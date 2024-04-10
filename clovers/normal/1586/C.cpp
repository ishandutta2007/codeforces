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
const int N=1000005;
string s[N];
vector<int> sum[N];
int n,m;
int Sum(int x,int y){
    return x>=0&&y>=0 ? sum[x][y] : 0;
}
int query(int sx,int sy,int ex,int ey){
    return Sum(ex,ey)-Sum(ex,sy-1)-Sum(sx-1,ey)+Sum(sx-1,sy-1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>s[i],sum[i].resize(m);
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            int tmp=(s[i-1][j]=='X'&&s[i][j-1]=='X');
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+tmp;
        }
    }
    int q; cin>>q;
    while(q--){
        int x1,x2; cin>>x1>>x2;
        if(x1==x2||n==1){cout<<"YES\n"; continue;}
        if(query(1,x1,n-1,x2-1)) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}