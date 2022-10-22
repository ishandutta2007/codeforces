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
string s;
long long dp[53][12];
long long a[53];
bool min1(long long n){
	for (long long i=2;i<=n;i++){
		if ((a[i-1]+a[i])/2==a[i] || (a[i-1]+a[i]+1)/2==a[i]);
		else return false;
	}
	return true;
}
int main(){
	memset (dp,0,sizeof(dp)); 
	cin>>s;
	long long n=s.size();
	for (long long i=1;i<=n;i++) a[i]=s[i-1]-'0';
	for (long long i=0;i<10;i++) dp[1][i]=1;
	for (long long i=2;i<=n;i++)
		for (long long j=0;j<10;j++){
			long long s1=j*2-1,s2=j*2,s3=j*2+1;
			long long ans1=s1-a[i],ans2=s2-a[i],ans3=s3-a[i];
			if (ans1>=0 && ans1<=9) dp[i][j]+=dp[i-1][ans1];
			if (ans2>=0 && ans2<=9) dp[i][j]+=dp[i-1][ans2];
			if (ans3>=0 && ans3<=9) dp[i][j]+=dp[i-1][ans3];
		}
	long long ans=0;
	for (long long i=0;i<10;i++) ans+=dp[n][i];
	if (min1(n)) ans--;
	cout<<ans;
	return 0;
}