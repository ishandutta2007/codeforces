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
typedef long long ll;
using namespace std;
ll n,m;
int main(){
	cin>>n>>m;
	ll sil=m*2;
	cout<<max(1ll*0,n-sil)<<" ";
	ll i;
	for (i=0;i*(i+1)/2<m;i++);
	if (i!=0) i++;
	cout<<n-i;
	return 0;
}