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
int n,k,lst=0;
long long ans=0;
vector<int>v;
int main(){
	cin>>n>>k;
	int o;cin>>o;lst=o;
	for (int i=1;i<n;i++){
		int x;cin>>x;v.push_back(x-lst); 
		ans+=x-lst;lst=x;
	} 
	sort (v.begin(),v.end());
	for (int i=v.size()-1,j=0;j<k-1;i--,j++) ans-=v[i];
	cout<<ans;
}