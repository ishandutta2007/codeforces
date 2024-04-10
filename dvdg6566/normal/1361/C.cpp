#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MAXN=1200010;
const ll MAXK=17;
const ll INF=1e18;
const ll MOD=1e9+7;

ll N;
ll A[MAXN];
vi CB[MAXN];
int p[MAXN];
int par(int x){return (p[x]==x)?x:p[x]=par(p[x]);}

int ask(int X){
    int mod = (1<<X);
    for (int i=0;i<mod;++i){CB[i].clear();}
    for (int i=0;i<2*N;i+=2){
        p[i]=p[i+1]=i;
        int a=i;
        int b=i+1;
        int c=A[a]%mod;
        int d=A[b]%mod;
        CB[c].pb(a);
        CB[d].pb(b);
    }
    for(int i=0;i<mod;++i){
        int t=SZ(CB[i]);
        if(t%2==1)return 0;
        for (auto x:CB[i])if(x!=CB[i][0]){
            p[par(x)] = par(CB[i][0]);
            // cerr<<x<<' '<<CB[i][0]<<'\n';
        }
    }
    // for(int i=1;i<=2*N;++i)cerr<<par(i)<<' ';cerr<<'\n';
    int cnt=0;
    for (int i=0;i<2*N;++i)if(par(i)==i)++cnt;
    if(cnt!=1)return 0;
    return 1;
}

vi V[MAXN];
int done[MAXN];
vi output[MAXN];
int cur=1;

struct node{
    node* nx=nullptr;
    int x;
    node(int _x){
        x=_x;
    }
    void insertAfter(int y){
        node* tmp = nx;
        nx = new node(y);
        // cerr<<"Next node "<<y<<'\n';
        nx->nx=tmp;
    }
}*root;
vi out;

void outP(){
    node* cur = root;
    while(cur!=nullptr){
        out.pb(cur->x+1);
        cur=cur->nx;
    }
}

void dfs(int grp,int tar, node* cur){
    // cerr<<"Visiting "<<tar<<" at grp "<<grp<<'\n';
    int fst=1;
    while(SZ(V[grp])){
        while(SZ(V[grp]) && done[V[grp].back()])V[grp].pop_back();
        if(!SZ(V[grp]))break;
        int t = V[grp].back();
        node* tmp = cur;
        tmp->insertAfter(t);
        tmp=tmp->nx;
        tmp->insertAfter(t^1);
        tmp=tmp->nx;
        // outP();
        done[t]=1;
        done[t^1]=1;
        if(fst)fst=0;
        dfs(A[t^1], t^1,tmp);
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N;
    for (int i=0;i<2*N;++i)cin>>A[i];
    int res=20;
    for (int i=0;i<=20;++i){
        int t=ask(i);
        if(t==0){res=i-1;break;}
    }
    cout<<res<<'\n';
    int mod=(1<<res);
    for (int i=0;i<N*2;++i){
        A[i]%=mod;
    }
    for(int i=0;i<N*2;i+=2){
        V[A[i]].pb(i);
        V[A[i+1]].pb(i+1);
    }
    for(int i=0;i<mod;++i)sort(ALL(V[i]));
    root = new node(0);
    root->insertAfter(1);
    done[0]=1;
    done[1]=1;
    dfs(A[1],1,root->nx);

    outP();
    for (auto i:out)cout<<i<<' ';cout<<'\n';
    // for (int i=1;i<2*N;i+=2){
    //     cerr<<A[out[i]-1]<<' '<<b<<'\n';
    // }
}