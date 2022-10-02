#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;

template <typename T>
ostream& operator <<(ostream& out, const vector<T>& vec) {
    out << "[";
    for (int x : vec) out << x << ", ";
    out << "]";
    return out;
}

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file
    #define dbg_var(x) clog << #x << ": " << x << endl;
#endif

string S;
int N;

const int MAXN = 1e6 + 20;
const int INF = 1e8;
bool din[2*MAXN];
int first_back[2*MAXN];
bool works(int L) {
    vector<int> ps = {INF, INF};
    for (int k = N-1; k >= 0; k--) {
        if (S[k] == '.') {
            din[k] = din[k+1];
            first_back[k] = first_back[k+1];
        }
        else if (S[k] == 'P') {
            int h1 = ps.back();
            int h2 = ps[ps.size()-2];
            if (din[k+1]) {
                din[k] = true;
                first_back[k] = k;
            } else if (din[k+L+1]) {
                din[k] = true;
                first_back[k] = h1;
            } else if (h1 > k+L or !din[h1]) {
                din[k] = false;
                first_back[k] = INF;
            } else if (h2 <= k+L) {
                din[k] = true;
                first_back[k] = h1;
            } else {
                din[k] = din[h1];
                first_back[k] = first_back[h1];
            }
            ps.push_back(k);
        }
        else {
            if (first_back[k+1] <= k + L) {
                din[k] = din[k+1];
                first_back[k] = first_back[k+1];
            } else {
                din[k] = false;
                first_back[k] = INF;
            }
        }
    }
    //~ for (int i = 0; i < N; i++) cout << din[i];
    //~ cout << endl;
    
    return din[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    cin >> S;
    
    int pac_num = 0;
    int star_num = 0;
    for (char c : S) {
        pac_num += (c == 'P');
        star_num += (c == '*');
    }
    if (pac_num == 1) {
        int star_before = 0;
        int star_after = 0;
        int first_star = -1;
        int last_star = -1;
        int pacman_pos = -1;
        for (int i = 0; i < N; i++) {
            if (S[i] == 'P') pacman_pos = i;
            if (S[i] == '*') {
                last_star = i;
                if (first_star == -1) first_star = i;
                if (pacman_pos == -1) star_before++;
                else star_after++;
            }
        }
        if (star_before == star_after) {
            cout << star_before << " " << min(pacman_pos-first_star, last_star-pacman_pos) << "\n";
        }
        if (star_before > star_after) {
            cout << star_before << " " << pacman_pos-first_star << "\n";
        }
        if (star_after > star_before) {
            cout << star_after << " " << last_star-pacman_pos << "\n";
        }
        return 0;
    }
    
    for (int i = N; i <= 2*N+20; i++) {
        din[i] = true;
        first_back[i] = INF;
    }

    int l = 1;
    int r = N; // [l, r]
    while (l < r) {
        int m = (l+r)/2;
        if (works(m)) r = m;
        else l = m+1;
    }
    cout << star_num << " " << l << "\n";
}