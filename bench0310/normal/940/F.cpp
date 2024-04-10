#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    const int sz=2150;
    const int N=200000;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<array<int,3>> queries; //version,l,r
    vector<array<int,3>> ch(q+1,{0,0,0}); //idx,old,new
    for(int i=1;i<=q;i++)
    {
        int t;
        cin >> t;
        if(t==1)
        {
            int l,r;
            cin >> l >> r;
            queries.push_back({i,l,r});
        }
        else
        {
            int p,x;
            cin >> p >> x;
            ch[i]={p,a[p],x};
            a[p]=x;
        }
    }
    vector<array<int,4>> h; //val,a|ch,x,y
    for(int i=1;i<=n;i++) h.push_back({a[i],0,i,0});
    for(int i=1;i<=q;i++) for(int j=1;j<=2;j++) h.push_back({ch[i][j],1,i,j});
    sort(h.begin(),h.end());
    int idx=1;
    for(int i=0;i<(int)h.size();i++)
    {
        auto [val,tp,x,y]=h[i];
        if(i>0&&val!=h[i-1][0]) idx++;
        if(tp==0) a[x]=idx;
        else ch[x][y]=idx;
    }
    int version=q;
    int l=1,r=0;
    auto ord=[&](const array<int,3> &x,const array<int,3> &y)->bool{return (make_tuple(x[0]/sz,x[1]/sz,x[2])<make_tuple(y[0]/sz,y[1]/sz,y[2]));};
    sort(queries.begin(),queries.end(),ord);
    vector<int> c(N+1,0);
    c[0]=n+1;
    vector<int> freq(N+1,0);
    vector<int> res(q+1,-2);
    auto add=[&](int x)
    {
        int one=freq[x];
        freq[x]++;
        int two=freq[x];
        c[one]--;
        c[two]++;
    };
    auto rm=[&](int x)
    {
        int one=freq[x];
        freq[x]--;
        int two=freq[x];
        c[one]--;
        c[two]++;
    };
    auto mv_version=[&](int nversion)
    {
        while(version<nversion)
        {
            version++;
            auto [p,x,y]=ch[version];
            a[p]=y;
            if(l<=p&&p<=r)
            {
                add(y);
                rm(x);
            }
        }
        while(nversion<version)
        {
            auto [p,x,y]=ch[version];
            a[p]=x;
            if(l<=p&&p<=r)
            {
                add(x);
                rm(y);
            }
            version--;
        }
    };
    auto mv=[&](int nl,int nr)
    {
        while(nl<l) add(a[--l]);
        while(r<nr) add(a[++r]);
        while(l<nl) rm(a[l++]);
        while(nr<r) rm(a[r--]);
    };
    for(auto [nversion,nl,nr]:queries)
    {
        mv_version(nversion);
        mv(nl,nr);
        for(int i=1;i<=n+1;i++)
        {
            if(c[i]==0)
            {
                res[nversion]=i;
                break;
            }
        }
    }
    for(int i=1;i<=q;i++) if(res[i]!=-2) cout << res[i] << "\n";
    return 0;
}