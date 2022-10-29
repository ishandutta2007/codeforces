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
const int N=200015;
int n,a[N],sum1[N],sum2[N],pos1[N],pos2[N];
vector<pii> ans;

int main()
{
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<N;i++) pos1[i]=n+10,pos2[i]=n+10;
    for(int i=1;i<=n;i++){
        sum1[i]=sum1[i-1]; sum2[i]=sum2[i-1];
        if(a[i]==1) sum1[i]++,pos1[sum1[i]]=i;
        else sum2[i]++,pos2[sum2[i]]=i;
    }
    for(int t=1;t<=n;t++){
        int w1=0,w2=0,lst;
        int pos=0;
        while(pos<n){
            int p1=pos1[sum1[pos]+t];
            int p2=pos2[sum2[pos]+t];
            pos=min(p1,p2);
            if(p1<p2) w1++,lst=1;
            else w2++,lst=2;
        }
        if(w1==w2||pos!=n) continue;
        if(w1>w2&&lst==1) ans.push_back(mk(w1,t));
        if(w1<w2&&lst==2) ans.push_back(mk(w2,t));
    }
    sort(ans.begin(),ans.end());
    cout<<sz(ans)<<endl;
    for(auto &u : ans) printf("%d %d\n",u.first,u.second);
    return 0;
}