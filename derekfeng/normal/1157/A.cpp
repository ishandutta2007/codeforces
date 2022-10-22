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
long long n;
map <long long,int> mp;
long long f(long long x){
	long long p=x;
	p++;
	while (p%10==0) p/=10;
	return p;
}
void dfs(long long x){
	long long tmd=f(x); 
	if (mp[tmd]) return;
	mp[tmd]++;
	dfs(tmd);
}
int main(){
	cin>>n;
	mp[n]++;
	dfs(n);
	cout<<mp.size();
}