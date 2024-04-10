#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file
#else

#endif

const LL INF = 1e16;
const int MAXN = 1<<18;

LL seg1[2*MAXN];
void Add1(int p, LL x) {
    seg1[MAXN+p] += x;
    int v = (MAXN+p)/2;
    while (v > 0) seg1[v] += x, v /= 2;
}

LL Ask1(int v, int a, int b, int l, int r) {
    if (b < l or r < a) return 0;
    if (l <= a and b <= r) return seg1[v];
    int m = (a+b) / 2;
    return Ask1(2*v, a, m, l, r) + Ask1(2*v+1, m+1, b, l , r);
}

LL seg2[2*MAXN];
LL flag[2*MAXN];

void Deflag(int v) {
    if (v >= MAXN) return;
    if (flag[v] == 0) return;
    flag[2*v] += flag[v], seg2[2*v] += flag[v];
    flag[2*v+1] += flag[v], seg2[2*v+1] += flag[v];
    flag[v] = 0;
}

void Add2(int v, int a, int b, int l, int r, LL x) {
    if (b < l or r < a) return;
    if (l <= a and b <= r) {
        flag[v] += x;
        seg2[v] += x;
        return;
    }
    //~ cout << "v " << v << endl;
    Deflag(v);
    int m = (a+b)/2;
    Add2(2*v, a, m, l, r, x);
    Add2(2*v+1, m+1, b, l , r, x);
    seg2[v] = max(seg2[2*v], seg2[2*v+1]);
}

LL Ask2(int v, int a, int b, int l, int r) {
    if (b < l or r < a) return -2*INF;
    if (l <= a and b <= r) return seg2[v];
    Deflag(v);
    int m = (a+b)/2;
    return max(Ask2(2*v, a, m, l, r), Ask2(2*v+1, m+1, b, l, r));
}


int main() {
    //~ for (int v = 1; v < 2*MAXN; v++) seg2[v] = -INF;
    //~ Add2(1, 0, MAXN-1, 1, 1, -1);
    //~ Add2(1, 0, MAXN-1, 1, 1, INF);
    //~ cout << Ask2(1, 0, MAXN-1, 1, 1);
    //~ return 0;
    ios::sync_with_stdio(false);
    cin.tie(0); // Togliere nei problemi con query online

    int n;
    LL T;
    cin >> n >> T;
    vector<LL> t(n+1, 0);
    for (int i = 1; i <= n; i++) cin >> t[i];
    vector<LL> val(n+1);
    for (int i = 0; i <= n; i++) val[i] = t[i] - i;
    vector<int> ord(n+1);
    for (int i = 0; i <= n; i++) ord[i] = i;
    sort(ord.begin(), ord.end(), [&] (int i, int j) {
                    if (val[i] == val[j]) return i < j;
                    return val[i] > val[j];});
                    
    vector<LL> stop(n+1, -INF);

    for (int i = 0; i <= n; i++) seg1[MAXN+i] = 1;
    for (int v = MAXN-1; v >= 1; v--) seg1[v] = seg1[2*v] + seg1[2*v+1];

    for (int v = 1; v < 2*MAXN; v++) seg2[v] = -INF;

    //~ cout << Ask1(1, 0, MAXN-1, 2, 4) << endl;
    for (int i : ord) {
        if (t[i] < T) {
            //~ if (i == 1) cout << i+1 << " " << T-val[i]-1 << " " << Ask1(1, 0, MAXN-1, i+1, T-val[i]-1) << endl;
            stop[i] = 1;
            if (T-val[i]-1 >= i+1) stop[i] = max(stop[i], 1 + Ask1(1, 0, MAXN-1, i+1, min(T-val[i]-1, (LL)n)));
            //~ if (i == 1) cout << i << " " << stop[i] << endl;
            //~ if (i == 0) cout << i << " " << Ask1(1, 0, MAXN-1, 0, i) << " " <<  Ask2(1, 0, MAXN-1, i+1, n) << endl;
            stop[i] = max(stop[i], 1 - Ask1(1, 0, MAXN-1, 0, i) + Ask2(1, 0, MAXN-1, i+1, n));
        }
        //~ cout << "tolgo " << i << endl;
        Add1(i, -1);
        Add2(1, 0, MAXN-1, i, n, -1);
        //~ cout << Ask2(1, 0, MAXN-1, i, i) << endl;
        Add2(1, 0, MAXN-1, i, i, -Ask2(1, 0, MAXN-1, i, i));
        //~ if (i == 1) cout << "cacca " << stop[i] + Ask1(1, 0, MAXN-1, 0, i) << " " << Ask2(1, 0, MAXN-1, i, i) << endl;
        Add2(1, 0, MAXN-1, i, i, stop[i] + Ask1(1, 0, MAXN-1, 0, i));
        //~ cout << Ask2(1, 0, MAXN-1, i, n) << endl;
    }

    //~ cout << "ordine: ";
    //~ for (int i : ord) cout << i << " ";
    //~ cout << endl;
    //~ for (int i = 0; i <= n; i++) cout << i << " " << stop[i] << endl;

    cout << stop[0] - 1 << "\n";
}