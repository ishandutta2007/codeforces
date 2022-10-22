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
int n;
ll a[300004],ans=0,num=0;
int main(){
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
		ll x=min(num,a[i]/2);
		ans+=x;
		num-=x;
		a[i]-=x*2;
		ans+=a[i]/3;
		num+=a[i]%3;
	}
	cout<<ans;
}