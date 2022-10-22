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
int n,q,a[200004];
multiset <int> st;
vector <int> ans; 
int i_will_become_0(int x){
	if (x==0) return 0;
	return n-x;
}
multiset <int>::iterator t;
int main(){
	cin>>n;
	for (int i=0;i<n;i++) scanf ("%d",a+i);
	for (int i=0;i<n;i++){
		int x;
		scanf ("%d",&x);
		st.insert(x);
	}
	for (int i=0;i<n;i++){
		int x=i_will_become_0(a[i]);
		t=st.lower_bound(x);
		if (t!=st.end()){
			int l=*t;
			ans.push_back((a[i]+l)%n);
			st.erase(t); 
		}else{
			int l=*st.begin();
			ans.push_back((a[i]+l)%n); 
			st.erase(st.begin()); 
		}
	}
	for (int i=0;i<ans.size();i++) printf("%d ",ans[i]);
}