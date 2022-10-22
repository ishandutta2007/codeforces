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
typedef long long ll;
int lst[26],n,k; 
const ll MOD=1e9+7;
ll dp[2000005];
string s;
vector <pair<int,int> > v;
int main(){
	memset (lst,-1,sizeof(lst));
	cin>>n>>k>>s;
	for (int i=0;i<s.size();i++) lst[s[i]-'a']=i;
	for (int i=0;i<k;i++) v.push_back(make_pair(lst[i],i)); 
	sort (v.begin(),v.end());
	for (int j=0;j<n;j++)
		s+=v[j%k].second+'a';
	memset (lst,-1,sizeof(lst));
	dp[0]=1;
	for (int i=1;i<=s.size();i++){
		dp[i]=(dp[i-1]*2-(lst[s[i-1]-'a']==-1?0:dp[lst[s[i-1]-'a']-1])+MOD)%MOD;
		lst[s[i-1]-'a']=i;
	}
	cout<<dp[s.size()];
}