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
int a[54],b[54];
int main() {
	int cnt1=0,cnt2=0,n;
	cin>>n;
	for (int i=0; i<n; i++) {
		cin>>a[i];
		cnt1+=a[i];
	}
	for (int i=0; i<n; i++) {
		cin>>b[i];
		cnt2+=b[i];
	}
	if (cnt2>cnt1) cout<<"No";
	else cout<<"Yes";
	return 0;
}