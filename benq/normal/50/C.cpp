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

int minx = MOD, maxx = -MOD, miny = MOD, maxy = -MOD;
int mindif = MOD, maxdif = -MOD, minsum = MOD, maxsum = -MOD;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int N; cin >> N;
	F0R(i,N) {
		int x,y; cin >> x >> y;
		minx = min(minx,x-1);
		maxx = max(maxx,x+1);
		miny = min(miny,y-1);
		maxy = max(maxy,y+1);
		mindif = min(mindif,y-x-1);
		maxdif = max(maxdif,y-x+1);
		minsum = min(minsum,x+y-1);
		maxsum = max(maxsum,x+y+1);
	}
	int cans = 2*(maxx-minx+maxy-miny);
	cans -= abs(maxx+maxy-maxsum);
	cans -= abs(minx+miny-minsum);
	cans -= abs(miny-(maxx+mindif));
	cans -= abs(maxy-(minx+maxdif));
	cout << cans;
}