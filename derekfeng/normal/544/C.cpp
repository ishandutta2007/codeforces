#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <sstream>
#include <stack>
#include <time.h>
#include <vector>
#include <complex>
#include <map>
#include <set>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <utility>
#include <memory>
#include <cstring>
#include <fstream>
#include <numeric>
#include <assert.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,b;
ll dp[503][503],ldp[503][503],mod,ans=0;
int a[503];
int main(){
	memset (dp,0,sizeof(dp));
	memset (ldp,0,sizeof(ldp));
	cin>>n>>m>>b>>mod;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++){
		dp[0][0]=1;
		for (int j=1;j<=m;j++)
			for (int k=a[i];k<=b;k++)
					dp[j][k]=(dp[j-1][k-a[i]]+dp[j][k])%mod;;
	}
	for (int i=0;i<=b;i++) ans=(ans+dp[m][i])%mod;
	cout<<ans;
}