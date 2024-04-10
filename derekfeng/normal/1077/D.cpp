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
#include <windows.h>
using namespace std;
int n,k;
int p[200004];
int main(){
	cin>>n>>k;
	for (int i=0;i<n;i++){
		int x;
		cin>>x;
		p[x]++;
	}
	int l=1,r=n;
	while (r>l){
		int mid=(l+r+1)/2,rel=0;
		for (int i=0;i<200004;i++)
			rel+=p[i]/mid;
		if (rel>=k) l=mid;
		else r=mid-1;
	}
	vector <int> ans;
	for (int i=0;i<200004;i++){
		for (int j=0;j<p[i]/l;j++) ans.push_back(i);
	}
	for (int i=0;i<k;i++) cout<<ans[i]<<" ";
	return 0;
}