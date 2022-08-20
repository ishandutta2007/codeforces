#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;

int n, k[2];
vi s[2];
int num[2][7000], dp[2][7000]; // -1 is lose, 0 is undetermined, 1 is win
queue<pii> todo;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	
	cin >> k[0]; s[0].resize(k[0]);
	F0R(i,k[0]) cin >> s[0][i];
	
	cin >> k[1]; s[1].resize(k[1]);
	F0R(i,k[1]) cin >> s[1][i];
	
	dp[0][0] = dp[1][0] = -1;
	todo.push({0,0}); todo.push({1,0});
	
	while (todo.size()) {
	    pii a = todo.front(); todo.pop();
	    if (dp[a.f][a.s] == 1) { // win
            for (int i: s[a.f^1]) if (dp[a.f^1][(i+a.s)%n] == 0) {
                num[a.f^1][(i+a.s)%n] ++;
                if (num[a.f^1][(i+a.s)%n] == s[a.f^1].size()) {
                    dp[a.f^1][(i+a.s)%n] = -1;
                    todo.push({a.f^1,(i+a.s)%n});
                }
            }
	    } else {
	        for (int i: s[a.f^1]) if (dp[a.f^1][(i+a.s)%n] == 0) {
                dp[a.f^1][(i+a.s)%n] = 1;
                todo.push({a.f^1,(i+a.s)%n});
            }
	    }
	}
	FORd(i,1,n) {
	    if (dp[0][i] == -1) cout << "Lose ";
	    else if (dp[0][i] == 0) cout << "Loop ";
	    else cout << "Win ";
	}
	cout << "\n";
	FORd(i,1,n) {
	    if (dp[1][i] == -1) cout << "Lose ";
	    else if (dp[1][i] == 0) cout << "Loop ";
	    else cout << "Win ";
	}
}

// read!
// ll vs. int!