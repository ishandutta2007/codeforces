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
int n,k,ans=0,ans1=-1;
int p[300004],a[300004];
int main(){
	p[0]=0;
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]==1) p[i]=p[i-1]+1;
		else p[i]=p[i-1];
	}
	for (int i=1;i<=n;i++){
		int l=i,r=n;
		while (r>l){
			int mid=(l+r+1)/2;
			if ((p[mid]-p[i-1])+k>=mid-i+1) l=mid;
			else r=mid-1;
		}
		if (p[l]-p[i-1]+k>=l-i+1 && ans<l-i+1){
			ans=l-i+1;
			ans1=i;
		}
	}
	cout<<ans<<endl;
	for (int i=1;i<=n;i++){
		if (i>=ans1 && i<=ans1+ans-1) cout<<"1 ";
		else cout<<a[i]<<" ";
	}
	return 0;
}