#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef map<int,int> mii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = b-1; i >= a; i--)
#define F0Rd(i,a) for (int i = a-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
double PI = 4*atan(1);

vector<pii> k,c;
vi cum;
int op = -1, car = 0, cur = 0;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,v; cin >> n >> v;
	F0R(i,n) {
		int t,p; cin >> t >> p;
		if (t == 1) k.pb(mp(p,i+1));
		else c.pb(mp(p,i+1));
	}
	sort(k.begin(),k.end()); sort(c.begin(),c.end());
	reverse(k.begin(),k.end()); reverse(c.begin(),c.end());
	cum.resize(k.size()+1);
	FOR(i,1,cum.size()) cum[i] = cum[i-1]+k[i-1].f;
	
	F0R(i,min((int)c.size()+1,v/2+1)) {
		if (i != 0) cur += c[i-1].f;
		if (cur+cum[min((int)cum.size()-1,v-2*i)]>car) {
			op = i;
			car = cur+cum[min((int)cum.size()-1,v-2*i)];
		}
	}
	cout << car << "\n";
	F0R(i,op) cout << c[i].s << "\n";
	F0R(i,min(v-2*op,(int)k.size())) cout << k[i].s << "\n";
}