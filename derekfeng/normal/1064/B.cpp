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
long long n;
int main(){
	int t;
	cin>>t;
	while (t--){
	cin>>n;
	int res=0;
	while (n){
		if (n%2==1) res++; 
		n>>=1;
	}
	cout<<(1<<res)<<"\n";
	}
	return 0;
}