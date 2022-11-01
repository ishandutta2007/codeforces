/******************
*  Author: BD747  *
******************/
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

set<int> t;
int a[100005];
int n,k,ans;

int main(){

	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
		if(t.find(a[i])==t.end()){
			ans++;
			if(a[i]%k==0)t.insert(a[i]/k);
		}
	}
	cout<<ans;

	return 0;
}