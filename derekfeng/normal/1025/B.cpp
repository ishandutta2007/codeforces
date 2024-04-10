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
typedef pair<int,int> pii;
int n;
vector <int> ans;
int l[150003],r[150003];
bool prime(int x){
	if (x==1) return false;
	for (int i=2;i*i<=x;i++)
		if (x%i==0) return false;
	return true;
}
int main(){
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>l[i]>>r[i];
	}
	for (int i=1;i*i<=max(l[0],r[0]);i++){
		vector <int> v;
		if (l[0]%i==0){
			if (prime(i)){
				v.push_back(i);
			}
			if (prime(l[0]/i)){
				v.push_back(l[0]/i);
			}
		}
		if(r[0]%i==0){
			if (prime(i)){
				v.push_back(i);
			}
			if (prime(r[0]/i)){
				v.push_back(r[0]/i);
			}
		}
		sort (v.begin(),v.end());
		for (int i=0;i<v.size();i++)
			if (i==0 || v[i-1]!=v[i])
				ans.push_back(v[i]);
	}
	if (n==1){
		cout<<l[0];
		return 0;
	}
	for (int i=0;i<ans.size();i++){
		bool q=1;
		for (int j=1;j<n;j++){
			if (l[j]%ans[i]==0 || r[j]%ans[i]==0);
			else{
				q=0;
				break;
			}
		}
		if (!q) continue;
		else{
			cout<<ans[i];
			return 0;
		}
	}
	cout<<"-1";
	return 0;
}