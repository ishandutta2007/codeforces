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
const int N=100005;
char s[N]; ll a[N],b[N],tt[N];
int n;
ll t[N][2],c=0;
set<pii> st;

void insert(int i){
    if(st.count(mk(i,0))) st.erase(mk(i,0));
    if(st.count(mk(i,1))) st.erase(mk(i,1));
    if(t[i][0]&&a[i]&&a[i+1]) st.insert(mk(i,0));
    if(t[i][1]&&a[i]<9&&a[i+1]<9) st.insert(mk(i,1)); 
}

int main()
{
    n=read();
    scanf("%s",s+1); for(int i=1;i<=n;i++) a[i]=s[i]-'0',tt[i]=a[i];
    scanf("%s",s+1); for(int i=1;i<=n;i++) b[i]=s[i]-'0';
    for(int i=1;i<n;i++){
        if(a[i]<b[i]) t[i][1]=b[i]-a[i],a[i+1]+=t[i][1];
        else t[i][0]=a[i]-b[i],a[i+1]-=t[i][0];
        c+=max(t[i][0],t[i][1]);
    }
    if(a[n]!=b[n]){puts("-1"); return 0;}
    printf("%lld\n",c);
    memcpy(a,tt,sizeof(a));
    for(int i=1;i<n;i++) insert(i);
    for(int rnd=1;rnd<=min(100000ll,c);rnd++){
        pii u=*st.begin();
        t[u.first][u.second]--;
        if(u.second) a[u.first]++,a[u.first+1]++,printf("%d 1\n",u.first);
        else a[u.first]--,a[u.first+1]--,printf("%d -1\n",u.first);
        if(u.first>1) insert(u.first-1); 
        insert(u.first); insert(u.first+1);
    }
    return 0;
}