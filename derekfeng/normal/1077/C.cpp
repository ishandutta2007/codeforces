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
ll n,num[1000004];
ll a[200004],now=0; 
int main(){
	cin>>n;
	for (ll i=0;i<n;i++){
		cin>>a[i];
		num[a[i]]++;
		now+=a[i];
	}
	vector <ll> ans;
	for (ll i=0;i<n;i++){
		now-=a[i];
		num[a[i]]--;
		if (now<=2e6 && now%2==0 && num[now/2]>0){
			ans.push_back(i+1); 
		}
		now+=a[i];
		num[a[i]]++;
	}
	cout<<ans.size()<<endl;
	for (ll i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	return 0;
}