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
	int n,ans; 
	cin>>n;
	ans=n/100;
	int res=1e9;
	n%=100;
	for (int i=0;i<=n/20;i++)
		for (int j=0;j<=n/10;j++)
			for (int k=0;k<=n/5;k++)
				for (int l=0;l<=n;l++){
					if (i*20+j*10+k*5+l==n) res=min(ans+i+j+k+l,res);
				}
	cout<<res;
	return 0;
}