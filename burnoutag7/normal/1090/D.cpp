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
bool d[503][100005];
int ans[100005];
int main(){
	cin>>n>>m;
	if (n<2){
		cout<<"NO";
		return 0;
	}
	while (m--){
		int x,y;
		cin>>x>>y;
		if (x>y) swap(x,y);
		if (x<=502)d[x][y]=1;
	}
	int a=-1,b=-1;
	for (int i=1;i<=min(n,500);i++)
		for (int j=i+1;j<=n;j++){
			if (!d[i][j]){
				a=i,b=j;
			}
		}
	if (a==-1,b==-1){
		cout<<"NO";
		return 0;
	}
	a--,b--;
	int ld=3;
	int pu=1;
	for (int i=0;i<n;i++){
		if (i!=a && i!=b){
			ans[i]=ld++;
		}
		else{
			ans[i]=pu++; 
		}
	}
	cout<<"YES\n";
	for (int i=0;i<n;i++) cout<<ans[i]<<" ";
	cout<<endl;
	for (int i=0;i<n;i++){
		if (i!=b) cout<<ans[i]<<" ";
		else cout<<"1 "; 
	}
	return 0;
}