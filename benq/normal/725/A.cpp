#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
 
const int MOD = 1000000007;
double PI = 4*atan(1);

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n, a = 0; cin >> n;
	string s; cin >> s;
	F0R(i,s.length()) {
	    if (s[i] == '<') a++;
	    else break;
	}
	for(int i = s.length()-1; i >= 0; --i) {
	    if (s[i] == '>') a++;
	    else break;
	}
	cout << a;
}