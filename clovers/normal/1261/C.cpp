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
vector<int> sum[N],sum2[N];
string ans[N],ANS[N];
int n,m;

int S(int ln,int rn,int lm,int rm,int flag){
    if(flag==1) return sum[rn][rm]-(ln==0 ? 0 :sum[ln-1][rm])
                    -(lm==0 ? 0 : sum[rn][lm-1]) 
                    +(lm==0||ln==0 ? 0 : sum[ln-1][lm-1]);
    else return sum2[rn][rm]-(ln==0 ? 0 :sum2[ln-1][rm])
                    -(lm==0 ? 0 : sum2[rn][lm-1]) 
                    +(lm==0||ln==0 ? 0 : sum2[ln-1][lm-1]);
}

void init(){
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>s[i];
    for(int i=0;i<n;i++) sum[i].resize(m),ans[i].resize(m),sum2[i].resize(m);
    sum[0][0]=(s[0][0]=='X');
    for(int i=1;i<m;i++) sum[0][i]=sum[0][i-1]+(s[0][i]=='X');
    for(int j=1;j<n;j++) sum[j][0]=sum[j-1][0]+(s[j][0]=='X');
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(s[i][j]=='X');
        }
    }
}

bool check(int mid){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) ans[i][j]='.',sum2[i][j]=0;
    }
    for(int i=mid;i<=n-1-mid;i++){
        for(int j=mid;j<=m-1-mid;j++){
            int sx=i-mid,sy=j-mid,ex=i+mid,ey=j+mid;
            int are=(ex-sx+1)*(ey-sy+1);
            if(S(sx,ex,sy,ey,1)==are) ans[i][j]='X';
        }
    }
    sum2[0][0]=(ans[0][0]=='X');
    for(int i=1;i<m;i++) sum2[0][i]=sum2[0][i-1]+(ans[0][i]=='X');
    for(int j=1;j<n;j++) sum2[j][0]=sum2[j-1][0]+(ans[j][0]=='X');
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            sum2[i][j]=sum2[i-1][j]+sum2[i][j-1]-sum2[i-1][j-1]+(ans[i][j]=='X');
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='.') continue;
            int sx=i-mid,sy=j-mid,ex=i+mid,ey=j+mid;
            checkmax(sx,0); checkmax(sy,0);
            checkmin(ex,n-1); checkmin(ey,m-1);
            if(!S(sx,ex,sy,ey,2)) return 0;
        }
    }
    for(int i=0;i<n;i++) ANS[i]=ans[i];
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init();
    //outln(S(0,n-1,0,m-1,1));
    for(int i=0;i<n;i++) ANS[i]=s[i];
    int l=1,r=min(n,m)/2,mid,best=0;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)) l=mid+1,best=mid;
        else r=mid-1;
    }
    cout<<best<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout<<ANS[i][j];
        cout<<"\n";
    }
    return 0;
}