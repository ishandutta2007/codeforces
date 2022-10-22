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
int n,dp[100005][26];
string s;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		for (int j=0;j<26;j++) if (dp[i-1][j]) dp[i][j]=1;
		cin>>s;
		int m=int(s.size());
		int k;
		int f,l,cnt1=0,cnt2=0,cnt=0;
		bool stane=0;
		for (int j=0;j<m;){
			k=j+1;
			for (;k<m && s[k]==s[k-1];k++);
			if (cnt==0){
				f=s[j]-'a';
				cnt1=k-j;
			}
			if (k==m){
				l=s[j]-'a';
				cnt2=k-j;
			}
			if (cnt==0 && k==m) stane=1;
			dp[i][s[j]-'a']=max(dp[i][s[j]-'a'],k-j);
			cnt++;
			j=k;
		}
		if (stane)
			if (dp[i-1][l])
				dp[i][l]=max(dp[i][l],dp[i-1][l]+cnt1*(dp[i-1][l]+1));
		if(l==f){
			if (dp[i-1][l])
				dp[i][l]=max(dp[i][l],1+cnt1+cnt2);
		}
		if (dp[i-1][l])
			dp[i][l]=max(dp[i][l],1+cnt2);
		if (dp[i-1][f])
			dp[i][f]=max(dp[i][f],1+cnt1);
	}
	int ans=0;
	for (int i=0;i<26;i++)
		ans=max(ans,dp[n][i]);
	cout<<ans;
}