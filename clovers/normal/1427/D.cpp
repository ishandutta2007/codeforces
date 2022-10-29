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
const int N=500005;
int n,a[N];
typedef vector<int> V;
vector<V> ans;

void move(V v){
    vector<V> T; T.clear();
    int now=0;
    for(auto to : v){
        V K; K.clear();
        while(to--) K.push_back(a[++now]);
        T.push_back(K);
    }
    reverse(T.begin(),T.end());
    now=0;
    for(auto &to : T){
        for(auto &to2 : to) a[++now]=to2;
    }
}

bool check(){
    for(int i=1;i<=n;i++) if(a[i]!=a[i-1]+1) return 0;
    return 1;
}

void solve(int m,int flag){
    if(check()) return;
    // cout<<m<<" "<<flag<<endl;
    // for(int i=1;i<=n;i++) cout<<a[i]<<" "; cout<<endl;
    vector<int> v; v.clear();
    if(m==n){
        if(flag){
            v.push_back(1);
            v.push_back(n-1);
            ans.push_back(v);
        }
        return;
    }
    int pos1,pos2;
    for(int i=1;i<=n;i++)
        if(a[i]==1) pos1=i;
        else if(a[i]==m+1) pos2=i;
    int val=m;
    if(flag){        
        if(pos1<pos2){
            if(pos1>2) v.push_back(pos1-2);
            v.push_back(1);
            v.push_back(val-1);
            v.push_back(pos2-(pos1+val-2));
            if(pos2!=n) v.push_back(n-pos2);
            ans.push_back(v);
            move(v);
            solve(m+1,1);
            return;
        }
        else{
            if(pos2>1) v.push_back(pos2-1);
            v.push_back(pos1-1-pos2);
            v.push_back(1);
            v.push_back(val-1);
            int rest=n-(pos2-1)-(pos1-1-pos2)-1-(val-1);
            if(rest) v.push_back(rest);
            ans.push_back(v);
            move(v);
            solve(m+1,0);
            return;
        }
    }
    else{
        if(pos1<pos2){
            if(pos1>1) v.push_back(pos1-1);
            v.push_back(val);
            v.push_back(pos2-(pos1+val-1));
            if(pos2!=n) v.push_back(n-pos2);
            ans.push_back(v);
            move(v);
            solve(m+1,1);
            return;
        }
        else{
            if(pos2>1) v.push_back(pos2-1);
            v.push_back(pos1-pos2);
            v.push_back(val);
            int rest=n-(pos2-1)-(pos1-pos2)-val;
            if(rest) v.push_back(rest);
            ans.push_back(v);
            move(v);
            solve(m+1,0);
            return;
        }
    }
}

int main()
{
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    solve(1,0);
    printf("%d\n",sz(ans));
    for(int i=0;i<sz(ans);i++){
        printf("%d ",sz(ans[i]));
        for(auto &to : ans[i]) printf("%d ",to);
        puts("");
    }
    return 0;
}