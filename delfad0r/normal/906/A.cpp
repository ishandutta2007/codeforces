#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

template <typename T>
ostream& operator <<(ostream& out, const vector<T>& vec) {
	out << "[";
	for (T x : vec) out << x << ", ";
	out << "]";
	return out;
}

#if DEBUG && !ONLINE_JUDGE
	#define dbg_var(x) cerr << #x << ": " << x << endl;
#else
	#define dbg_var(x)
#endif

int N;
bool possible[300];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    fill(possible + 'a', possible + 'z' + 1, true);
    
    cin >> N;
    while(N > 0) {
        --N;
        string k, q;
        cin >> k >> q;
        if(k == "?") {
            possible[q[0]] = false;
        } else if(k  == ".") {
            for(char c : q) {
                possible[c] = false;
            }
        } else if(k == "!") {
            for(char c = 'a'; c <= 'z'; ++c) {
                if(count(q.begin(), q.end(), c) == 0) {
                    possible[c] = false;
                }
            }
        } else {
            abort();
        }
        if(count(possible + 'a', possible + 'z' + 1, true) == 1) {
            break;
        }
    }
    int ans = 0;
    while(N > 0) {
        --N;
        string k, q;
        cin >> k >> q;
        if(k == "?" || k == "!") {
            ++ans;
        }
    }
    cout << max(0, ans - 1) << '\n';
}