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
int dp[5003][5003],q;
string s;
int main(){
	cin>>s;
	s='*'+s;
	int n=s.size()-1;
	for (int k=1;k<=n;k++)
		for (int i=1;i+k-1<=n;i++){
			int j=i+k-1;
			if (k==1) dp[i][j]=1;
			if (k==2 && s[i]==s[j]) dp[i][j]=1;
			if (k>2 && s[i]==s[j] && dp[i+1][j-1]) dp[i][j]=1;
		}
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			dp[i][j]+=dp[i][j-1];
	for (int i=n-1;i>=1;i--)
		for (int j=i+1;j<=n;j++)
			dp[i][j]+=dp[i+1][j];
	cin>>q;
	while (q--){
		int x,y;
		scanf ("%d%d",&x,&y);
		cout<<dp[x][y]<<"\n";
	}
}