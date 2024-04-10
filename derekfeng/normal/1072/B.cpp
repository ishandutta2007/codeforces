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
int n,a[200004],b[200004],p[200004];
int r_ans[4][200004]; 
int main(){
	cin>>n;
	n--;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++){
		cin>>b[i];
		p[i]=b[i]+a[i];
	}
	r_ans[0][0]=0;
	r_ans[1][0]=1;
	r_ans[2][0]=2;
	r_ans[3][0]=3;
	for (int i=1;i<=n;i++){
		r_ans[0][i]=p[i]-r_ans[0][i-1];
		r_ans[1][i]=p[i]-r_ans[1][i-1];
		r_ans[2][i]=p[i]-r_ans[2][i-1];
		r_ans[3][i]=p[i]-r_ans[3][i-1];
	}
	for (int i=0;i<4;i++){
		bool q=1;
		for (int j=1;j<=n;j++){
			if ((r_ans[i][j]|r_ans[i][j-1])==a[j] && (r_ans[i][j]&r_ans[i][j-1])==b[j]);
			else{
				q=0;
				break;
			}
		}
		if (q){
			puts("YES");
			for (int j=0;j<=n;j++)
				cout<<r_ans[i][j]<<" ";
			return 0;
		}
	}
	puts("NO");
	return 0;
}