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
string s;int k,n;
int dp[103][103][27];
int cnt[26][26];
int main(){
	for (int i=0;i<103;i++) for (int j=0;j<103;j++) for (int k=0;k<27;k++) dp[i][j][k]=-1e8;
	cin>>s>>k>>n;
	s="0"+s;
	while(n--){
		char a,b;cin>>a>>b;
		cin>>cnt[a-'a'][b-'a'];
	}
	for (int i=0;i<26;i++){
		if (i+'a'!=s[1]) dp[1][1][i]=0;
		else dp[1][0][i]=0;
	}
	for (int i=2;i<s.size();i++) for (int j=0;j<=k;j++) for (int l=0;l<26;l++)for(int q=0;q<26;q++){
		if (s[i]!=l+'a'){
			if (j<k)dp[i][j+1][l]=max(dp[i][j+1][l],dp[i-1][j][q]+cnt[q][l]);
		}
		else dp[i][j][l]=max(dp[i][j][l],dp[i-1][j][q]+cnt[q][l]);
	}
	int res=-1e8;
	for (int i=0;i<=k;i++) for (int j=0;j<26;j++)
		res=max(res,dp[s.size()-1][i][j]);
	cout<<res;
}