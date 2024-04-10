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
int a[200004];
string ans;
int main(){
	int n,now=0;
	cin>>n; 
	for (int i=0;i<n;i++) cin>>a[i];
	int l=0,r=n-1;
	while (1){
		if (l>r || max(a[r],a[l])<=now) break;
		int minn=min(a[l],a[r]),maxx=max(a[l],a[r]);
		if (minn>now){
			now=minn;
			if (minn==a[r]) r--,ans+="R";
			else l++,ans+="L";
		}else{
			now=maxx;
			if (maxx==a[r]) r--,ans+="R";
			else l++,ans+="L";
		}
	}
	cout<<ans.size()<<"\n"<<ans;
}