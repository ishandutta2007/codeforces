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
int n,h;
vector <int> v;
int main(){
	cin>>n>>h;
	for (int i=0;i<n;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	for (int i=n;i>=0;i--){
		bool stane=1;
		int ans=0;
		vector <int> q;
		for (int j=i-1;j>=0;j--) q.push_back(v[j]);
		if (q.size()%2==1) q.push_back(0); 
		sort (q.begin(),q.end());
		for (int i=0;i<q.size() && stane;i+=2){
			ans+=q[i+1];
			if (ans>h) stane=0;
		}
		if (stane){
			cout<<i;
			return 0;
		}
	}
}