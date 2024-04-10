#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,ll> pii;
typedef vector<pi> vpi;
typedef set<ll> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
ll INF = 1e15;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define f first 
#define s second
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define MAXN 200100

int N,indexof[MAXN],A[MAXN];

struct node{
    int s,e,m,v;
    node *l, *r;
    node(int _s, int _e, node *pref, int u, int fst): s(_s), e(_e){
        m=(s+e)/2;
        if (fst == 1){
            // Initial 
            if (s == e){
                v = 0;
            }else{
                l = new node(s,m,pref,u,1);
                r = new node(m+1,e,pref,u,1);
            }
        }else{
            if (s == e){
                assert(s == u);
                v = 1;
                return;
            }
            if (u <= m){
                // update left node
                r = pref->r;
                l = new node(s,m,pref->l,u,0);
            }else{
                // update right node
                l = pref->l;
                r = new node(m+1, e, pref->r, u,0);
            }
        }
    }
    bool query(int x){
        if (s == e)return v;
        if (x <= m)return l->query(x);
        return r->query(x);
    }
}*root[MAXN];

struct SparseTable{
    int N,K;
    vector<vi> ST;
    SparseTable(int _N): N(_N){
        K = MSB(N);
        ST.resize(K);
        ST[0] = vi(A,A+N);
        for (int k=1;k<K;++k){
            for (int i=0;i+(1<<k)<=N;++i){
                ST[k].pb(max(ST[k-1][i], ST[k-1][i+(1<<(k-1))]));
            }
        }
    }
    inline int MSB(int x){return 32 - __builtin_clz(x);}
    int query(int x, int y){
        int k = MSB(y-x+1)-1;
        return max(ST[k][x], ST[k][y - (1<<k) + 1]);
    }
}*S;

bool inrange(pi rng, int t){
    if (!root[rng.s]->query(t))return 0;
    if (root[rng.f-1]->query(t))return 0;
    return 1;
}

int mem[MAXN],ans;

void dnc(int s, int e){
    int m = indexof[S->query(s,e)];
    pi leftwin = mp(s,m-1);
    pi rightwin = mp(m+1, e);
    if (leftwin.s >= leftwin.f && rightwin.s >= rightwin.f){
        pi smol = leftwin;
        pi big = rightwin;
        if (rightwin.s - rightwin.f < leftwin.s - leftwin.f){
            swap(smol, big);
        }
        int a = 0;
        for (int i=smol.f;i<=smol.s;++i){
            int j = A[i];
            int k = A[m] - j;
            if (inrange(big, k)){
                ++a;
            }
        }
        ans += a;
    }
    // Length needs to be at least 3
    if (leftwin.f+1 < leftwin.s)dnc(leftwin.f,leftwin.s);
    if (rightwin.f+1 < rightwin.s)dnc(rightwin.f,rightwin.s);
}

int main(){
    //freopen("in.txt","r",stdin);
    cin >> N;
    for (int i=1;i<=N;++i){
        cin >> A[i];
        indexof[A[i]] = i;
    }

    S = new SparseTable(N+1);
    root[0] = new node(1,N,root[1],0,1);

    for (int i=1;i<=N;++i){
        root[i] = new node(1,N,root[i-1],A[i], 0);
    }

    dnc(1,N);
    cout<<ans<<' ';
    // int o = 0;
    // for (int i=1;i<=N;++i){
    //     for (int j=i+1;j<=N;++j){
    //         if (A[i] + A[j] == S->query(i,j))++o;
    //     }
    // }
    // cout<<o;
}