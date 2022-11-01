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
        int n,m;
        cin >> n >> m;
        vector<int> x(n+1,0);
        string tp(n+1,'$');
        for(int i=1;i<=n;i++) cin >> x[i];
        for(int i=1;i<=n;i++) cin >> tp[i];
        vector<array<int,3>> tmp[2];
        for(int i=1;i<=n;i++) tmp[x[i]&1].push_back({x[i],(tp[i]=='R'),i});
        vector<int> res(n+1,-1);
        for(int o=0;o<2;o++)
        {
            vector<array<int,3>> v=tmp[o];
            sort(v.begin(),v.end());
            stack<array<int,2>> s;
            for(auto [a,dir,id]:v)
            {
                if(dir==0)
                {
                    if(s.empty()) s.push({-a,id});
                    else
                    {
                        res[id]=res[s.top()[1]]=(a-s.top()[0])/2;
                        s.pop();
                    }
                }
                else s.push({a,id});
            }
            while(s.size()>=2)
            {
                auto [b,two]=s.top();
                s.pop();
                auto [a,one]=s.top();
                s.pop();
                res[one]=res[two]=(b+2*(m-b)-a)/2;
            }
        }
        for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
    }
    return 0;
}