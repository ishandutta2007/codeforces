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
bool cmp(int a,int b){
	return a>b;
}
int a[52];
int main(){
	int n,k,ans=0;
	cin>>n>>k;
	for (int i=0;i<n;i++)
		cin>>a[i];
	sort (a,a+n,cmp);
	for (int i=0;i<n;i++){
		if (a[i]>=a[k-1] && a[i]!=0) ans++;
		else break;
	}
	cout<<ans;
	return 0;
}