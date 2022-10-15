#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vpi;
typedef set<ll> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e18;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define MAXN 200100

int N,T;
int A[MAXN],B[MAXN],dd[MAXN];
multiset<int> V[MAXN];
vi des;
list<int> cyc;
int p[MAXN];
vi seq;
int cur;

void dfs(int x){
    for (auto i : V[x]){
        if (p[i] != -1)continue;
        p[i] = x;
        dfs(i);
    }
}

void EulerTour(list<int>::iterator i, int u, int head){
    // cout<<des[u]<<' '<<des[head]<<'\n';
    // cout<<"Next " << *n<<' '<<u<<'\n';
    if (SZ(V[u]) == 0){
        ++i;
        if (cur == u)cyc.insert(i,u);
        return;
    }
    // cout<<"At " << u <<'\n';
    // for (auto v : cyc)cout<<des[v]<<' ';cout<<'\n';
    // cout<<"At "<<u<<'\n';
    // cout<<"At first previous is " << *i<<'\n';
    int a = *i;
    ++i;
    cyc.insert(i,u);
    --i;
    int t = *V[u].begin();
    V[u].erase(V[u].begin());
    V[t].erase(V[t].find(u)); // Remove backedge
    EulerTour(i , t, head);
    --i;
    // cout<<des[u]<<' '<<des[*i]<<' '<<des[a]<<'\n';
    // for (auto v : cyc)cout<<des[v]<<' ';cout<<'\n';
    // assert(*i == a);

    while (SZ(V[u])){
        ++i;
        cyc.insert(i,u);
        --i;
        int t = *V[u].begin();
        V[u].erase(V[u].begin());
        V[t].erase(V[t].find(u)); // Remove backedge
        EulerTour(i, t, u);
        --i;
    }
}


int main(){
    // freopen("in.txt","r",stdin);
    cin >> N;
    
    for (int i=1;i<N;++i){
        cin >>A[i];
        des.pb(A[i]);
    }
    for (int i=1;i<N;++i){
        cin >>B[i];
        if (B[i] < A[i]){cout<<-1;return 0;}
        des.pb(B[i]);
    }


    sort(ALL(des));
    des.resize(unique(ALL(des)) - des.begin());

     for (int i=1;i<N;++i){
        A[i] = lb(ALL(des),A[i]) - des.begin();
        B[i] = lb(ALL(des),B[i]) - des.begin();
        if (A[i] == B[i]){++dd[A[i]];continue;}
        V[A[i]].insert(B[i]);
        V[B[i]].insert(A[i]);
    }
    T = SZ(des);
    int odds = 0,start=-1,stop=-1;
    for (int i=0;i<T;++i){
        if (SZ(V[i]) %2 == 1){
            if (stop != -1)start = i;
            else stop = i;
            odds++;
        }
    }
    if (odds != 2 && odds != 0){
        cout<<-1;
        return 0;
    }
    if (odds == 0){
        // Randomly start
        cur = 0;
        memset(p,-1,sizeof(p));
        p[0] = 1;
        dfs(0);
        for (int i=0;i<T;++i){
            if (p[i] == -1){
                cout<<-1;
                return 0;
            }
        }
        EulerTour(cyc.begin(),0,0);
    }
    else{
        memset(p,-1,sizeof(p));
        p[start] = 1;
        dfs(start);
        for (int i=0;i<T;++i){
            if (p[i] == -1){
                cout<<-1;
                return 0;
            }
        }
        seq.pb(stop);
        int t = stop;
        while (t != start){
            t = p[t];
            seq.pb(t);
        }
        // cout<<des[start]<<' '<<des[stop]<<'\n';
        reverse(ALL(seq));
        for (int i=1;i<SZ(seq);++i){
            int a = seq[i];
            int b = seq[i-1];
            // cout<<"Remove " << des[a] << ' '<<des[b]<<'\n';
            V[a].erase(V[a].find(b));
            V[b].erase(V[b].find(a));
        }
        // for (int i=0;i<T;++i)assert(SZ(V[i])%2 == 0);
        cyc.pb(-1);
        for (auto x : seq){
            // cout<<des[x]<<'\n';
            list<int>::iterator tt = --cyc.end();
            if (SZ(V[x])){
                cur = x;
                EulerTour(tt,x,x);
            }
            else cyc.pb(x);
            // for (auto i : cyc)cout<<i<<' ';cout<<'\n';
        }
    }
    // for (auto i : cyc)cout<<i<<' ';cout<<'\n';
    for (auto i : cyc){
        if (i == -1)continue;
        while (dd[i]){
            cout<<des[i]<<' ';
            --dd[i];
        }
        cout<<des[i]<<' ';
    }
}