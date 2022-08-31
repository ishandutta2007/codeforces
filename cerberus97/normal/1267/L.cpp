// Nihesh Anderson - knandy
 
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
 
using namespace __gnu_pbds;
using namespace std;
 
typedef long long ll;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; // find_by_order, order_of_key
ll MOD=1000000007;
 
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char *name, Arg1 &&arg1) {
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
 
#else
#define trace(...)
#endif // ifndef ONLINE_JUDGE
 
#define endl '\n'
#define fast_cin() ios_base::sync_with_stdio(false)
#define pb push_back
#define debug1(x) cerr << x << endl;
#define debug2(x,y) cerr << x << " " << y << endl;
#define debug3(x,y,z) cerr << x << " " << y << " " << z << endl;
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORR(i, a, b) for (int i=a; i>=(b); i--)
ll INF = 2000000000000000001;
double EPS = 1e-9;
ll nextInt(){ll inp; cin>>inp; return inp;}
string nextStr(){string inp; cin>>inp; return inp;}
double nextDouble(){double inp; cin>>inp; return inp;}
ll power(ll a, ll n, ll md){if(n==0){return 1;}else{int res=power(a,n/2,md);res=(res*res)%md;if(n%2!=0){res=(res*a)%md;}return res;}}
random_device rndm;
mt19937 grndm(rndm());
void mix(int* a, int* b){shuffle(a,b,grndm);}
 
const int SZ = 1000 + 5;

int n, l, k;
char ans[SZ][SZ];

int main(){
	fast_cin();
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
	cin >> n >> l >> k;
	priority_queue<char, vector<char>, greater<char> > pq;
	FOR(i, 0, n * l) {
		char c; cin >> c;
		pq.push(c);
	}
	FOR(i, 0, n) {
		FOR(j, 0, l + 1) {
			ans[i][j] = '0';
		}
	}
	FOR(j, 0, l) {
		FOR(i, 0, k) {
			if(ans[i][j] == ans[k - 1][j]) {
				ans[i][j + 1] = pq.top();
				pq.pop();
			}
		}
	}
	FOR(i, 0, n) {
		FOR(j, 1, l + 1) {
			if(ans[i][j] == '0') {
				ans[i][j] = pq.top();
				pq.pop();
			}
		}
	}
	FOR(i, 0, n) {
		FOR(j, 1, l + 1) {
			cout << ans[i][j];
		}
		cout << endl;
	}
	return 0;
}