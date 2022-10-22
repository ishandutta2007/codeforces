//I am a little huhaoyuan,he is a big fool!!!!!!!!!!!!
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
#define mp make_pair
typedef pair<int,int> ii;
int n,m,res[5005],pre[5005];
vector <pair<ii,int> > v;
int out(int x){
	if (x==-1) return 0;
	out (pre[x]);
	cout<<v[x].second+1<<" ";
	return 0;
}
int main(){
	int n,w,h;
	cin>>n>>w>>h;
	for (int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		if (a>w && b>h) v.push_back(mp(mp(a,b),i));
	}
	sort (v.begin(),v.end());
	int ans=0,ai=-1;
	for (int i=0;i<v.size();i++){
		res[i]=1;
		pre[i]=-1;
		for (int j=0;j<i;j++)
			if (v[j].first.first<v[i].first.first && v[j].first.second<v[i].first.second && res[i]<res[j]+1){
				res[i]=res[j]+1;
				pre[i]=j;
			}
		if (res[i]>ans){
			ans=res[i];
			ai=i;
		}
	}
	cout<<ans<<endl;
	out(ai);
	return 0;
}