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
ll b[100004],ans[200004];
int main(){
	int n;
	cin>>n>>b[1];
	ans[1]=0,ans[n]=b[1];
	for (int i=2;i<=n/2;i++){
		cin>>b[i]; 
		if (b[i]==b[i-1]){
			ans[i]=ans[i-1];
			ans[n-i+1]=ans[n-i+2];
		}
		if (b[i]<b[i-1]){
			ans[i]=ans[i-1];
			ans[n-i+1]=ans[n-i+2]-(b[i-1]-b[i]);
		}
		if (b[i]>b[i-1]){
			ans[i]=ans[i-1]+(b[i]-b[i-1]);
			ans[n-i+1]=ans[n-i+2];
		}
	}
	for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
	return 0;
}