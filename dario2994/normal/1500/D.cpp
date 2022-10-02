#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))

// Returns the time elapsed in nanoseconds from 1 January 1970, at 00:00:00.
LL get_time() {
    return chrono::duration_cast<chrono::nanoseconds>(
        chrono::steady_clock::now().time_since_epoch())
        .count();
}

template <typename T1, typename T2>
string print_iterable(T1 begin_iter, T2 end_iter, int counter) {
    bool done_something = false;
    stringstream res;
    res << "[";
    for (; begin_iter != end_iter and counter; ++begin_iter) {
        done_something = true;
        counter--;
        res << *begin_iter << ", ";
    }
    string str = res.str();
    if (done_something) {
        str.pop_back();
        str.pop_back();
    }
    str += "]";
    return str;
}

template <typename S, typename T>
ostream& operator <<(ostream& out, const pair<S, T>& p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}

template <typename T>
ostream& operator <<(ostream& out, const vector<T>& v) {
    out << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        out << v[i];
        if (i != (int)v.size()-1) out << ", ";
    }
    out << "]";
    return out;
}

template<class TH>
void _dbg(const char* name, TH val){
    clog << name << ": " << val << endl;
}
template<class TH, class... TA>
void _dbg(const char* names, TH curr_val, TA... vals) {
    while(*names != ',') clog << *names++;
    clog << ": " << curr_val << ", ";
    _dbg(names+1, vals...);
}

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
    #define dbg_arr(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////


const int MAXN = 1600;
const int MAXQ = 11;
int N, Q;
int C[MAXN][MAXN];
int rdiff[MAXN][MAXN][MAXQ];
int ddiff[MAXN][MAXN][MAXQ];

pair<int,int> diff[MAXN][MAXN][MAXQ];

bool used[MAXN*MAXN];

pair<int,int> TMP1[MAXQ*4], TMP2[MAXQ*4], TMP3[MAXQ*4], TMP4[MAXQ*4], TMP5[MAXQ*4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    cin >> N >> Q;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> C[i][j];
    for (int i = 0; i < N; i++) {
        for (int q = 0; q < MAXQ; q++) rdiff[i][N][q] = N;
        for (int j = N-1; j >= 0; j--) {
            rdiff[i][j][0] = j;
            int it = 1;
            for (int q = 0; it < MAXQ; q++) {
                if (C[i][rdiff[i][j+1][q]] != C[i][j]) {
                    rdiff[i][j][it] = rdiff[i][j+1][q];
                    it++;
                }
            }
        }
    }

    for (int j = 0; j < N; j++) {
        for (int q = 0; q < MAXQ; q++) ddiff[N][j][q] = N;
        for (int i = N-1; i >= 0; i--) {
            ddiff[i][j][0] = i;
            int it = 1;
            for (int q = 0; it < MAXQ; q++) {
                if (C[ddiff[i+1][j][q]][j] != C[i][j]) {
                    ddiff[i][j][it] = ddiff[i+1][j][q];
                    it++;
                }
            }
        }
    }

    vector<int> res(N+1, 0);
    
    for (int j = 1; j <= N; j++) for (int q = 0; q < MAXQ; q++) {
        diff[N][j][q] = {N, j};
        diff[j][N][q] = {j, N};
    }
    for (int i = N-1; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            for (int q = 0; q < MAXQ; q++) TMP1[q] = diff[i+1][j+1][q];
            for (int q = 0; q < MAXQ; q++) TMP2[q] = {i, rdiff[i][j][q]};
            for (int q = 0; q < MAXQ; q++) TMP3[q] = {ddiff[i][j][q], j};
            auto cmp = [&](const auto& pp, const auto& qq) {
                return max(pp.first-i, pp.second-j) < max(qq.first-i, qq.second-j);
            };
            merge(TMP1, TMP1+MAXQ, TMP2, TMP2+MAXQ, TMP4, cmp);
            merge(TMP4, TMP4+2*MAXQ, TMP3, TMP3+MAXQ, TMP5, cmp);
            
            
            // vector<pair<int,int>> vec;
            // for (int q = 0; q < MAXQ; q++) {
                // vec.push_back(diff[i+1][j+1][q]);
                // vec.push_back(pair<int,int>{i, rdiff[i][j][q]});
                // vec.push_back(pair<int,int>{ddiff[i][j][q], j});
            // }
            // sort(vec.begin(), vec.end(), [&](const auto& pp, const auto& qq) {
                // return max(pp.first-i, pp.second-j) < max(qq.first-i, qq.second-j);
            // }); // this can be optimized!
            int q = 0;
            for (int _ = 0; _ < 3*MAXQ; _++) {
                auto pp = TMP5[_];
                int c = C[pp.first][pp.second];
                if (c == 0) {
                    diff[i][j][q] = pp;
                    q++;
                } else if (!used[c]) {
                    used[c] = true;
                    diff[i][j][q] = pp;
                    q++;
                }
                if (q == MAXQ) break; // filled!
            }
            for (int q = 0; q < MAXQ; q++) used[C[diff[i][j][q].first][diff[i][j][q].second]] = false;
            auto pp = diff[i][j][Q]; // the first one which is outside!
            int len = max(pp.first-i, pp.second-j);
            len = min(len, N-i);
            len = min(len, N-j);
            // dbg(i, j, len);
            res[len]++;

            // dbg(i, j);
            // dbg_arr(diff[i][j], MAXQ);
        }
    }
    for (int k = N-1; k >= 1; k--) res[k] += res[k+1]; 
    for (int k = 1; k <= N; k++) cout << res[k] << "\n";
}