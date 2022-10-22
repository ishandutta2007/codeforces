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
int main(){
	int n;
	int a[3];
	cin>>n>>a[0]>>a[1]>>a[2];
	sort (a,a+3);
	int ans=0;
	for (int i=0;a[2]*i<=n;i++)
		for (int j=0;a[1]*j<=n-a[2]*i;j++)
			if ((n-a[2]*i-a[1]*j)%a[0]==0)
				ans=max(ans,i+j+(n-a[2]*i-a[1]*j)/a[0]);
	cout<<ans;
	return 0;
}