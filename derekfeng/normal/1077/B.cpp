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
int n;
int a[103];
bool vis[103];
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++){
		if (a[i-1]==1 && a[i]==0 && a[i+1]==1)
			vis[i]=1;
	}
	int ans=0;
	for (int i=1;i<=n;i++){
		if (vis[i]==0) continue;
		int j;
		for (j=i+2;j<=n && vis[j]==1;j+=2);
		j-=2;
		int kk=j-i+1;
		ans+=kk/4+1;
		i=j;
	}
	cout<<ans;
	return 0;
}