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
int n,ans=0,ls=-1; 
int d[20][20],a[103];
int main(){
	d[1][2]=3;
	d[2][1]=3;
	d[3][1]=4;
	d[1][3]=4;
	cin>>n;
	bool t=1;
	for (int i=0;i<n && t;i++){
		cin>>a[i];
		if (i==0 || a[i-1]+a[i]!=5) ans+=d[a[i-1]][a[i]];
		else t=0;
		if (i>1 && a[i-2]==3 && a[i-1]==1 && a[i]==2) ans--;
		//if (i>1 && a[i-2]==2 && a[i-1]==1 && a[i]==3) ans-=2; 
	}
	if (!t) return !printf("Infinite");
	else puts("Finite");
	cout<<ans; 
}