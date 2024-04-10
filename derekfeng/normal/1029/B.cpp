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
int a[200005];
int n;
int ans[2000005];
int main(){
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
		if (i==0){
			ans[i]=1;
			continue;
		}
		if (a[i]<=a[i-1]*2) ans[i]=ans[i-1]+1;
		else ans[i]=1;
	}
	int res=1;
	for (int i=0;i<n;i++)
		res=max(res,ans[i]);
	cout<<res;
	return 0;
}