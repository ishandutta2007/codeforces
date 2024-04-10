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
int g[104],n,d[104],a[104],i;
int Find(int x){return x==g[x]?g[x]:g[x]=Find(g[x]);}
void union_(int x,int y){g[Find(x)]=Find(y);}
int main(){
	cin>>n;
	for (i=1;i<=n;i++){
		cin>>a[i];
		g[i]=i;
	}
	for (i=1;i<=n;i++){
		cin>>d[i];
		if (i+d[i]<=n) union_(i,i+d[i]);
		if (i-d[i]>0) union_(i,i-d[i]);
	}
	for (i=1;i<=n;i++) if (Find(i)==i){
		int c[105];
		memset (c,0,sizeof(c));
		int j;
		for (j=1;j<=n;j++) if (Find(j)==i) c[j]++,c[a[j]]--;
		for (j=1;j<=n;j++) if(c[j]) break;
		if (j<=n) break;
	}
	if (i>n)puts("YES");
	else puts("NO");
}