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
int t[100004],l[100004];
int main(){
	int n,L,a;
	cin>>n>>L>>a;
	for (int i=0;i<n;i++)	
		cin>>t[i]>>l[i];
	vector <int> v;
	v.push_back(0); 
	for (int i=0;i<n;i++){
		v.push_back(t[i]);
		v.push_back(t[i]+l[i]);
	}
	int ans=0;
	v.push_back(L);
	for (int i=0;i<v.size();i+=2){
		ans+=(v[i+1]-v[i])/a;
	} 
	cout<<ans;
	return 0;
}