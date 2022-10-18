#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=34;
const int ex=1000000;
constexpr int mdn=998244353;
struct mint{
    int v;
    inline operator int()const{return v;}
    inline mint(int v=0):v(v){}
    inline bool operator==(const mint&a)const{return v==a.v;}
    inline bool operator!=(const mint&a)const{return v!=a.v;}
    inline mint operator~ ()const{int r=1,b=v;for(int i=1;i<=(mdn-2);i<<=1){if((mdn-2)&i)r=r*(long long)b%mdn;b=b*(long long)b%mdn;}return mint(r);}
    inline mint operator- ()const{return mint(v?mdn-v:0);}
    inline mint operator+ (const mint&a)const{mint c(v+a.v);if(c.v>=mdn)c.v-=mdn;return c;}
    inline mint operator- (const mint&a)const{mint c(v-a.v);if(c.v<0)c.v+=mdn;return c;}
    inline mint operator* (const mint&a)const{return mint(v*(long long)a.v%mdn);}
    inline mint operator/ (const mint&a)const{return (*this)*~a;}
    inline mint&operator++(){v++;if(v==mdn)v=0;return*this;}
    inline mint&operator--(){v--;if(v==-1)v=mdn-1;return*this;}
    inline mint operator++(int){mint ret=*this;++*this;return ret;}
    inline mint operator--(int){mint ret=*this;++*this;return ret;}
    inline mint&operator+=(const mint&a){v+=a.v;if(v>=mdn)v-=mdn;return*this;}
    inline mint&operator-=(const mint&a){v-=a.v;if(v<0)v+=mdn;return*this;}
    inline mint&operator*=(const mint&a){v=v*(long long)a.v%mdn;return*this;}
    inline mint&operator/=(const mint&a){v=v*(long long)(~a).v%mdn;return*this;}
    friend istream&operator>>(istream&s,mint&a){s>>a.v;return s;}
    friend ostream&operator<<(ostream&s,const mint&a){s<<a.v;return s;}
};

mint inv[maxn];

vector<mint> integ(vector<mint> x){
    x.push_back(0);
    for(int i=x.size()-1;i>0;i--)x[i]=x[i-1];
    x[0]=0;
    for(int i=1;i<x.size();i++)x[i]=x[i]*inv[i]%mdn;
    return x;
}

mint calc(vector<mint> x,mint val){
    mint ans;
    for(int i=x.size()-1;i>=0;i--)ans=ans*val+x[i];
    return ans;
}

vector<mint> add(vector<mint> a,vector<mint>b){
    if(a.size()<b.size())swap(a,b);
    for(int i=0;i<b.size();i++)a[i]+=b[i];
    return a;
}

vector<mint> sub(vector<mint> a,vector<mint> b){
    a.resize(max(a.size(),b.size()));
    for(int i=0;i<b.size();i++)a[i]-=b[i];
    return a;
}

mint binom[maxn][maxn];

vector<mint> plg(vector<mint> a,mint dlt){
    vector<mint> ret;ret.resize(a.size());
    for(int i=0;i<a.size();i++){
        mint pw=1;
        for(int j=i;j>=0;j--){
            ret[j]+=a[i]*binom[i][j]*pw;
            pw*=dlt;
        }
    }
    return ret;
}
int n;
int p[maxn];
vector<mint> dp[maxn][maxn*maxn];
mint pfx[maxn*maxn];
vector<int> pt;
vector<int> prv;

int main(){
    for(int i=0;i<maxn;i++){
        binom[i][0]=1;
        for(int j=1;j<=i;j++)binom[i][j]=binom[i-1][j]+binom[i-1][j-1];
    }
    for(int i=1;i<maxn;i++)inv[i]=~(mint)i;
    mint invex=~(mint)ex;
    cin>>n;
    pt.push_back(0);
    for(int i=0;i<=n;i++)pt.push_back(i*ex);
    for(int i=1;i<=n;i++){
        double t;cin>>t;
        p[i]=(int)(t*ex+0.5);
        for(int j=0;j<=n;j++){
            pt.push_back(p[i]%ex+j*ex);
        }
    }
    sort(pt.begin(),pt.end());
    pt.resize(unique(pt.begin(),pt.end())-pt.begin());
    prv.resize(pt.size());
    for(int i=0;i<pt.size();i++){
        prv[i]=-1;
        for(int j=0;j<pt.size();j++){
            if(pt[j]==pt[i]-ex)prv[i]=j;
        }
    }
    //for(int i=0;i<pt.size();i++)cerr<<pt[i]<<','<<prv[i]<<endl;
    for(int i=1;i<pt.size();i++){
        dp[1][i]={invex};
        if(pt[i]==ex||pt[i]==p[1])break;
    }
    for(int i=2;i<=n;i++){/*
        mint ans=0;
        for(int j=1;j<pt.size();j++){
            vector<mint> ig=integ(dp[i-1][j]);
            ans+=calc(ig,pt[j])-calc(ig,pt[j-1]);
        }
        cout<<ans<<endl;*/
        for(int j=1;j<pt.size();j++){
            int l=pt[j-1],r=pt[j];
            dp[i-1][j]=integ(dp[i-1][j]);
            pfx[j]=pfx[j-1]+calc(dp[i-1][j],r)-calc(dp[i-1][j],l);
            dp[i][j]=dp[i-1][j];
            dp[i][j][0]-=calc(dp[i-1][j],l);
            dp[i][j][0]+=pfx[j-1];
            if(prv[j]>=0)dp[i][j][0]-=pfx[prv[j]];
            if(prv[j-1]>=0){
                int pr=prv[j];
                dp[i][j]=sub(dp[i][j],plg(dp[i-1][pr],mdn-ex));
                dp[i][j][0]+=calc(dp[i-1][pr],pt[pr]);
            }
            for(int k=0;k<dp[i][j].size();k++)dp[i][j][k]*=invex;
            if(pt[j]==p[i])break;
        }
    }
    mint ans=0;
    for(int j=1;j<pt.size();j++){
        vector<mint> ig=integ(dp[n][j]);
        ans+=calc(ig,pt[j])-calc(ig,pt[j-1]);
    }
    cout<<ans<<endl;
    return 0;
}