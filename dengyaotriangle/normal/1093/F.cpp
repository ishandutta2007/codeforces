#include<bits/stdc++.h>
#pragma GCC optimize("-Ofast")
using namespace std;
//dengyaotriangle!

const int maxn=100005*2;
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
    inline mint operator--(int){mint ret=*this;--*this;return ret;}
    inline mint&operator+=(const mint&a){v+=a.v;if(v>=mdn)v-=mdn;return*this;}
    inline mint&operator-=(const mint&a){v-=a.v;if(v<0)v+=mdn;return*this;}
    inline mint&operator*=(const mint&a){v=v*(long long)a.v%mdn;return*this;}
    inline mint&operator/=(const mint&a){v=v*(long long)(~a).v%mdn;return*this;}
    friend istream&operator>>(istream&s,mint&a){s>>a.v;return s;}
    friend ostream&operator<<(ostream&s,const mint&a){s<<a.v;return s;}
};
int n,m,l;
int a[maxn];
mint dp[maxn];
int rep[maxn];
int cnt[maxn];
int l1[maxn],l2[maxn],cl[maxn];
mint sfx[maxn];

namespace nqio{const unsigned R=4e5,W=4e5;char*a,*b,i[R],o[W],*c=o,*d=o+W,h[40],*p=h,y;bool s;struct q{void r(char&x){x=a==b&&(b=(a=i)+fread(i,1,R,stdin),a==b)?-1:*a++;}void f(){fwrite(o,1,c-o,stdout);c=o;}~q(){f();}void w(char x){*c=x;if(++c==d)f();}q&operator>>(char&x){do r(x);while(x<=32);return*this;}q&operator>>(char*x){do r(*x);while(*x<=32);while(*x>32)r(*++x);*x=0;return*this;}template<typename t>q&operator>>(t&x){for(r(y),s=0;!isdigit(y);r(y))s|=y==45;if(s)for(x=0;isdigit(y);r(y))x=x*10-(y^48);else for(x=0;isdigit(y);r(y))x=x*10+(y^48);return*this;}q&operator<<(char x){w(x);return*this;}q&operator<<(char*x){while(*x)w(*x++);return*this;}q&operator<<(const char*x){while(*x)w(*x++);return*this;}template<typename t>q&operator<<(t x){if(!x)w(48);else if(x<0)for(w(45);x;x/=10)*p++=48|-(x%10);else for(;x;x/=10)*p++=48|x%10;while(p!=h)w(*--p);return*this;}}qio;}using nqio::qio;

int main(){
    qio>>n>>m>>l;
    for(int i=1;i<=n;i++)qio>>a[i],a[i]+=a[i]==-1;
    int div=0,lst;
    for(int i=n;i>=1;i--){
        if(a[i])div+=1==++cnt[a[i]],lst=a[i];
        if(a[i+l]&&i+l<=n)div-=0==--cnt[a[i+l]];
        if(div==0)rep[i]=0;
        else if(div==1)rep[i]=lst;
        else rep[i]=-1;
    }
    for(int i=1;i<=l;i++){
        int cc=0;int lp1=i,lp2=i,fp=i;
        l1[i]=l2[i]=i;
        for(int j=i;j<=n;j+=l){
            if(rep[j]==-1){
                lp1=lp2=j+l;cc=0;
            }else if(rep[j]!=0){
                if(cc==0){cc=rep[j];lp2=j+l;}
                else{
                    if(cc!=rep[j]){
                        lp1=fp;lp2=j+l;cc=rep[j];
                    }else lp2=j+l;
                }
                fp=j+l;
            }
            l1[j+l]=lp1;l2[j+l]=lp2;cl[j+l]=cc;
        }
    }
    //for(int i=1;i<=n;i++)cerr<<l1[i]<<' '<<l2[i]<<' '<<cl[i]<<endl;
    dp[n+1]=1;
    for(int i=n;i>=1;i--){
        if(a[i]){
            mint w=dp[i+1];
            if(rep[i]!=-1)w-=dp[i+l];
            if(cl[i]==a[i]){
                sfx[i+l]+=w;
                sfx[l1[i]]-=w;
            }else{
                sfx[i+l]+=w;
                sfx[l2[i]]-=w;
            }
        }else{
            if(rep[i]==0){
                mint w=dp[i+1]-dp[i+l];
                sfx[i+l]+=w*mint(m);
                sfx[l2[i]]-=w*mint(m-1);
                sfx[l1[i]]-=w;
            }else if(rep[i]!=-1){
                mint w1=dp[i+1],w2=dp[i+1]-dp[i+l];
                if(cl[i]==rep[i]){
                    sfx[i+l]+=w1*mint(m-1)+w2;
                    sfx[l2[i]]-=w1*mint(m-1);
                    sfx[l1[i]]-=w2;
                }else{
                    sfx[i+l]+=w1*mint(m-1)+w2;
                    sfx[l2[i]]-=w1*mint(m-2)+w2;
                    sfx[l1[i]]-=w1;
                }
            }else{
                mint w=dp[i+1];
                sfx[i+l]+=w*mint(m);
                sfx[l2[i]]-=w*mint(m-1);
                sfx[l1[i]]-=w;
            }
        }
        dp[i]=sfx[i+l];
        sfx[i]+=sfx[i+l];
        //cerr<<dp[i]<<endl;
        //cerr<<i<<' '<<cl[i]<<' '<<l1[i]<<' '<<l2[i]<<endl;
    }
    qio<<int(dp[1]);
    return 0;
}