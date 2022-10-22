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
const ll MOD=998244353;
ll n,ans=0;
ll num1[1000003],num2[1000003];
int main(){
	cin>>n;
	num1[0]=1;
	num2[n+1]=1;
	for (ll i=1;i<=n;i++)
		num1[i]=num1[i-1]*i%MOD;
	for (ll i=n;i>=1;i--)
		num2[i]=num2[i+1]*i%MOD;
	for (ll i=1;i<=n-1;i++)
		ans=(ans+num2[n-i+1]*(num1[n-i]-1))%MOD;
	ans=(ans+num1[n])%MOD;
	cout<<ans;
}