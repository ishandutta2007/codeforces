#include "bits/stdc++.h"
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=110;

int parent[N],siz[N],pos[N];
int findParent(int i)
{
	if(parent[parent[i]]!=parent[i])
		parent[i]=findParent(parent[i]);
	return parent[i];
}
void unionNodes(int a,int b)
{
	int parent_a=findParent(a),parent_b=findParent(b);
	if(parent_a==parent_b)
		return;
	if(siz[parent_a]>=siz[parent_b]){
		swap(parent_a,parent_b);
	}
	siz[parent_b]+=siz[parent_a];
	parent[parent_a]=parent_b;
	return;
}
void cleardsu(int n){
	for(int i=0;i<n;i++){
		parent[i]=i;
		siz[i]=1;
	}
}

int n;
int c1 = 0, c2 = 0;

int q1(int a,int b){
	c1++;
	assert(c1 <= 9 * n);
	assert(0 <= a && a < n);
	assert(0 <= b && b < n);
	cout << "1 " << a << " " << b << endl;
	int ans;
	cin >> ans;
	return ans;
}

int q2(int x,vector<int> vals){
	c2++;
	assert(c2 <= 2 * n);
	assert(0 <= x && x < n);
	cout << "2 " << x << " " << sz(vals) << " ";
	assert(sz(vals) > 0 );
	assert(sz(vals) < n);
	for(int y:vals){
		assert(0 <= y && y < n);
		cout << y << " ";
	}
	cout << endl;
	int ans;
	cin >> ans;
	return ans;
}

void solve(){
	c1 = c2 = 0;
	cin >> n;
	
	cleardsu(n);
	
	vector<int> order = {0};
	
	rep(i,1,n){
		// put i in the order using bin search
		int k = sz(order);
		int L = 0, U = k;
		while(L < U){
			int m = (L + U) / 2;
			// put it in mth pos, that is above order[m]
			if(q1(i,order[m])){
				// edge from i to order m
				U = m;
			}
			else{
				L = m + 1;
			}
		}
		// put it on U-th position
		order.emplace_back();
		for(int j = k; j > U; j--){
			order[j] = order[j - 1];
		}
		order[U] = i;
	}
	
	// rep(i,1,n){
	// 	assert(q1(order[i-1],order[i]));
	// }
	
	// for(int x:order){
	// 	cout << x << "\n";
	// }
	
	rep(i,0,n){
		pos[order[i]] = i;
	}
	
	
	// order is basically toposort
	// now make SCCs
	
	int f = n - 1;
	
	for(int i = n - 1; i > 0; i--){
		amin(f,i);
		while(f > 0){
			vector<int> query;
			rep(j,0,f){
				query.pb(order[j]);
			}
			int res = q2(order[i],query);
			if(res){
				f--;
				unionNodes(order[i],order[f]);
			}
			else{
				break;
			}
		}
	}
	
	rep(i,0,n){
		pos[i] = pos[findParent(i)];
	}
	
	
	cout << 3;
	
	rep(i,0,n){
		cout << "\n";
		rep(j,0,n){
			cout << (pos[i] <= pos[j]);
		}
	}
	cout << endl;
	
	int out;
	cin >> out;
	assert(out == 1);
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	cin>>t;
	while(t--) solve();
	return 0;
}