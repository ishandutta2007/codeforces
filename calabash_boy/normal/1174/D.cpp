/* Generated by powerful Codeforces Tool
 * Author: calabash_boy_love_15 
 * Time: 2019-07-16 12:03:30
 * Personal Code Template: https://github.com/4thcalabash/ACM-Code-Library
**/
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#ifdef __LOCAL_DEBUG__
# define _debug(fmt, ...) fprintf(stderr, "\033[91m[%s %3d]: " fmt "\n\033[0m", \
  __func__,__LINE__, ##__VA_ARGS__)
#else
# define _debug(...) (void(0))
#endif
#define PB(x) push_back(x)
#define rep(i,l,r) for (int i = l,_ = r;i< _;i++)
#define REP(i,l,r) for (int i=l,_=r;i<=_;i++)
#define leave(x) do {cout<<#x<<endl;fflush(stdout);return 0;}while (0);
#define untie do{ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);}while (0)
#define range(x) x.begin(),x.end()
typedef long long LL;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 0x3f3f3f3f;
const ll inf_ll = 0x3f3f3f3f3f3f3f3fLL;
/************* header ******************/
const int maxn = (1 << 18) + 5;
//vector<int> E[maxn];
int n;
int x;
int ans[maxn];
int main(){
	cin>>n>>x;
	set<int> used;
	for (int i=1;i<(1 << n);i++){
		if (i == x || used.count(i) || used.count(i ^ x))continue;
		used.insert(i);
	}
	int idx = 0;
	for (int x : used){
		ans[idx++] = x;
	}
	for (int i=idx-1;i>=1;i--){
		ans[i] ^= ans[i-1];
	}
	cout<<idx<<endl;
	for (int i=0;i<idx;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
    return 0;
}