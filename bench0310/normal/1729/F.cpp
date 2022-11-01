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
        string s;
        cin >> s;
        int n=s.size();
        s="$"+s;
        int w,m;
        cin >> w >> m;
        vector<int> sum(n+1,0);
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+(s[i]-'0');
        auto f=[&](int l,int r)->int{return (sum[r]-sum[l-1])%9;};
        vector<int> v[9];
        for(int i=1;i+w-1<=n;i++) v[f(i,i+w-1)].push_back(i);
        while(m--)
        {
            int l,r,k;
            cin >> l >> r >> k;
            int x=f(l,r);
            array<int,2> res={n+1,n+1};
            for(int a=0;a<9;a++)
            {
                for(int b=0;b<9;b++)
                {
                    if(((a*x+b)%9)==k)
                    {
                        if(a!=b&&!v[a].empty()&&!v[b].empty()) res=min(res,{v[a][0],v[b][0]});
                        if(a==b&&v[a].size()>=2) res=min(res,{v[a][0],v[a][1]});
                    }
                }
            }
            if(res[0]<=n) cout << res[0] << " " << res[1] << "\n";
            else cout << "-1 -1\n";
        }
    }
    return 0;
}