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
long long n,k;
int main(){
	cin>>n>>k;
	long long l=0,r=n+1;
	while (r>l+1){
		long long mid=(l+r)/2;
		if (mid*(mid+1)/2-(n-mid)>=k) r=mid;
		else l=mid;
	}
	cout<<n-r;
}