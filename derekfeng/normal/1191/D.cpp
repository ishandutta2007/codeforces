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
int n;
int a[100004]; 
void fiwin(){
	puts("sjfnb");
	exit(0);
}
void sewin(){
	puts("cslnb");
	exit(0);
}
typedef long long ll;
ll wt,z=1;
int cnt=0,pv;
int main(){ 
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	sort (a,a+n);
	if (n==1){
		if (a[0]%2==0) sewin(); 
		else fiwin();
	}
	for (int i=n-2;i>=0;i--){
		if (a[i]==a[i+1] && ((i!=0 && a[i]==a[i-1]+1)||a[i]==0)) sewin();
		if (a[i]==a[i+1]) cnt++,pv=i;
	}
	if (cnt>1) sewin();
	if (cnt==1) wt++,a[pv]--;
	for (int i=n-2;i>=0;i--){
		wt+=z*(a[i+1]-a[i]-1);
		z++;
	}
	wt+=n*a[0];
	if (wt%2==0) sewin();
	else fiwin();
}