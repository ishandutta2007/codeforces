#include<bits/stdc++.h>
#define N 300000
#define mid ((l+r)>>1)
using namespace std;
namespace IO
{
    const int SIZE=1<<21;
    char ibuf[SIZE],*iS,*iT,obuf[SIZE],*oS=obuf,*oT=oS+SIZE-1,c,qu[55];int f,qr;
    #define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,SIZE,stdin),(iS==iT?EOF:*iS++)):*iS++)
    inline void flush()
    {
        fwrite(obuf,1,oS-obuf,stdout);
        oS=obuf;
    }
    inline void putc(char x)
    {
        *oS++=x;
        if(oS==oT) flush();
    }
    template<class I>
    inline void read(I &x)
    {
        for(f=1,c=gc();c<'0' || c>'9';c=gc()) if(c=='-') f=-1;
        for(x=0;c<='9' && c>='0';c=gc()){x=(x<<1)+(x<<3)+(c&15);}x*=f;
    }
    template<class I>
    inline void print(I x)
    {
        if(!x) putc('0');
        if(x<0) putc('-'),x=-x;
        while(x) qu[++qr]=x%10+'0',x/=10;
        while(qr) putc(qu[qr--]);
    }
    struct Flusher_{~Flusher_(){flush();}}io_flusher_;
}
using IO::read;
using IO::putc;
using IO::print;
const int inf=1e9+7;
int n,k,a[N+5],b[N+5];
vector<pair<int,int> > v[N+5];
inline void init()
{
    set<pair<int,int> > s;
    s.insert({0,0}),s.insert({inf,0});
    auto split=[&](int p)
    {
        set<pair<int,int> >::iterator it=s.lower_bound({p,0});
        return it->first==p?it:s.insert({p,prev(it)->second}).first;
    };
    for(int i=1;i<=n;++i)
    {
        set<pair<int,int> >::iterator ed=split(b[i]);
        for(set<pair<int,int> >::iterator it=split(a[i]);it!=ed;s.erase(it++))
            v[i].push_back({it->second+1,next(it)->first-it->first});
        s.insert({a[i],i});
    }
}
inline pair<long long,long long> solve(int val)
{
    static int s[N+5];
    pair<long long,long long> ret;
    memset(s,0,sizeof s);
    long long sum=0;
    for(int i=1,j=0,now=0;i<=n;++i)
    {
        for(pair<int,int> x:v[i])
        {
            s[x.first]+=x.second,s[i+1]-=x.second;
            if(x.first<=j) now+=x.second,sum+=1ll*(j-x.first+1)*x.second;
        }
        while(now+s[j+1]>val) sum+=now+=s[++j];
        ret.first+=j,ret.second+=sum;
    }
    return ret;
}
int main()
{
    read(n),read(k);
    for(int i=1;i<=n;++i) read(a[i]),read(b[i]);
    int l=1,r=inf;init();
    while(l<r) solve(mid).first<k?r=mid:l=mid+1;
    pair<long long,long long> ans=solve(l);
    print(ans.second+1ll*(k-ans.first)*l);
    cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}