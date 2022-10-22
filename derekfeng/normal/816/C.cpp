//QQQQQQQQQQQQQQQQQQQQQQQQQQQ 
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
int a[103][103]; 
int col[103];
int row[103];
bool okay(){
	for (int i=0;i<m;i++){
		int now=a[0][i]-row[0];
		if (now<0) return false;
		for (int j=1;j<n;j++)
		if (a[j][i]-row[j]!=now) return false;
		col[i]=now;
	}
	return true;
}
int main(){
	int r=1e9,c=1e9;
	vector <int> rv,cv;
	cin>>n>>m;
	int maxn=1e9;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			cin>>a[i][j];
	for (int i=0;i<n;i++)
		maxn=min(maxn,a[i][0]);
	for (int i=0;i<=maxn;i++){
		bool q=1;
		for (int j=0;j<n;j++){
			row[j]=a[j][0]-i;
			if (row[j]<0){
				q=0;
				break;
			}
		}
		if (!q) continue;
		if (okay()){
			vector <int> n1,n2;
			for (int j=0;j<n;j++){
				for (int k=0;k<row[j];k++)
					n1.push_back(j);
			}
			for (int j=0;j<m;j++){
				for (int k=0;k<col[j];k++)
					n2.push_back(j);
			}
			if (n1.size()+n2.size()<r+c){
				r=n1.size(),c=n2.size();
				rv=n1,cv=n2;
			}
		}
	}
	if (r==1e9) cout<<"-1";
	else{
		cout<<c+r<<endl;
		for (int i=0;i<rv.size();i++)
			cout<<"row "<<rv[i]+1<<endl;
		for (int j=0;j<cv.size();j++)
			cout<<"col "<<cv[j]+1<<endl;
	}
	return 0;
}