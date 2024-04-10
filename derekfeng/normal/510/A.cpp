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
char c[60][60];
int n,m; 
int main(){ 
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			c[i][j]='.';
	for (int i=1;i<=n;i+=2)
		for (int j=1;j<=m;j++)
		 c[i][j]='#';
	for (int i=2;i<n;i+=2){
		if (i/2%2==1)
			c[i][m]='#';
		else
			c[i][1]='#';
	}
	for (int i=1;i<=n;i++){ 
		for (int j=1;j<=m;j++) cout<<c[i][j];
		cout<<endl;
	}
	return 0;
}