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
long long ans0=0,ans1=0;
int n;
int a[2][100005];
long long ans[2][100005];
int main(){
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[0][i];
	for (int i=0;i<n;i++) cin>>a[1][i];
	ans[0][n-1]=a[0][n-1];
	ans[1][n-1]=a[1][n-1];
	for (int i=n-2;i>=0;i--)for(int j=0;j<2;j++){
		ans[j][i]=ans[j][i+1];
		ans[j][i]=max(ans[j][i],ans[j^1][i+1]+a[j][i]);
	}
	cout<<max(ans[0][0],ans[1][0]);
}