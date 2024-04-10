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
int main(){
	long long n;
	int q;
	cin>>n>>q;
	while (q--){
		long long x,y;
		cin>>x>>y;
		if (n%2==0){
			long long ml=x/2;
			if (x%2==0) ml--;
			long long pl=x%2;
			if (pl==1){
				if (y%2==1) cout<<(y+1)/2+ml*n;
				else cout<<n*n/2+ml*n+y/2;
			}
			else{
				if (y%2==1) cout<<n*n/2+ml*n+(y+1)/2+n/2;
				else cout<<ml*n+y/2+(n+1)/2;
			}
		}
		else{
			long long ml=x/2;
			if (x%2==0) ml--;
			long long pl=x%2;
			if (pl==1){
				if (y%2==1) cout<<(y+1)/2+ml*n;
				else cout<<(n*n+1)/2+ml*n+y/2;
			}
			else{
				if (y%2==1) cout<<(n*n+1)/2+ml*n+(y+1)/2+n/2;
				else cout<<ml*n+y/2+(n+1)/2;
			}
		}
		cout<<endl;
	}
	return 0;
}