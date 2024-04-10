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
int n,k;
multiset <ll> s;
int main(){
	scanf ("%d%d",&n,&k);
	for (int i=0;i<k;i++)
		s.insert(0);
	for (int i=0;i<n;i++){
		ll a,b;
		scanf ("%lld%lld",&a,&b);
		ll v=*s.begin();
		s.erase(s.begin());
		v=max(a,v);
		printf ("%lld\n",v+b);
		s.insert(v+b);  
	}
	return 0;
}