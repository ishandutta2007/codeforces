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
#include <numeric>
#include <memory>
#include <cstring> 
#include <fstream>
#include <assert.h>
#include <bitset>
#include <ios> 
#include <bits/stdc++.h>
using namespace std;
char s[703];
typedef long long ll;
const ll MOD=1e9+7;
ll dp[703][703][3][3],ans=0;
int num[703];
void solve(int l,int r){
	if (r==l+1){
		dp[l][r][0][1]=1;
		dp[l][r][0][2]=1;
		dp[l][r][1][0]=1;
		dp[l][r][2][0]=1;
		return;
	}
	if (num[l]==r){
		solve(l+1,r-1);
		for (int i=0;i<3;i++)for(int j=0;j<3;j++){
			for(int k=0;k<3;k++)for(int q=0;q<3;q++){
			if ((i>0 && j>0)||(i==0 && j==0))continue;
			if (i>0 && i==k) continue;
			if (j>0 && j==q) continue;
			dp[l][r][i][j]+=dp[l+1][r-1][k][q];
			}
			dp[l][r][i][j]%=MOD; 
		}		
		return;
	}
	solve(l,num[l]);solve(num[l]+1,r);
	for (int i=0;i<3;i++)for(int j=0;j<3;j++)for(int k=0;k<3;k++)for(int q=0;q<3;q++){
		if (k>0 && k==q) continue;
		dp[l][r][i][j]=(dp[l][r][i][j]+dp[l][num[l]][i][k]*dp[num[l]+1][r][j][q]%MOD)%MOD;
	}
}
int main(){
	scanf ("%s",s);
	vector <int> v;
	for (int i=0;i<strlen(s);i++){
		if (s[i]=='(') v.push_back(i);
		else{ 
			num[v[v.size()-1]]=i;
			v.pop_back();
		}
	}
	solve(0,strlen(s)-1);
	for (int i=0;i<3;i++)for(int j=0;j<3;j++) ans+=dp[0][strlen(s)-1][i][j];
	cout<<ans%MOD;
}