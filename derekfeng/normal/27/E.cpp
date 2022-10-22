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
int n;
long long ans=1e18;
int primes[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
void dfs(int pos,long long cur,int d,int pr){
	long long cur2=cur;
	if (d==n){
		ans=min(ans,cur);
		return;
	}
	for (int i=1;i<=pr;i++){
		if (cur2>ans/primes[pos]) break;
		cur2*=primes[pos];
		if (n%(d*(i+1))==0) dfs(pos+1,cur2,d*(i+1),i);
	}
}
int main(){
	cin>>n;
	dfs(0,1,1,100);
	cout<<ans;
	return 0;
}