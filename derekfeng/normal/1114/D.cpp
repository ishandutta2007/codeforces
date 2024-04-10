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
int n;
int c[5003]; 
int dp[5003][5003];
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>c[i];
		if (c[i]==c[i-1]){
			i--;
			n--;
		}
	}
	for (int i=0;i<5003;i++)
		for (int j=0;j<5003;j++)
			dp[i][j]=1e9;
	for (int i=n;i>=1;i--){
		dp[i][i]=0;
		for (int j=i+1;j<=n;j++){
			dp[i][j]=min(dp[i][j-1],dp[i+1][j])+1;
			if (c[i]==c[j] && j-i>1) dp[i][j]=dp[i+1][j-1]+1;
		}
	}
	cout<<dp[1][n];
}