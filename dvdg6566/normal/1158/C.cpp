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
#define MAXN 500100

vpi V;
int T,N,a;
vi G[MAXN];

void run(){
    int A[N+2];
    stack<pair<pi,int> > st;
    while(SZ(st))st.pop();
    memset(A, 0, sizeof(A));
    for (int i=0;i<SZ(V);++i)G[i].clear();
    V.pb(mp(-1,N));
    sort(ALL(V));
    for (int i=0;i<SZ(V);++i)G[i].clear();

    for (int it=1;it<SZ(V);++it){
        pi i = V[it];
        while (SZ(st) && st.top().f.s <= i.f){
            st.pop();
        }
        if (SZ(st) == 0){
            st.push(mp(i, it));
            G[0].pb(it);
            continue;
        }
        if (st.top().f.s >= i.s){
            // Subset
            G[st.top().s].pb(it);
            st.push(mp(i,it));
            continue;
        }
        cout<<-1<<'\n';
        return;
    }
    V[0].f = 1;
   //  for (auto v : V)cout<<v.f<<' '<<v.s<<'\n';

   //  for (int i=0;i<SZ(V);++i){
   //      for (auto v : G[i])cout<<v<<' ';cout<<'\n';
   // }
    
    pi rang[SZ(V)];
    rang[0] = mp(1, N);
    A[N+1] = N+1;

    for (int i =0;i<SZ(V);++i){
        if (i) {
            rang[i].s = rang[i].f + V[i].s - V[i].f - 2;
            // cout<<"Range is " << rang[i].f <<' '<<rang[i].s << '\n';
            if(rang[i].s < 0)continue;
        }
        // cout<<V[i].f<<' '<<V[i].s<<'\n';
        vi tmp;
        for (auto x : G[i]){
            tmp.pb(V[x].f);
            tmp.pb(V[x].s);
        }
        tmp.resize( unique(ALL(tmp)) - tmp.begin() );
        // for (auto i : tmp)cout<<i<<' ';cout<<'\n';
        reverse(ALL(tmp));
        for (auto v : tmp){
            if (A[v])continue;
            A[v] = rang[i].s;
            --rang[i].s;
        }
        int ind = 0;
        int cnt = rang[i].f;
        // for (int i=1;i<=N;++i)cout<<A[i]<<' ';cout<<'\n';
        for (int j = V[i].f; j <= V[i].s; ++j){
            if (A[j] != 0)continue;
            while (SZ(G[i]) > ind && j > V[G[i][ind]].f+1)++ind;
            if (SZ(G[i]) > ind && j == V[G[i][ind]].f+1){
                int t = G[i][ind];
                rang[t].f = cnt;
                int l = V[t].s - V[t].f - 1;
                cnt += l;
                j += l;
                ++ind;
                continue;
            }
            A[j] = cnt++;
        }
    }
    for (int i=1;i<=N;++i)cout<<A[i]<<' ';cout<<'\n';
}

int main(){
    // freopen("in.txt","r",stdin);
    cin >> T;
    while(T--){
        cin >> N;
        V.clear();
        for (int i=1;i<=N;++i){
            cin >> a;
            if (a != -1)V.pb(mp(i,a));
        }
        run();
    }
}