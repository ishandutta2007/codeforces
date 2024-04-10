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
#include <bitset>
#include <ios> 
#include <bits/stdc++.h>
using namespace std;
int n,k;string s;
int tw[2][1000004];
typedef long long ll;
const ll MOD=1e9+7; 
ll dp[1000004][3][2];
int main(){
	cin>>n>>k>>s;
	s="0"+s;
	for (int i=1;i<=n;i++){
		tw[0][i]=tw[0][i-1];
		tw[1][i]=tw[1][i-1];
		if (s[i]=='W') tw[1][i]++;
		if (s[i]=='B') tw[0][i]++;
	}
	if (k==1){
		if (s[1]=='X'){
			dp[1][1][0]=1;
			dp[1][0][1]=1;
		}
		if (s[1]=='B') dp[1][1][0]=1;
		if (s[1]=='W') dp[1][0][1]=1;
	}else{
		if(s[1]=='X'){
			dp[1][0][1]=1;
			dp[1][0][0]=1;
		}
		if (s[1]=='B') dp[1][0][0]=1;
		if (s[1]=='W') dp[1][0][1]=1;
		if (tw[1][k]==0) dp[k][1][0]=1;
	}
	for (int i=2;i<=n;i++){
		if (s[i]=='X'){
			if (i+k-1<=n && tw[1][i+k-1]-tw[1][i-1]==0){
				if (k!=1)dp[i+k-1][1][0]=dp[i-1][0][1];
				else dp[i+k-1][1][0]=dp[i-1][0][0]+dp[i-1][0][1];
			}
			if (i+k-1<=n && tw[0][i+k-1]-tw[0][i-1]==0){
				if (k!=1)dp[i+k-1][2][1]=dp[i-1][1][0];
				else dp[i+k-1][2][1]=dp[i-1][1][1]+dp[i-1][1][0];
			}
			dp[i][0][0]=(dp[i-1][0][0]+dp[i-1][0][1]-dp[i][1][0]+MOD)%MOD;
			dp[i][0][1]=(dp[i-1][0][0]+dp[i-1][0][1])%MOD;
			dp[i][1][0]=(dp[i][1][0]+dp[i-1][1][0]+dp[i-1][1][1])%MOD;
			dp[i][1][1]=(dp[i-1][1][0]+dp[i-1][1][1]-dp[i][2][1]+MOD)%MOD;
			dp[i][2][0]=(dp[i-1][2][0]+dp[i-1][2][1])%MOD;
			dp[i][2][1]=(dp[i][2][1]+dp[i-1][2][0]+dp[i-1][2][1])%MOD;
		}
		if (s[i]=='W'){
			if (i+k-1<=n && tw[0][i+k-1]-tw[0][i-1]==0){
				if (k!=1)dp[i+k-1][2][1]=dp[i-1][1][0];
				else dp[i+k-1][2][1]=dp[i-1][1][1]+dp[i-1][1][0];
			}
			dp[i][0][1]=(dp[i-1][0][0]+dp[i-1][0][1])%MOD;
			dp[i][1][1]=(dp[i-1][1][0]+dp[i-1][1][1]-dp[i][2][1]+MOD)%MOD;
			dp[i][2][1]=(dp[i][2][1]+dp[i-1][2][0]+dp[i-1][2][1])%MOD;
		}
		if (s[i]=='B'){
			if (i+k-1<=n && tw[1][i+k-1]-tw[1][i-1]==0){
				if (k!=1)dp[i+k-1][1][0]=dp[i-1][0][1];
				else dp[i+k-1][1][0]=dp[i-1][0][0]+dp[i-1][0][1];
			}
			dp[i][0][0]=(dp[i-1][0][0]+dp[i-1][0][1]-dp[i][1][0]+MOD)%MOD;
			dp[i][1][0]=(dp[i][1][0]+dp[i-1][1][0]+dp[i-1][1][1])%MOD;
			dp[i][2][0]=(dp[i-1][2][0]+dp[i-1][2][1])%MOD;
		}
	}
	cout<<(dp[n][2][0]+dp[n][2][1])%MOD;
}