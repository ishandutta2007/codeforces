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
int l[200005],pl,num=0;
int a[200005],now=2e5,ans;
int main(){
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (!l[a[i]]) l[a[i]]=i;
	}
	for (int i=1;i<=n;i++) if (i!=1 && a[i]<=a[i-1]) break;else num++;
	pl=n+1,ans=num;
	now=num;
	for (int i=n;i>=1;i--){
		if (i!=n && a[i]<=a[i+1]) break;
		now=min(now,l[a[i]]-1);
		if(now+n-i+1>ans){
			ans=now+n-i+1;
			pl=i;
		}
	}
	cout<<ans<<endl;
	vector <pair<int,int> > v;
	for (int i=n;i>=pl;i--) v.push_back(make_pair(a[i],1));
	for (int i=1;i<=ans-(n-pl+1);i++) v.push_back(make_pair(a[i],0)); 
	sort (v.begin(),v.end());
	for (int i=0;i<v.size();i++) if (v[i].second==0) cout<<"L";else cout<<"R";
}