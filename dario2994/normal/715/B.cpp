// TODO: REMOVE IO from file
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL INF = 1e10;
const int MAXN = 1050;
int N;
int M;
int S, T;
int L;

vector <int> aa[MAXN];
vector <LL> ww[MAXN];

LL dist[MAXN];
LL dijstra() {
    for (int i = 0; i < N; i++) dist[i] = INF;
    priority_queue <pair<LL, int> > coda;
    dist[S] = 0;
    coda.push(make_pair(0, S));
    while(!coda.empty()) {
        auto pp = coda.top();
        coda.pop();
        int v = pp.second;
        LL d = -pp.first;
        
        if (v == T) return d;
        if (d > dist[v]) continue;
        for (int i = 0; i < (int) aa[v].size(); i++) {
            int a = aa[v][i];
            LL w = ww[v][i];
            if (dist[a] > d + w) {
                dist[a] = d+w;
                coda.push(make_pair(-dist[a], a));
            }
        }
    } 
    return dist[T];
}


vector <pair<pair<int, int>, pair<int,int> >> to_choose;
void set_value(int k, long long int w) {
    ww[to_choose[k].first.first][to_choose[k].first.second] = w;
    ww[to_choose[k].second.first][to_choose[k].second.second] = w;
}

void set_first(int q) {
    for (int k = 0; k < q; k++) set_value(k, 1);
    for (int k = q; k < (int)to_choose.size(); k++) set_value(k, INF);
}

void print_output() {
    cout << "YES\n";
    for (int v = 0; v < N; v++) {
        for (int i = 0; i < (int)aa[v].size(); i++) {
            int a = aa[v][i];
            if (a < v) continue;
            cout << v << " " << a << " " << ww[v][i] << "\n";
        }
    }
}

int main() {
    // std::ifstream cin("input.txt");
    // ofstream cout("output.txt");

    ios::sync_with_stdio(false);
    cin >> N >> M >> L >> S >> T;
    int u, v;
    long long w;
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        if (w == 0) {
            to_choose.push_back(make_pair(
                    make_pair(u, (int)ww[u].size()), 
                    make_pair(v, (int)ww[v].size())
            ));
            
        }
        aa[u].push_back(v);
        aa[v].push_back(u);
        ww[u].push_back(w);
        ww[v].push_back(w);
    }
    
    
    set_first(0);
    if (dijstra() == L) {
        print_output();
        return 0;
    }
    if (dijstra() < L) {
        cout << "NO";
        return 0;
    }
    
    set_first(to_choose.size());
    if (dijstra() == L) {
        print_output();
        return 0;
    }
    if (dijstra() > L) {
        cout << "NO";
        return 0;
    }
    
    // TUTTO INCLUSO
    int l = 1;
    int r = (int)to_choose.size();
    while (l < r) {
        int m = (l+r)/2;
        set_first(m);
        if (dijstra() > L) {
            l = m+1;
        } else {
            r = m;
        }
    }
    
    set_first(l);
    // cout << "Errore: " << dijstra() << "\n";
    set_value(l-1, 1+L - dijstra());
    print_output();
}