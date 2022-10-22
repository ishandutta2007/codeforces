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
int n,m;
int a[103];
int main(){
	cin>>n>>m;
	for (int i=0;i<n;i++)
		cin>>a[i];
	sort (a,a+n);
	int ans=0;
	for (int i=0;i<n;i++){
		if (i==m) break;
		if (a[i]>=0) break;
		ans+=-a[i];
	}
	cout<<ans;
	return 0;
}