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

map<string,int> a;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	a["monday"] = 0;
	a["tuesday"] = 1;
	a["wednesday"] = 2;
	a["thursday"] = 3;
	a["friday"] = 4;
	a["saturday"] = 5; 
	a["sunday"] = 6;
	string x,y; cin >> x >> y;
    if ((a[x] % 7 == a[y]) || ((a[x]+2) % 7 == a[y]) || ((a[x]+3) % 7 == a[y])) cout << "YES";
    else cout << "NO";
}