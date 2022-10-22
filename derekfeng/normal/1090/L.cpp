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
typedef long long ll;
ll t,n,a,b,k,s1,s2;
int main(){
	cin>>t>>n>>a>>b>>k;
	s1=(n+1)/2,s2=n/2;
	a=min(a,t);
	b=min(b,t);
	while (t*k>s1*a+s2*b){
		t=(s1*a+s2*b)/k;
		a=min(a,t);
		b=min(b,t);
	}
	cout<<t;
	return 0;
}