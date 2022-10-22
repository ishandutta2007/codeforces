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
int main(){
	ll a[12][12];
	memset (a,0,sizeof(a));
	ll n;
	cin>>n;
	for (ll i=1;i<=n;i++) a[1][i]=1;
	for (ll i=2;i<=n;i++)
		for (ll j=1;j<=n;j++) 
			a[i][j]=a[i][j-1]+a[i-1][j];
	cout<<a[n][n];
}