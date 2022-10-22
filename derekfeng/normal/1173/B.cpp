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
int main(){
	int n;
	cin>>n;
	int now=1,now2=1;
	int a=1,b=0,ans=0;
	vector <int> ans1,ans2;
	for (int i=1;i<=n;i++){
		ans=max(now,ans);
		ans=max(now,ans);
		ans1.push_back(now),ans2.push_back(now2);
		now+=a,now2+=b;
		swap(a,b);
	}
	cout<<ans<<"\n";
	for (int i=0;i<n;i++) cout<<ans1[i]<<" "<<ans2[i]<<"\n";
}