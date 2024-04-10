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
typedef pair<ll,int> pli;
vector <pli> v;
ll a[200004];
bool vis[200004];
int n,m,k;
bool cmp(pli a,pli b){
	return a.first>b.first;
}
ll ans=0;
int main(){
	memset (vis,0,sizeof(vis));
	cin>>n>>m>>k;
	for (int i=0;i<n;i++){
		cin>>a[i];
		v.push_back(pli(a[i],i));
	}
	sort (v.begin(),v.end(),cmp);
	for (int i=0;i<k*m;i++){
		vis[v[i].second]=1;
		ans+=v[i].first;
	}
	cout<<ans<<endl;
	int num=0;
	int xx=0;
	for (int i=0;i<n;){
		xx++;
		int j=i;
		for (;j<n;j++) if (vis[j]){
			num++;
			if (num==m) break;
		}
		if (xx!=k && num) cout<<j+1<<endl;
		i=j+1;
		num=0;
	}
}