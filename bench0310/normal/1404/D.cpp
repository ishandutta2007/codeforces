#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if((n%2)==0)
    {
        cout << "First\n";
        for(int o=0;o<2;o++) for(int i=1;i<=n;i++) cout << i << " \n"[o==1&&i==n];
        cout.flush();
    }
    else
    {
        cout << "Second\n";
        cout.flush();
        vector<array<int,2>> a(n+1,{0,0});
        for(int i=1;i<=2*n;i++)
        {
            int p;
            cin >> p;
            if(a[p][0]==0) a[p][0]=i;
            else a[p][1]=i;
        }
        vector<int> v[2*n+1];
        for(int i=1;i<=n;i++)
        {
            v[i].push_back(n+i);
            v[n+i].push_back(i);
            v[a[i][0]].push_back(a[i][1]);
            v[a[i][1]].push_back(a[i][0]);
        }
        vector<int> res[2];
        vector<int> c(2*n+1,-1);
        for(int i=1;i<=2*n;i++)
        {
            if(c[i]!=-1) continue;
            queue<int> q;
            q.push(i);
            c[i]=0;
            res[0].push_back(i);
            while(!q.empty())
            {
                int e=q.front();
                q.pop();
                for(int to:v[e])
                {
                    if(c[to]==-1)
                    {
                        c[to]=1-c[e];
                        res[c[to]].push_back(to);
                        q.push(to);
                    }
                }
            }
        }
        ll sum=0;
        for(int x:res[0]) sum+=x;
        if((sum%(2*n))!=0) swap(res[0],res[1]);
        for(int x:res[0]) cout << x << " ";
        cout << "\n";
        cout.flush();
    }
    return 0;
}