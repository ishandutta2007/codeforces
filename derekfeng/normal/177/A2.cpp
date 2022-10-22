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
int a[103][103];
bool vis[103][103];
int main(){
	int n,ans=0;
	cin>>n;
	for (int i=1;i<=n;i++)for (int j=1;j<=n;j++) cin>>a[i][j];
	for (int i=1;i<=n;i++)
		vis[i][(n+1)/2]=vis[(n+1)/2][i]=vis[i][i]=vis[i][n-i+1]=1;
	for (int i=1;i<=n;i++)for (int j=1;j<=n;j++)if(vis[i][j])ans+=a[i][j];
	cout<<ans;
	return 0;
}