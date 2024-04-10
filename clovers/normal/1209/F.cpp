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
const int MOD=1e9+7;
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
const int N=1200005;
int n,m,tot;
vector<pii> v[N];
int dis[N],vis[N],bl[N];
vector<int> seq[N*10]; vector<int> used;
void add_edge(int x,int y,int id){
    int nxt=y;
    while(id>=10){
        tot++;
        v[tot].push_back(mk(nxt,id%10));
        id/=10; nxt=tot;
    }
    v[x].push_back(mk(nxt,id));
}
void bfs(){
    int cnt=1;
    queue<int> q; seq[1].push_back(1);
    dis[1]=0; vis[1]=1; q.push(1);
    while(!q.empty()){
        int now=q.front(); q.pop();
        for(int val=0;val<=9;val++){
            cnt++;
            for(auto &u : seq[now]){
                for(auto &to : v[u]) if(to.second==val&&!vis[to.first]){
                    dis[to.first]=add(mul(dis[u],10),val);
                    vis[to.first]=1; seq[cnt].push_back(to.first);
                }
            }
            if(!seq[cnt].empty()) q.push(cnt);
            else cnt--;
        }
    }
    for(int i=2;i<=n;i++) printf("%d\n",dis[i]);
}

int main()
{
    n=read(); m=read(); tot=n;
    for(int i=1;i<=m;i++){
        int x=read(),y=read();
        add_edge(x,y,i);
        add_edge(y,x,i);
    }
    bfs();
    return 0;
}