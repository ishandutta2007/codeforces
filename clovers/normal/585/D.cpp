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
const int N=50;
int n,a[N][4],ans=-inf;
map<pii,int> mp;
map<pii,vector<string> > mp2;
vector<string> v,ans1,ans2;
void dfs1(int x,int A,int B,int C){
    if(x==0){
        if(!mp.count(mk(A-B,A-C))){
            mp2[mk(A-B,A-C)]=v;
            mp[mk(A-B,A-C)]=A;
        }
        else if(mp[mk(A-B,A-C)]<A){
            mp2[mk(A-B,A-C)]=v;
            mp[mk(A-B,A-C)]=A;
        }
        return;
    }
    v.push_back("LM");
    dfs1(x-1,A+a[x][1],B+a[x][2],C); v.pop_back();
    v.push_back("LW");
    dfs1(x-1,A+a[x][1],B,C+a[x][3]); v.pop_back();
    v.push_back("MW");
    dfs1(x-1,A,B+a[x][2],C+a[x][3]); v.pop_back();
}
void dfs2(int x,int A,int B,int C){
    if(x==n+1){
        if(mp.count(mk(B-A,C-A))){
            if(ans<A+mp[mk(B-A,C-A)]){
                ans=A+mp[mk(B-A,C-A)];
                ans1=mp2[mk(B-A,C-A)];
                ans2=v;
            }
        }
        return;
    }
    v.push_back("LM");
    dfs2(x+1,A+a[x][1],B+a[x][2],C); v.pop_back();
    v.push_back("LW");
    dfs2(x+1,A+a[x][1],B,C+a[x][3]); v.pop_back();
    v.push_back("MW");
    dfs2(x+1,A,B+a[x][2],C+a[x][3]); v.pop_back();
}

int main()
{
    n=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=3;j++) a[i][j]=read();
    mp[mk(0,0)]=0;
    v.clear();
    dfs1((n-2)/2,0,0,0);
    v.clear();
    dfs2((n-2)/2+1,0,0,0);
    if(ans==-inf) puts("Impossible");
    else{
        for(int i=sz(ans1)-1;i>=0;i--) 
            cout<<ans1[i]<<"\n";
        for(int i=0;i<sz(ans2);i++)
            cout<<ans2[i]<<"\n";
    }
    return 0;
}