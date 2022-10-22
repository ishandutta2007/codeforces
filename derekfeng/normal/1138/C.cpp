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
int n,m;
int a[1003][1003];
int c_max[1003],r_max[1003];
int c_num[1003][1003],r_num[1003][1003];
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for (int i=1;i<=n;i++){
		int cnt=0;
		vector <pair<int,int> > v;
		for (int j=1;j<=m;j++)
			v.push_back(make_pair(a[i][j],j)); 
		sort (v.begin(),v.end());
		for (int j=1;j<=m;j++){
			int qq=j-1;
			if (qq==0 || v[qq].first!=v[qq-1].first) cnt++;
			r_num[i][v[qq].second]=cnt;
			if (j==m) r_max[i]=cnt;
		}
	}
	for (int i=1;i<=m;i++){
		int cnt=0;
		vector <pair<int,
		int> > v;
		for (int j=1;j<=n;j++)
			v.push_back(make_pair(a[j][i],j)); 
		sort (v.begin(),v.end());
		for (int j=1;j<=n;j++){
			int qq=j-1;
			if (qq==0 || v[qq].first!=v[qq-1].first) cnt++;
			c_num[v[qq].second][i]=cnt;
			if (j==n) c_max[i]=cnt;
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			int d1=r_num[i][j],d2=c_num[i][j];
			int max1=r_max[i],max2=c_max[j],min1=1;
			max1+=(d2-d1),min1+=(d2-d1);
			cout<<max(max1,max2)-min(min1,1)+1<<" ";
			if (j==m) puts("");
		}
}