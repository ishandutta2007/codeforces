/*
the vast starry sky,
bright for those who chase the light.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mk make_pair
const int inf=(int)1e9;
const ll INF=(ll)5e18;
const int MOD=998244353;
int _abs(int x){return x<0 ? -x : x;}
int add(int x,int y){x+=y; return x>=MOD ? x-MOD : x;}
int sub(int x,int y){x-=y; return x<0 ? x+MOD : x;}
#define mul(x,y) (ll)(x)*(y)%MOD
void Add(int &x,int y){x+=y; if(x>=MOD) x-=MOD;}
void Sub(int &x,int y){x-=y; if(x<0) x+=MOD;}
void Mul(int &x,int y){x=mul(x,y);}
int qpow(int x,int y){int ret=1; while(y){if(y&1) ret=mul(ret,x); x=mul(x,x); y>>=1;} return ret;}
void checkmin(int &x,int y){if(x>y) x=y;}
void checkmax(int &x,int y){if(x<y) x=y;}
void checkmin(ll &x,ll y){if(x>y) x=y;}
void checkmax(ll &x,ll y){if(x<y) x=y;}
#define out(x) cerr<<#x<<'='<<x<<' '
#define outln(x) cerr<<#x<<'='<<x<<endl
#define sz(x) (int)(x).size()
inline int read(){
    int x=0,f=1; char c=getchar();
    while(c>'9'||c<'0'){if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x*f;
}
const int N=105;
int n,A,B,a[N],ret[N],val[N];
int b[N];
int t[100];
int calc1(){
    int ret=0;
    for(int i=1;i<=n;i++) ret+=val[t[i]];
    return ret;
}
int calc2(){
    int ret=0;
    for(int i=1;i<=n-2;i++) ret+=t[i]*t[i+1]*t[i+2];
    return ret;
}
pii ask(int x){
    printf("+ %d\n",x); t[x]++;
    fflush(stdout);
    //out(calc1()); outln(calc2());
    int xx=read(),yy=read();
    return mk(xx,yy);
}

int main()
{
    t[1]=1; t[2]=0; t[3]=1; t[4]=2;
    n=read(); 
    for(int i=3;i<=n+n;i++) val[i]=i*(i-1)*(i-2)/6;
    //out(calc1()); outln(calc2());
    A=read(); B=read();
    for(int i=1;i<n;i++){
        pii now=ask(i),kk;
        if(i==1){
            if(now.first==A) ret[1]=-1;
            else{
                int pos; 
                for(int j=2;j<=n;j++) 
                    if(val[j+1]-val[j]==now.first-A) pos=j;
                ret[i]=pos; a[i]=ret[i]+1;
            }
        }
        else{
            if(i==3){
                kk=ask(1);
                if(ret[1]==-1){
                    if(kk.first==now.first) ret[1]=0,a[1]=2;
                    else ret[1]=1,a[1]=3;
                }
                else a[1]++;
            }
            int tmp=b[i-1]-(i==2 ? 0 : a[i-3]*a[i-2]);
            if(!tmp){
                if(i==2) ret[i]=-1;
                else ret[i]=0,a[i]=1;
                if(i==3&&ret[2]==-1) a[2]=kk.second-now.second,ret[2]=a[2]-1;
            }
            else{
                if(i==3&&ret[2]==-1) ret[2]=0,a[2]=1;
                int pos;
                for(int j=1;j<=n;j++)
                    if(val[j+1]-val[j]==now.first-A) pos=j;
                ret[i]=pos; a[i]=ret[i]+1;
            }
        }
        if(i!=3){
            b[i]=now.second-B;
            A=now.first; B=now.second;
        }
        else{//13
            b[i]=kk.second-a[2]*ret[3]-B;
            A=kk.first; B=kk.second;
        }
    }
    outln(b[n-1]);
    int delta=b[n-1]-a[n-2]*a[n-3];
    ret[n]=delta/a[n-2];
    printf("! ");
    for(int i=1;i<=n;i++) printf("%d ",ret[i]);
    fflush(stdout);
    return 0;
}