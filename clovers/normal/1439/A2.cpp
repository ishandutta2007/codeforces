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
#define y1 ruewioaurioa
#define y2 fjdskfjksadlf
#define y3 fjiaowjfoiadfjoaosd
#define y4 fsdjhkafs
const int N=105;
int T,n,m; char s[N][N]; int a[N][N];
struct node{
    int x1,y1,x2,y2,x3,y3;
};
vector<node> ans;
void insert(int x1,int y1,int x2,int y2,int x3,int y3){
    a[x1][y1]^=1; a[x2][y2]^=1; a[x3][y3]^=1;
    ans.push_back({x1,y1,x2,y2,x3,y3});
}
void kkk1(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
    insert(x1,y1,x2,y2,x3,y3);
    insert(x2,y2,x1,y1,x4,y4);
    insert(x1,y1,x3,y3,x4,y4);
}
void kkk2(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
    insert(x1,y1,x3,y3,x4,y4);
    insert(x2,y2,x3,y3,x4,y4);
}
void kkk4(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
    insert(x2,y2,x3,y3,x4,y4);
    kkk1(x1,y1,x2,y2,x3,y3,x4,y4);
}


int main()
{
    T=read();
    while(T--){
        n=read(); m=read(); ans.clear();
        for(int i=1;i<=n;i++){
            scanf("%s",s[i]+1);
            for(int j=1;j<=m;j++) a[i][j]=s[i][j]-'0';
        }
        for(int i=1;i<n-1;i++){
            for(int j=1;j<=m;j++) if(a[i][j]){
                if(j==m) insert(i,j,i+1,j-1,i+1,j);
                else if(a[i][j+1]) insert(i,j,i,j+1,i+1,j);
                else insert(i,j,i+1,j,i+1,j+1);
            }
        }
        for(int i=1;i<m-1;i++){
            if(a[n-1][i]&&a[n][i]) insert(n-1,i,n,i,n,i+1);
            else if(a[n-1][i]) insert(n-1,i,n-1,i+1,n,i+1);
            else if(a[n][i]) insert(n,i,n-1,i+1,n,i+1);
        }
        pii k1[5],k2[5]; int top1=0,top2=0;
        for(int i=n-1;i<=n;i++){
            for(int j=m-1;j<=m;j++) 
                if(a[i][j]) k1[++top1]=mk(i,j);
                else k2[++top2]=mk(i,j);
        }
        if(top1==1) kkk1(k1[1].first,k1[1].second,k2[1].first,k2[1].second,k2[2].first,k2[2].second,k2[3].first,k2[3].second);
        if(top1==2) kkk2(k1[1].first,k1[1].second,k1[2].first,k1[2].second,k2[1].first,k2[1].second,k2[2].first,k2[2].second);
        if(top1==3) insert(k1[1].first,k1[1].second,k1[2].first,k1[2].second,k1[3].first,k1[3].second);
        if(top1==4) kkk4(n-1,m-1,n-1,m,n,m-1,n,m);
        printf("%d\n",sz(ans));
        for(auto &u : ans){
            printf("%d %d %d %d %d %d\n",u.x1,u.y1,u.x2,u.y2,u.x3,u.y3);
        }
    }
    return 0;
}