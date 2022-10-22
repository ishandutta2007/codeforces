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
long long a[200003];
int main(){
	int n;
	long long m,pre=0;
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>a[i];
		long long l=a[i]+pre;
		cout<<l/m<<" ";
		pre=l%m;
	}
	return 0;
}