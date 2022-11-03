#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> II;

template<typename T, typename S>
ostream& operator << (ostream& out, const pair<T, S>& p) {
    out << '{' << p.first << ", " << p.second << '}';
    return out;
}

template<typename T>
ostream& operator << (ostream& out, const vector<T>& v) {
    out << '[';
    for(T& i : v) {
        cout << i << ' ';
    }
    out << ']';
    return out;
}

template<typename I>
vector<int> Z_algorithm(I b, I e) {
    I l = b, r = b;
    vector<int> Z(e - b);
    for(I i = b + 1; i != e; ++i) {
        if(i > r) {
            l = r = i;
            while(r < e and *(b + (r - l)) == *r) {
                ++r;
            }
            Z[i - b] = r - l;
            --r;
        } else {
            if(Z[i - l] <= r - i) {
                Z[i - b] = Z[i - l];
            } else {
                l = i;
                while(r < e and *(b + (r - l)) == *r) {
                    ++r;
                }
                Z[i - b] = r - l;
                --r;
            }
        }
    }
    return Z;
}

int main() {
    #ifdef DEBUG
    freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string S;
    cin >> S;
    auto Z = Z_algorithm(S.begin(), S.end());
    int maxz = 0;
    int N = S.length();
    for(int i = 1; i < N; ++i) {
        if(Z[i] == N - i and maxz >= Z[i]) {
            cout << S.substr(0, Z[i]) << '\n';
            return 0;
        }
        maxz = max(maxz, Z[i]);
    }
    cout << "Just a legend\n";
}