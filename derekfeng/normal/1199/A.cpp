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
int n,x,y;
int a[100004];
int main(){
	cin>>n>>x>>y;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	for (int i=0;i<n;i++){
		bool ok=1;
		for (int j=i-1,k=0;j>=0&&k<x;j--,k++)if(a[j]<a[i])ok=0;
		for (int j=i+1,k=0;j<n&&k<y;j++,k++) if(a[j]<a[i])ok=0;
		if (ok){
			cout<<i+1;return 0;
		}
	}
}