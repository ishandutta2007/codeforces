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
const ll INF=(ll)2e18;
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
const int N=200005;
const int B=600;
int n,m,x[N],y[N],sum[N],ins[N];
int t[805][805];

int main()
{
    n=read(); m=read();
    for(int i=1;i<=n;i++) x[i]=read(),y[i]=read();
    for(int ti=1;ti<=m;ti++){
        int opt=read(),id=read();
        if(opt==1){
            ins[id]=ti;
            int s=x[id]+y[id];
            if(s<=B){
                int now=(ti+x[id])%s,to=ti%s;
                while(now!=to) t[s][now]++,now=(now+1)%s;
            }
            else{
                for(int i=ti+s;i-y[id]<=m;i+=s){
                    sum[i-y[id]]++; 
                    if(i<=m) sum[i]--;
                }
            }
        }
        else{
            int s=x[id]+y[id];
            if(s<=B){
                int now=(ins[id]+x[id])%s,to=ins[id]%s;
                while(now!=to) t[s][now]--,now=(now+1)%s;           
            }
            else{
                for(int i=ins[id]+s;i-y[id]<=m;i+=s){
                    if(i-y[id]<=ti){
                        if(i>ti){
                            sum[ti]--;
                            if(i<=m) sum[i]++;
                        }
                        continue;
                    }
                    sum[i-y[id]]--; 
                    if(i<=m) sum[i]++;
                }
            }
        }
        
        sum[ti]+=sum[ti-1];
        int ret=sum[ti];
        for(int i=1;i<=B;i++) ret+=t[i][ti%i];
        printf("%d\n",ret); 
    }
    return 0;
}