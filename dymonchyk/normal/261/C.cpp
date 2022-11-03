#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <ctime>

using namespace std;

int a[560][560]={0};

int build(int m,bool out = true) {
	memset(a,0,sizeof(a));
	for(int j=1;j<=m;j++)
		a[1][j]=0;
	a[1][m+1]=1;
	for(int i=2;i<=m+1;++i)
		for(int j=1;j<=m+1;++j)
			if (j==1)
				a[i][j]=a[i-1][j+1];
			else {
				if (j==m+1)
					a[i][j]=a[i-1][j-1];
				else a[i][j]=a[i-1][j-1]^a[i-1][j+1];
			}
	int ret=0;
	if (out) cout << "For:	" << m << endl;
	for(int i=1;i<=m+1;++i) {
		ret+=a[m+1][i];
		for(int j=1;j<=m+1;++j)
			if (out) cout << a[i][j] << "	";
		if (out) cout << endl;
	}
	if (out) cout << endl;
	return ret;
}

int C(int n,int k) {
	int res=0;
	for(int i=n-k+1;i<=n;++i) {
		int j=i;
		while(j%2==0) ++res,j/=2;
	}
	for(int i=1;i<=k;++i) {
		int j=i;
		while(j%2==0) --res,j/=2;
	}
	return !res;
}

int bit(int x) {
	int ret=0;
	while(x) {
		ret+=(x&1);
		x>>=1;
	}
	return ret;
}

vector <int> v;

long long dp[129][129][3];

long long check(int n,int t) {
	int ans=0;
	for(int i=1;i<=n;++i)
		if ((1<<(bit(i)-1))==t) ++ans;
//		if (build(i,false)==t) ++ans;
	return ans;
}

long long solve(long long n,long long t) {
	if (t==0) exit(-1);
/*	if (t&(t-1)) {
		return 0;
	}*/
	++n;
	v.clear();
//	memset(dp,0,sizeof(dp));
	while(n) {
		v.push_back(n%2);
		n>>=1;
	}
	reverse(v.begin(),v.end());
	dp[0][0][0]=1;
	for(int i=0;i<v.size();++i)
		for(int j=0;j<=i+1;++j)
			for(int less=0;less<2;++less) {
				for(int t=less ? 1 : v[i];t>=0;--t) {
					dp[i+1][j+t][less ? 1 : (t<v[i])]+=dp[i][j][less];
				}
			}
	int cnt=1;
	while(t>1) {
		if (t%2==1) return 0;
		t>>=1,cnt++;
	}
	return dp[v.size()][cnt][1];
}

int main() {
//	freopen("input.txt","r", stdin);
//	freopen("output.txt", "w", stdout);
	long long n,t;
	cin >> n >> t;
	cout << solve(n+1,t)-(t==1) << endl;
//	for(int i=1;i<=n;++i)
//		build(i);
/*	long long sum=0;
	for(t=1;t<=n+1;t<<=1)
		sum+=solve(n,t);
	cout << sum << endl;*/
/*	for(int n=1;n<=256;++n)
		for(int t=1;t<=n+1;t<<=1)
			if (solve(n,t)!=check(n,t)) {
				cout << n << "	" << t << "	fail\n";
				break;
			}*/
	/*int ans=0;
	for(int i=1;i<=n;++i) {
		if (build(i)==t) ++ans;
	}
	cout << ans << endl;
	for(int i=0;i<=n;++i)
		cout << C(n,i) << "	";
	cout << endl;*/
//	for(int i=1;i<=513;++i)
//		cout << i << "	" << build(i,false) << "	" << (1<<(bit(i)-1)) << endl;
	return 0;
}