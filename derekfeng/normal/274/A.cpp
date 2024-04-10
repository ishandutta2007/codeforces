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
int n,ans=0;
ll k;
ll a[100004];
set <ll> minion;
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	sort (a,a+n);
	for(int i=n-1;i>=0;i--)
		if (minion.find(a[i])==minion.end()){
			ans++;
			if (a[i]%k==0) minion.insert(a[i]/k); 
		}
	cout<<ans;
	return 0;
}