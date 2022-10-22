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
int n,m;
char c[1003][1003],g[1003][1003];
int main(){
	int n,m;
	cin>>n>>m;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			cin>>c[i][j];
	for (int i=1;i<n-1;i++)
		for (int j=1;j<m-1;j++)
			if (c[i-1][j-1]=='#' && c[i+1][j+1]=='#' &&
				c[i+1][j-1]=='#' && c[i-1][j+1]=='#' &&
				c[i-1][j]=='#' && c[i+1][j]=='#' &&
				c[i][j+1]=='#' && c[i][j-1]=='#')
					g[i-1][j-1]='#',g[i+1][j+1]='#',g[i+1][j-1]='#',g[i-1][j+1]='#',g[i-1][j]='#',g[i+1][j]='#',g[i][j+1]='#',g[i][j-1]='#';
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			if (c[i][j]=='#' && c[i][j]!=g[i][j]){
				cout<<"NO";
				return 0;
			}
	cout<<"YES";
	return 0;
}