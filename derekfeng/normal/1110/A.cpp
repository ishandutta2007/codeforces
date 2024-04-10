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
long long b,k,n=0,mod=2;
long long d[100004];
string ans[2]={"even","odd"};
int main(){
	cin>>b>>k;
	d[0]=1;
	for (long long i=1;i<100004;i++) d[i]=d[i-1]*b%2;
	while (k--){
		long long x;
		cin>>x;
		n=(n+d[k]*x)%2;
	}
	cout<<ans[n%2];
}