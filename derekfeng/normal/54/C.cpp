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
typedef long double ld;
int N,M;
ll al[1003],ones[1003];
ld dp[1003][1003];
ll xx[20];
ll itoa_(ll p){
	ll k=p;
	string res="";
	while (k>0){
		res+=(k%10)+'0';
		k/=10;	
	}
	return res.size();
}
ll picks(ll a,ll b){
	ll reads=0;
	ll p=itoa_(a);
	ll q=itoa_(b);
	for (int c=p;c<=q;c++) reads+=xx[c];
	ll cil1=a-xx[p]+1;
	if (cil1>0) reads-=min(xx[p],cil1-1);
	ll cil2=b-xx[q]+1;
	if (cil2<xx[q]) reads-=xx[q]-cil2;
	return reads;
}
int main(){
	xx[1]=1;
	for (int i=2;i<20;i++) xx[i]=xx[i-1]*10;
	memset (dp,0.0,sizeof(dp));
	cin>>N;
	for (int i=1;i<=N;i++){
		ll l,r;
		cin>>l>>r;
		al[i]=r-l+1;
		ones[i]=picks(l,r);
	}
	cin>>M;
	int xp=(N*M+99)/100;
	dp[0][0]=1.0;
	for (int i=1;i<=N;i++){
		for (int j=0;j<=N;j++)
			dp[i][j+1]+=dp[i-1][j]*ld(ones[i])/ld(al[i]);
		for (int j=0;j<=N;j++)
			dp[i][j]+=dp[i-1][j]*(1.0-(ld(ones[i])/ld(al[i])));
	}
	ld ans=0.0;
	for (int i=xp;i<=N;i++)
		ans+=dp[N][i];
	printf ("%.18Lf",ans);
	return 0;
}