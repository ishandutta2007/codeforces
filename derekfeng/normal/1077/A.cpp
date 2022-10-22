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
#include <windows.h>
using namespace std;
typedef long long ll;
int main(){
	int t;
	cin>>t;
	while (t--){
		ll a,b,n;
		cin>>a>>b>>n;
		if (n%2==0) cout<<n/2*(a-b);
		else cout<<n/2*(a-b)+a;
		puts("");
	}
	return 0;
}