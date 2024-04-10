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
int n,k,c[100004],ans; 
int main(){
	cin>>n>>k;
	for (int i=0;i<n;i++) cin>>c[i];
	for (int i=0;i<n;){
		int res=1,j;
		for (j=i+1;j<n && c[j]!=c[j-1];j++) res++;
		ans=max(res,ans);
		i=j;
	}
	cout<<ans;
	return 0;
}