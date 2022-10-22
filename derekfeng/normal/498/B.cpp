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
int n,T;
double dp[5001][5001];
int p[5001],t[5001];
double quick_power(double x,int times){
	double res=1;
	while (times){
		if (times&1) res*=x;
		x*=x;
		times>>=1;
	}
	return res;
}
int main(){
	cin>>n>>T;
	dp[0][0]=1;
	for (int i=0;i<n;i++) scanf ("%d%d",&p[i],&t[i]);
	double ans=0;
	for (int i=0;i<n;i++){
		double pp=p[i]*0.01;
		double now=0;
		double r=quick_power(1-pp,t[i]-1)*pp;
		double r2=quick_power(1-pp,t[i]-1);
		for (int j=0;j<T;j++){
			now*=(1-pp);
			now+=dp[i][j]*pp;
			if (j+1>=t[i]){
				now-=dp[i][j+1-t[i]]*r;
				dp[i+1][j+1]=now+dp[i][j+1-t[i]]*r2;
			}
			else{
				dp[i+1][j+1]=now;
			}
		}
		for (int j=0;j<=T;j++) ans+=dp[i+1][j];
	}
	printf("%.12lf\n",ans);
}