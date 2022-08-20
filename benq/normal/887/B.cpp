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

bool ok[1001];
vector<vi> num;
int n;

void ins(string s) {
    if (s[0] == '0') return;
    ok[stoi(s)] = 1;
}

void test1(int x) {
    F0R(i,6) {
        string s; s += char('0'+num[x][i]);
        ins(s);
    }
}

void test2(int x, int y) {
    F0R(i,6) F0R(j,6) {
        string s; s += char('0'+num[x][i]); s += char('0'+num[y][j]);
        ins(s);
    }
}

void test3(int x, int y, int z) {
    F0R(i,6) F0R(j,6) F0R(k,6) {
        string s; s += char('0'+num[x][i]); s += char('0'+num[y][j]); s += char('0'+num[z][k]);
        ins(s);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n; num.resize(n);
	F0R(i,n) {
	    num[i].resize(6);
	    F0R(j,6) cin >> num[i][j];
	}
	sort(num.begin(),num.end());
	F0R(i,n) test1(i);
	F0R(i,n) F0R(j,n) if (i != j) test2(i,j);
	F0R(i,n) F0R(j,n) F0R(k,n) if (i != j && j != k && i != k) test3(i,j,k);
	
	FOR(i,1,1001) if (!ok[i]) {
	    cout << i-1;
	    return 0;
	}
}

// read!
// ll vs. int!