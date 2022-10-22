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
ll n,a[200004]; 
ll ans=0;
int main(){
	cin>>n;
	for (ll i=1;i<=n;i++)
		cin>>a[i];
	for (ll i=1;i<=n;){
		ans++;
		ll j=i;
		while (j<=n && a[j]==-1) j++;
		ll k=j+1;
		while (k<=n && a[k]==-1) k++;
		ll now=(a[k]-a[j])/(k-j);
		if (k>n||(a[k]-a[j])%(k-j)!=0 || a[j]-(j-i)*now<=0){
			i=k;
			continue;
		}
		ll l=k+1;
		while (l<=n && (((l-j)*now+a[j]==a[l] && a[l]!=-1) || ((l-j)*now+a[j]>0 && a[l]==-1))) l++;
		i=l; 
	}  
	cout<<ans;
	return 0;
}