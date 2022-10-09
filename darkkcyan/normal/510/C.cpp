#include<iostream>
using namespace std;

const int maxn = 111;
const int max_char = 26;
int gr[max_char][max_char] = {0};
int n;
string a[maxn];

void build_graph(int l, int r, int pos) {
    if (l >= r) return ;
    while (l <= r and (int)a[l].size() <= pos) ++l;
    int prev_l = l;
    for (int i = l; i <= r; ++i) {
        if ((int)a[i].size() <= pos) {
            cout << "Impossible";
            exit(0);
        }
        if (a[prev_l][pos] == a[i][pos]) continue;
        int u = a[prev_l][pos] - 'a';
        int v = a[i][pos] - 'a';
        if (gr[u][v] == -1) {
            cout << "Impossible";
            exit(0);
        }
        gr[u][v] = 1;
        gr[v][u] = -1;
        build_graph(prev_l, i - 1, pos + 1);
        prev_l = i;
    }
    build_graph(prev_l, r, pos + 1);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    build_graph(0, n - 1, 0);

    string ans = "";
    bool picked[26] = {0};
    while (true) {
        bool has = false;
        for (int i = 0; i < 26; ++i) {
            if (picked[i]) continue;
            int cnt_in = 0;
            for (int f = 0; f < 26; ++f) 
                cnt_in += gr[i][f] == -1 ? 1 : 0;
            if (cnt_in) continue;
            ans += char(i + 'a');
            for (int f = 0; f < 26; ++f) {
                gr[i][f] = gr[f][i] = 0;
            }
            picked[i] = true;
            has = true;
            break;
        }
        if (!has) break;
    }
    // cout << ans << endl; 
    if (ans.size() != 26) cout << "Impossible";
    else cout << ans;
    return 0;
}