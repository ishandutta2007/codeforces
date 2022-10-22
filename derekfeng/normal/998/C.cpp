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
int n,x,y,cnt=0;
long long ans=1e18;
char c[300004]; 
int main(){
	cin>>n>>x>>y>>c;
	for (int i=0;i<n;i++){
		if (c[i]=='0')
			if (i==0 || c[i-1]!='0') cnt++;
	}
	for (int i=0;i<cnt;i++){
		long long num=1ll*i*x+1ll*(cnt-i)*y;
		ans=min(ans,num);
	}
	if (cnt==0) cout<<0;
	else cout<<ans;
	return 0;
}