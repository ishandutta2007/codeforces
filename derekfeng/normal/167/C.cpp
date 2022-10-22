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
typedef long long ll; 
bool ok(ll a,ll b){
	if (a==0 || b==0) return 0;
	if (a>b) swap(a,b);
	if (!ok(a,b%a)) return 1;
	ll N=b/a;
	ll M=a+1;
	return ((N%M)%2==0);
}
ll A,B;
int main(){
	int t;cin>>t;
	while (t--){
		cin>>A>>B;
		bool yes=ok(A,B);
		if (yes) puts("First");
		else puts("Second");
	}
}