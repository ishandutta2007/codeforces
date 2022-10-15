#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define MAXN 100010
#define MAXL 17
#define INF 1e9
int MOD = 1e9+7;
 
deque<pi> D;

string S;
int N,a,b;

int main(){
	cin>>S;
	N=SZ(S);
	for (auto i : S){
		if (!SZ(D) || D.back().f != i - 'a')D.pb(i-'a', 1);
		else ++D.back().s;
	}
	int ans = 0;
	while (SZ(D) > 1){
		if (D[0].f == D.back().f && D[0].s + D.back().s >= 3){
			D.pop_front();D.pop_back();
		}else{
			cout<<0;
			return 0;
		}
	}
	if (SZ(D)!=1){cout<<0;return 0;}
	if (D[0].s < 2){cout<<0;return 0;}
	cout<<D[0].s+1;
}