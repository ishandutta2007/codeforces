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
int main(){
	int n,m;
	ll k,a[200004];
	cin>>n>>m>>k;
	for (int i=0;i<n;i++)
		cin>>a[i];
	int l=n-1;
	while (m>0 && l>=0){
		ll K=k;
		while (l>=0 && K-a[l]>=0){
			K-=a[l];
			l--;
		}
		m--;
	}
	cout<<n-l-1;
	return 0;
}