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
#include <windows.h> 
using namespace std;
int n,b,ans=0;
int a[2003];
int main(){
	cin>>n>>b;
	for (int i=0;i<n;i++){
		cin>>a[i];
		if (i==0) continue;
		if (a[i]>a[i-1]) continue;
		ans+=(a[i-1]-a[i])/b+1; 
		a[i]+=((a[i-1]-a[i])/b+1)*b;
	}
	cout<<ans;
	return 0;
}