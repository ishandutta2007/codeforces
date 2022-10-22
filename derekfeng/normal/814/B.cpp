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
int n; 
int a[1004],b[1004];
vector <int> v;
void record0(){
	bool vis[1004];
	int f,s;
	for (int i=0;i<n;i++){
		if (vis[a[i]]) f=a[i];
		vis[a[i]]=1;
	}
	for (int i=1;i<=n;i++)
		if (!vis[i]) s=i;
	bool q=0;
	for (int i=0;i<n;i++){
		if (a[i]!=f || q) cout<<a[i]<<" ";
		else{
			cout<<s<<" ";
			q=1;
		}
	}
	return;
}
void record1(int xp){
	bool vis[1004];
	memset (vis,0,sizeof(vis));
	for (int i=0;i<n;i++){
		if (xp!=i) vis[a[i]]=1;
	}
	int ca;
	for (int i=1;i<=n;i++){
		if (!vis[i]){
			ca=i;
		}
	}
	for (int i=0;i<n;i++){
		if (xp==i) cout<<ca<<" ";
		else cout<< a[i]<<" ";
	}
	return;
}
void record2(int c,int d){
	bool vis[1004];
    memset (vis,0,sizeof(vis));
	for (int i=0;i<n;i++)
		if (i!=c && i!=d) vis[a[i]]=1;
	vector <int> r;
	for (int i=1;i<=n;i++)
		if (!vis[i])
			r.push_back(i);
	if (r[0]==a[c] && r[1]==b[d]){
		for (int i=0;i<n;i++){
			if (i==d) cout<<b[d]<<" ";
			else cout<<a[i]<<" "; 
		}
		return;
	}
	if (r[0]==a[d] && r[1]==b[c]){
		for (int i=0;i<n;i++){
			if (i==c) cout<<b[c]<<" ";
			else cout<<a[i]<<" ";
		}
		return;
	}
	if (r[1]==a[c] && r[0]==b[d]){
		for (int i=0;i<n;i++){
			if (i==d) cout<<b[d]<<" ";
			else cout<<a[i]<<" ";
		}
		return;
	}
	if (r[1]==a[d] && r[0]==b[c]){
		for (int i=0;i<n;i++){
			if (i==c) cout<<b[c]<<" ";
			else cout<<a[i]<<" ";
		}
		return;
	}
}
int main(){
	cin>>n;
	vector <int> v; 
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n;i++) cin>>b[i];
	for (int i=0;i<n;i++)
		if (a[i]!=b[i]) v.push_back(i);
	if (v.size()==0){
		record0();
	}
	if (v.size()==1){
		record1(v[0]);
	}
	if (v.size()==2){
		record2(v[0],v[1]);
	}
	return 0;
}