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
int n;int a[100004],ans[100004];
int main(){
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	sort (a,a+n);
	if (a[n-1]>=a[n-2]+a[n-3]){
		cout<<"NO";
		return 0;
	}
	cout<<"YES\n";
	vector <int> cnt[2];
	int i=n-2,j=n-3;
	for (;i>=0;i-=2) cnt[0].push_back(a[i]); 
	for (;j>=0;j-=2) cnt[1].push_back(a[j]);
	reverse (cnt[0].begin(),cnt[0].end()); 
	for (i=0;i<cnt[0].size();i++) cout<<cnt[0][i]<<" ";
	cout<<a[n-1]<<" ";
	for (i=0;i<cnt[1].size();i++) cout<<cnt[1][i]<<" "; 
}