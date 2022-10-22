// xzy
//tourist... 
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
int n,m,q;
int a[44][44];
char c[44][44];
int f[44][44];
int cnt[44][44][44][44];
int main(){ 
	cin>>n>>m>>q;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			cin>>c[i][j];
			a[i][j]=(c[i][j]=='1');
		}
	for (int i=0;i<=n;i++)
		for (int j=0;j<=m;j++){
			if (i==0 || j==0) f[i][j]=0;
			else f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+a[i][j];// 
		}
	for (int xa=1;xa<=n;xa++)
		for (int ya=1;ya<=m;ya++/**/)
			for (int xb=xa;xb<=n;xb++)
				for (int yb=ya;yb<=m;yb++){
					int sum=f[xb][yb]-f[xa-1][yb]-f[xb][ya-1]+f[xa-1][ya-1];
					cnt[xa][ya][xb][yb]=(sum==0);// 
				}
	for (int xa=n;xa>=2;xa--)
		for (int ya=1;ya<=m;ya++)
			for (int xb=xa;xb<=n;xb++/**/)
				for (int yb=ya;yb<=m;yb++){ 
					cnt[xa-1][ya][xb][yb]+=cnt[xa][ya][xb][yb];// 
				}
	for (int xa=1;xa<=n;xa++)
		for (int ya=m;ya>=2;/**/ya--)
			for (int xb=xa;xb<=n;xb++)
				for (int yb=ya;yb<=m;yb++){
					cnt[xa][ya-1][xb][yb]+=cnt[xa][ya][xb][yb];// 
				}
	for (int xa=1;xa<=n;xa++)
		for (int ya=1;ya<=m;ya++)
			for (int xb=xa;xb<=n;xb++/**/)
				for (int yb=ya;yb<=m;yb++){
					cnt[xa][ya][xb+1][yb]+=cnt[xa][ya][xb][yb];//
				}
	for (int xa=1;xa<=n;xa++/**/)
		for (int ya=1;ya<=m;ya++)
			for (int xb=xa;xb<=n;xb++)
				for (int yb=ya;yb<=m;yb++) 
					cnt[xa][ya][xb][yb+1]+=cnt[xa][ya][xb][yb];
	while (q--){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		cout<<cnt[a][b][c][d]<<endl;
		//LOL WORLD CUP
	}
	return 0;
}