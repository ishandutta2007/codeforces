/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

map<char,int> m1;
char m2[26];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	string a,b; cin >> a >> b;
	F0R(i,26) m1[a[i]] = i;
	F0R(i,26) m2[i] = b[i];
	
	string z; cin >> z;
	for (char x: z) {
	    if ('0' <= x && x <= '9') cout << x;
	    else if ('A' <= x && x <= 'Z') cout << char(m2[m1[x-'A'+'a']]-'a'+'A');
	    else cout << m2[m1[x]];
	}
}