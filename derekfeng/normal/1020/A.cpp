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
int n,h,a,b,k;
int main(){
	cin>>n>>h>>a>>b>>k;
	while (k--){
		int t1,f1,t2,f2;
		cin>>t1>>f1>>t2>>f2;
		if (t1==t2){cout<<abs(f1-f2)<<endl;continue;}
		int ans,br;
		if (f1<a) ans=a-f1,br=a;
		else if (f1>b) ans=f1-b,br=b;
		else ans=0,br=f1;
		ans+=abs(t1-t2);
		cout<<ans+abs(br-f2)<<endl;
	}
	return 0;
}