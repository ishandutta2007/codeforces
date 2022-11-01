#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        vector<array<int,2>> v(k);
        for(int i=0;i<k;i++) cin >> v[i][0];
        for(int i=0;i<k;i++) cin >> v[i][1];
        sort(v.begin(),v.end(),[](const array<int,2> &a,const array<int,2> &b){return (a[1]<b[1]);});
        int idx=0;
        vector<int> res(n+1,-1);
        queue<int> q;
        q.push(v[0][0]);
        res[v[0][0]]=v[0][1];
        idx++;
        while(idx<k||!q.empty())
        {
            if(q.empty())
            {
                while(idx<k&&res[v[idx][0]]!=-1) idx++;
                if(idx==k) break;
                q.push(v[idx][0]);
                res[v[idx][0]]=v[idx][1];
                idx++;
            }
            while(idx<k&&v[idx][1]==res[q.front()])
            {
                if(res[v[idx][0]]==-1)
                {
                    q.push(v[idx][0]);
                    res[v[idx][0]]=v[idx][1];
                }
                idx++;
            }
            int a=q.front();
            q.pop();
            for(int b:{a-1,a+1})
            {
                if(!(1<=b&&b<=n)) continue;
                if(res[b]==-1)
                {
                    res[b]=res[a]+1;
                    q.push(b);
                }
            }
        }
        for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
    }
    return 0;
}