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

stack<char> cur;
int lst = -1;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	string s,ans; cin >> s;
	F0R(i,26) {
	    while (cur.size() && cur.top() <= ('a'+i)) {
	        ans += cur.top();
	        cur.pop();
	    }
	    int a = s.length();
	    for (int j = s.length()-1; j > lst; --j) {
	        if (s[j] == ('a'+i)) {
	            a = j;
	            break;
	        }
	    }
	    lst ++;
	    if (a != s.length()) {
	        for (;lst <= a; ++lst) {
	            if (s[lst] == 'a'+i) ans += s[lst];
	            else cur.push(s[lst]);
	        }
	    }
	    lst --;
	}
	while (cur.size()) {
	    ans += cur.top();
	    cur.pop();
	}
	cout << ans;
}