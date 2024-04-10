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
    const int N=100000;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<array<int,4>> queries; //version,l,r,k
    vector<array<int,3>> ch(q+1,{0,0,0}); //idx,old,new
    for(int i=1;i<=q;i++)
    {
        int t;
        cin >> t;
        if(t==1)
        {
            int l,r,k;
            cin >> l >> r >> k;
            queries.push_back({i,l,r,k});
        }
        else
        {
            int p,x;
            cin >> p >> x;
            ch[i]={p,a[p],x};
            a[p]=x;
        }
    }
    int version=q;
    int l=1,r=0;
    auto ord=[&](const array<int,4> &x,const array<int,4> &y)->bool{return (make_tuple(x[0]/sz,x[1]/sz,x[2])<make_tuple(y[0]/sz,y[1]/sz,y[2]));};
    sort(queries.begin(),queries.end(),ord);
    vector<int> c(N+1,0);
    c[0]=n+1;
    vector<int> prv(N+2,0);
    vector<int> nxt(N+2,N+1);
    vector<int> freq(N+1,0);
    vector<int> res(q+1,-2);
    auto add=[&](int x)
    {
        int one=freq[x];
        freq[x]++;
        int two=freq[x];
        c[one]--;
        c[two]++;
        if(c[two]==1)
        {
            prv[nxt[one]]=two;
            nxt[two]=nxt[one];
            nxt[one]=two;
            prv[two]=one;
        }
        if(c[one]==0)
        {
            nxt[prv[one]]=nxt[one];
            prv[nxt[one]]=prv[one];
        }
    };
    auto rm=[&](int x)
    {
        int one=freq[x];
        freq[x]--;
        int two=freq[x];
        c[one]--;
        c[two]++;
        if(c[two]==1)
        {
            nxt[prv[one]]=two;
            prv[two]=prv[one];
            nxt[two]=one;
            prv[one]=two;
        }
        if(c[one]==0)
        {
            prv[nxt[one]]=prv[one];
            nxt[prv[one]]=nxt[one];
        }
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
    for(auto [nversion,nl,nr,k]:queries)
    {
        mv_version(nversion);
        mv(nl,nr);
        vector<array<int,2>> v; //c,val
        int now=0;
        while(now<N+1)
        {
            now=nxt[now];
            if(now<N+1) v.push_back({now,c[now]});
        }
        int m=N+1;
        int two=-1;
        int len=v.size();
        int sum=0;
        for(int one=0;one<len;one++)
        {
            while(two+1<len&&sum<k) sum+=v[++two][1];
            if(sum<k) break;
            m=min(m,v[two][0]-v[one][0]);
            sum-=v[one][1];
        }
        if(m==N+1) m=-1;
        res[nversion]=m;
    }
    for(int i=1;i<=q;i++) if(res[i]!=-2) cout << res[i] << "\n";
    return 0;
}