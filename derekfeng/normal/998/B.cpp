//NOIP 2018
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
int n,b;
int a[104];
int dp[104][104];
vector <int> v[204];
int main(){
	cin>>n>>b;
	int eve=0;
	vector <int> p,ans;
	for (int i=1;i<=n;i++){ 
		cin>>a[i];
		if (a[i]%2==0)
			eve++;
		else eve--;
		if (eve==0) p.push_back(i);  
	}
	for (int i=0;i<p.size()-1;i++)
		ans.push_back(abs(a[p[i]]-a[p[i]+1])); 
	int i;
	int ko=0;
	sort (ans.begin(),ans.end());
	for (i=0;i<ans.size() && b;i++){
		b-=ans[i];
		if (b>=0) ko++;
	}
	cout<<ko;
	return 0;
}