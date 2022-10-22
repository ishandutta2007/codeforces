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
using namespace std;
int n,m,x,y;
int to_b[1003],to_w[1003];
char c[1003][1003];
int costs1[1003][1003],costs2[1003][1003];
int main(){
	for (int i=0;i<1003;i++)
		for (int j=0;j<1003;j++)
			costs1[i][j]=costs2[i][j]=1e9;
	cin>>n>>m>>x>>y;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			cin>>c[i][j];
	for (int i=1;i<=m;i++){
		to_b[i]=0,to_w[i]=n;
		for (int j=1;j<=n;j++)
			if (c[j][i]=='.') to_w[i]--,to_b[i]++;
	}
	costs1[1][1]=to_w[1];
	costs2[1][1]=to_b[1];
	for (int i=2;i<=m;i++){
		for (int j=2;j<=y;j++) if (costs1[i-1][j-1]!=1e9) costs1[i][j]=min(costs1[i][j],costs1[i-1][j-1]+to_w[i]);
		for (int j=x;j<=y;j++) if (costs2[i-1][j]!=1e9) costs1[i][1]=min(costs1[i][1],costs2[i-1][j]+to_w[i]);
		for (int j=2;j<=y;j++) if (costs2[i-1][j-1]!=1e9) costs2[i][j]=min(costs2[i][j],costs2[i-1][j-1]+to_b[i]);
		for (int j=x;j<=y;j++) if (costs1[i-1][j]!=1e9) costs2[i][1]=min(costs2[i][1],costs1[i-1][j]+to_b[i]);
	}
	int res=1e9;
	for (int i=x;i<=y;i++) res=min(res,min(costs1[m][i],costs2[m][i]));
	cout<<res;
}