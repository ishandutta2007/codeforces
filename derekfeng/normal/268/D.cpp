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
#define MOD 1000000009
int H,S;
vector <int> state[10000];
map <vector<int>,int> mp;
int trans[10000][4];
int dp[1010][10000];
int get_state(vector<int>v){
	if (mp.find(v)!=mp.end()) return mp[v];
	state[S]=v;mp[v]=S;S++;
	return S-1;
}
void func(int id){
	int i,j;
	REP(i,4){
		vector <int> w=state[id];
		REP(j,4){
			if (j==i) w[j]=((w[j]==H)?H:0);
			else w[j]=min(w[j]+1,H);
		}
		sort (w.begin(),w.end());
		trans[id][i]=get_state(w);
	}
}
int	main(){
	int N,i,j,k;
	cin>>N>>H;
	vector <int> init;
	REP(i,4) init.push_back(0);
	get_state(init);
	int pos=0;
	while (pos<S){
		func(pos);
		pos++;
	}
	dp[0][0]=1;
	REP(i,N) REP(j,S) REP(k,4){
		int j2=trans[j][k];
		dp[i+1][j2]+=dp[i][j];
		if (dp[i+1][j2]>=MOD) dp[i+1][j2]-=MOD;
	}
	int ans=0;
	REP(i,S){
		bool good=false;
		REP(j,4) if (state[i][j]!=H) good=true;
		if (good){
			ans+=dp[N][i];
			if (ans>=MOD) ans-=MOD;
		}
	}
	cout<<ans<<endl;
	return 0;
}