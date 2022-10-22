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
int n,m;
int main(){
	cin>>n>>m;
	m=240-m;
	int ans=0;
	int p=0;
	for (int i=1;i<=n;i++){
		p+=i;
		if (p*5<=m) ans=i;
		else break;
	}
	cout<<ans;
	return 0;
}