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
int a[103]; 
int main(){
	int n;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	sort (a,a+n);
	int ans=0;
	for (int i=0;i<n-1;i++) ans+=a[n-1]-a[i];
	cout<<ans;
	return 0;
}