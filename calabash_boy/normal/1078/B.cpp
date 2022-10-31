// Created by calabash_boy on 18-10-18.
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
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 0x3f3f3f3f;
const ll inf_ll = 0x3f3f3f3f3f3f3f3fLL;
/************* header ******************/
typedef long long ll;
const int maxn = 105;
int a[maxn];
int dp[2][maxn][maxn*maxn];
int cnt[maxn];
inline void add(int &x,int y){
	if (x >=2)return;
	x += y;
}
int main(){
	untie;
	int n;
	cin>>n;
	int co = 0;
	int Sum = 0;
	for (int i=1;i<=n;i++)cin>>a[i];
	for (int i=1;i<=n;i++)cnt[a[i]]++;
	dp[0][0][0]=1;
	int tot = 0;
	int now = 0;
	for (int i=1;i<=100;i++,now ^=1){
		if(cnt[i])co++;
		memset(dp[now^1],0,sizeof dp[now^1]);
		//Sum+= i * cnt[i];
		//tot += cnt[i];
		for (int x = 0;x <= cnt[i];x++)
		for (int j=i*x;j<=10000;j++){
			for (int k=x;k<=n;k++)
			add(dp[now^1][k][j],dp[now][k-x][j-x*i]);
		}
	//	for (int k=0;k<=n;k++)for (int j=0;j<=10000;j++){
	//		add(dp[i][k][j],dp[i-1][k][j]);
	//	}
	}
	if (co == 1){
		cout<<n<<endl;
		return 0;
	}
	for (int i=1;i<=n;i++)for (int j=1;j<=10000;j++){
		if (dp[100][i][j]){
		//	_debug("dp[%d][%d][%d]=%d",n-1,i,j,dp[100][i][j]);
		}
	}
	int ans =0;
	for (int i=1;i<=100;i++){
		if (cnt[i] == 0)continue;
		for (int j=1;j<=cnt[i];j++){
			int sum = i *j;
			if (dp[now][j][sum] == 1)ans = max(ans,j);
		}
		for (int j=1;j<=cnt[i];j++){
			int sum = Sum - i * j;
			if (dp[now][n-j][sum] == 1)ans = max(ans,j);
		}
	}
	if (co == 2){
		for (int i=1;i<=100;i++){
			if (cnt[i] == ans && ans != 0){
				ans = n;
				break;
			}	
		}
	}
	cout<<ans<<endl;
    return 0;
}