#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector a(n+2,vector(m+2,int(1<<30)));
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> a[i][j];
    vector<array<int,2>> z={{1,0},{-1,0},{0,-1},{0,1}};
    auto in=[&](int i,int j)->bool{return (1<=i&&i<=n&&1<=j&&j<=m);};
    auto bad=[&](int i,int j)->bool
    {
        if((!in(i,j))||a[i][j]==1) return 0;
        for(auto [di,dj]:z) if(a[i+di][j+dj]<a[i][j]) return 0;
        return 1;
    };
    vector<array<int,2>> v;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(bad(i,j)) v.push_back({i,j});
    int cnt=v.size();
    if(cnt==0) cout << "0\n";
    else if(cnt<=10)
    {
        for(int i=0;i<cnt;i++) for(auto [di,dj]:z) if(in(v[i][0]+di,v[i][1]+dj)) v.push_back({v[i][0]+di,v[i][1]+dj});
        ranges::sort(v);
        v.erase(unique(v.begin(),v.end()),v.end());
        int sz=v.size();
        int idx=0;
        vector o(n+1,vector(m+1,int(1)));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(idx<sz&&array<int,2>{i,j}==v[idx])
                {
                    o[i][j]=0;
                    idx++;
                }
            }
        }
        int res=0;
        auto try_swap=[&](array<int,2> one,array<int,2> two)
        {
            auto [ra,ca]=one;
            auto [rb,cb]=two;
            swap(a[ra][ca],a[rb][cb]);
            bool ok=1;
            for(auto [r,c]:v) ok&=(!bad(r,c));
            ok&=((!bad(ra,ca))&&(!bad(rb,cb)));
            for(auto [r,c]:{one,two})
            {
                for(auto [di,dj]:z) ok&=(!bad(r+di,c+dj));
            }
            swap(a[ra][ca],a[rb][cb]);
            res+=ok;
        };
        for(int x=0;x<sz;x++)
        {
            for(int y=x+1;y<sz;y++)
            {
                try_swap(v[x],v[y]);
            }
            int now=0;
            now+=bad(v[x][0],v[x][1]);
            for(auto [di,dj]:z) now+=bad(v[x][0]+di,v[x][1]+dj);
            if(now==cnt)
            {
                for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(o[i][j]==1) try_swap(v[x],{i,j});
            }
        }
        if(res>=1) cout << "1 " << res << "\n";
        else cout << "2\n";
    }
    else cout << "2\n";
    return 0;
}