#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file
#else

#endif

const int MAXN = 100010;

int N;
vector<int> aa[MAXN];
double p[MAXN];
double s[MAXN];

int f[MAXN];

void father(int v, int p) {
    f[v] = p;
    for (int a : aa[v]) {
        if (a == p) continue;
        father(a, v);
    }
}

//~ double compute_res() {
    //~ double res = 0;
    //~ for (int i = 0; i < N; i++) res += (1-p[i])*p[f[i]];
    //~ return res;
//~ }

double read_double() {
    char c;
    int a, b;
    cin >> a >> c >> b;
    return a + b*1e-2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Togliere nei problemi con query online
    
    cin >> N;
    for (int i = 0; i < N; i++) p[i] = read_double();
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        aa[u].push_back(v);
        aa[v].push_back(u);
    }
    p[N] = 1;
    aa[N].push_back(0);
    aa[0].push_back(N);
    
    father(N, -1);

    for (int i = 0; i < N; i++) s[f[i]] += 1-p[i];
    
    double res = 0;
    for (int i = 0; i < N; i++) res += (1-p[i])*p[f[i]];
    //~ cout << res << endl;
    //~ res = compute_res();
    //~ cout << res << endl;
    
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int v;
        double pr;
        cin >> v;
        pr = read_double();
        res += s[v]*(pr - p[v]);
        res += (p[v] - pr)*p[f[v]];
        s[f[v]] += p[v] - pr;
        p[v] = pr;
        cout.precision(10);
        cout << fixed << res << "\n";
    }
    
}