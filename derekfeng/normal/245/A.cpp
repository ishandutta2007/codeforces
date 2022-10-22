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
int c[3],num[3];
int main(){
	int n;
	cin>>n;
	while (n--){
		int t,a,b;
		cin>>t>>a>>b;
		num[t]++;
		c[t]+=a;
	}
	if (num[1]*5<=c[1]) puts("LIVE");
	else puts("DEAD");
	if (num[2]*5<=c[2]) puts("LIVE");
	else puts("DEAD");
}