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
int n,m,qub=0;
char c[503][503];
int a[503],a1[503],b[503],b1[503],num[2][503],cnt=0;
int main(){
	for (int i=0;i<503;i++) a[i]=1e9,b[i]=1e9;
	cin>>n>>m;
	for (int i=0;i<n;i++) cin>>c[i];
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++) if (c[i][j]=='*'){
			num[0][i]++;
			a[i]=min(a[i],j);
			a1[i]=max(a1[i],j);
		}
		if(num[0][i]>2) cnt++;
		if(num[0][i]==2){
			cout<<"NO";
			return 0;
		}
		qub+=num[0][i];
	}
	if (cnt!=1){
		cout<<"NO";
		return 0;
	}
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++) if (c[j][i]=='*'){
			num[1][i]++;
			b[i]=min(b[i],j);
			b1[i]=max(b1[i],j);
		}
		if (num[1][i]>2) cnt++;
		if (num[1][i]==2){
			cout<<"NO";return 0;
		}
	}
	if (cnt!=2){
		cout<<"NO";
		return 0;
	}
	for (int i=0;i<n;i++) if (num[0][i]>2){
		for (int j=0;j<m;j++) if (num[1][j]>2){
			if (a1[i]-a[i]+1==num[0][i] && b1[j]-b[j]+1==num[1][j] && qub==num[0][i]+num[1][j]-1 && b1[j]>i && a1[i]>j)  cout<<"YES";
			else cout<<"NO";
			return 0;
		}
	}
}