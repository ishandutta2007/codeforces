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
        int n;
        string s;
        cin >> n >> s;
        s="$"+s;
        set<int> a,b;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='0') a.insert(i);
            else b.insert(i);
        }
        int cnt=0;
        vector<int> res(n+1,0);
        while((!a.empty())&&(!b.empty()))
        {
            cnt++;
            bool x=0;
            int now=0;
            if((*a.begin())<(*b.begin()))
            {
                now=(*a.begin());
                x=0;
            }
            else
            {
                now=(*b.begin());
                x=1;
            }
            while(1)
            {
                if(x==0)
                {
                    auto it=a.lower_bound(now);
                    if(it==a.end()) break;
                    now=*it;
                    res[now]=cnt;
                    a.erase(it);
                }
                else
                {
                    auto it=b.lower_bound(now);
                    if(it==b.end()) break;
                    now=*it;
                    res[now]=cnt;
                    b.erase(it);
                }
                x=1-x;
            }
        }
        while(!a.empty())
        {
            res[*a.begin()]=++cnt;
            a.erase(a.begin());
        }
        while(!b.empty())
        {
            res[*b.begin()]=++cnt;
            b.erase(b.begin());
        }
        cout << cnt << "\n";
        for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
    }
    return 0;
}