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
bool holidays[368];
int dp[368];
int main(){
	int N,K,C;
	cin>>N>>K>>C;
	for (int i=0;i<C;i++){
		int x;
		cin>>x;
		holidays[x]=1;
	}
	dp[0]=0;
	for (int i=1;i<=N;i++){
		for (int k=1;k<=K;k++){
			if (i-k<0) break;
			if (holidays[i-k]){
				dp[i]=dp[i-k]+1;
				break; 
			}
			else{
				dp[i]=dp[i-k]+1;
			}
		}
	}
	if (holidays[N]){
		cout<<dp[N];
		return 0;
	}
	for (int i=N,j=1;j<K;i--,j++)
		if (holidays[i]){
			cout<<dp[i];
			return 0;
		}
	cout<<dp[N-K+1];
	return 0;
}