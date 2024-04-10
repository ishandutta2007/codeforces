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
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
typedef long long ll;
#define MOD 1000000007ll
int N;
vector <int> graph[100010];
ll dp0[100010],dp1[100010];
int color[100010];
int main(void){
	int i,j;
	cin>>N;
	REP(i,N-1){
		int p;
		scanf ("%d",&p);
		graph[p].push_back(i+1);
	}
	REP(i,N) scanf ("%d",&color[i]);
	for (i=N-1;i>=0;i--){
		ll zero=0,one=0;
		if (color[i]==0) zero++;else one++;
		REP(j,graph[i].size()){
			int v=graph[i][j];
			ll zero2=(zero*dp1[v]+zero*dp0[v])%MOD;
			ll one2=(one*dp1[v]+zero*dp1[v]+one*dp0[v])%MOD;
			zero=zero2;
			one=one2;
		}
		dp0[i]=zero;
		dp1[i]=one;
	}
	cout<<dp1[0]<<endl;
}