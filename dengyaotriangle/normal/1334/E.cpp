#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=52;
constexpr int mdn=998244353;
struct mint{
    int v;
    inline operator int()const{return v;}
    inline mint(int v=0):v(v){}
    inline bool operator==(const mint&a)const{return v==a.v;}
    inline bool operator!=(const mint&a)const{return v!=a.v;}
    inline mint operator~ ()const{int r=1,b=v;for(int i=1;i<=(mdn-2);i<<=1){if((mdn-2)&i)r=static_cast<long long>(r)*static_cast<long long>(b)%mdn;b=static_cast<long long>(b)*static_cast<long long>(b)%mdn;}return mint(r);}
    inline mint operator- ()const{return mint(v==0?0:mdn-v);}
    inline mint operator+ (const mint&a)const{mint c(v+a.v);if(c.v>=mdn)c.v-=mdn;return c;}
    inline mint operator- (const mint&a)const{mint c(v-a.v);if(c.v<0)c.v+=mdn;return c;}
    inline mint operator* (const mint&a)const{long long c=static_cast<long long>(v)*static_cast<long long>(a.v);return mint(c%mdn);}
    inline mint operator/ (const mint&a)const{return (*this)*~a;}
    inline mint&operator++(){v++;if(v==mdn)v=0;return*this;}
    inline mint&operator--(){v--;if(v==-1)v=mdn-1;return*this;}
    inline mint&operator+=(const mint&a){v+=a.v;if(v>=mdn)v-=mdn;return*this;}
    inline mint&operator-=(const mint&a){v-=a.v;if(v<0)v+=mdn;return*this;}
    inline mint&operator*=(const mint&a){long long c=static_cast<long long>(v)*static_cast<long long>(a.v);v=c%mdn;return*this;}
    inline mint&operator/=(const mint&a){long long c=static_cast<long long>(v)*static_cast<long long>((~a).v);v=c%mdn;return*this;}
    friend istream&operator>>(istream&s,mint&a){s>>a.v;return s;}
    friend ostream&operator<<(ostream&s,const mint&a){s<<a.v;return s;}
};
long long d;
int m;
pair<long long,int> v[maxn];

inline vector<int> g(long long x){
    vector<int> ret;ret.resize(m+1);
    for(int i=1;i<=m;i++){
        while(x%v[i].first==0)x/=v[i].first,ret[i]++;
    }
    return ret;
}

const int maxf=100000;
int x[maxn];
mint fac[maxf],ifac[maxf];
inline mint calc(vector<int> s,vector<int> t){
    mint ans=1;
    int a=0;
    for(int i=1;i<=m;i++){
        int g=s[i]-t[i];
        ans*=ifac[g];
        a+=g;
    }
    ans*=fac[a];
    return ans;
}

int main(){
    fac[0]=1;for(int i=1;i<maxf;i++)fac[i]=fac[i-1]*(mint)i;
    ifac[maxf-1]=~fac[maxf-1];
    for(int i=maxf-1;i>0;i--)ifac[i-1]=ifac[i]*(mint)i;
    ios::sync_with_stdio(0);
    cin>>d;long long tmp=d;
    for(long long r=2;r*r<=d;r++){
        if(tmp%r==0){
            int cnt=0;while(tmp%r==0)tmp/=r,cnt++;
            v[++m]=make_pair(r,cnt);
        }
    }
    if(tmp!=1)v[++m]=make_pair(tmp,1);
    int q;cin>>q;
    while(q--){
        long long ux,vx;cin>>ux>>vx;
        vector<int> u=g(ux),v=g(vx),w;w.resize(m+1);
        for(int i=1;i<=m;i++)w[i]=min(u[i],v[i]);
        cout<<calc(u,w)*calc(v,w)<<'\n';
    }
    return 0;
}