/******************
*  Author: BD747  *
******************/
#include<bits/stdc++.h>
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
#include<windows.h>
#include<time.h>
#include<conio.h>
using namespace std;

long long n;
long long v[100005];
long long t[100005];
long long qz[100005];
long long m[100005];
long long mqz[100005];
long long lft[100005];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>v[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>t[i];
		qz[i]=qz[i-1]+t[i];
	}
	for(long long i=1;i<=n;i++){
		long long gay=upper_bound(qz+i,qz+n+1,v[i]+qz[i-1])-qz;//cout<<gay<<endl;
		m[gay]--;m[i]++;
		lft[gay]+=v[i]-qz[gay-1]+qz[i-1];
	}
	for(long long i=1;i<=n;i++){
		mqz[i]=mqz[i-1]+m[i];
		//cout<<mqz[i]<<' ';
	}//cout<<endl;
	for(long long i=1;i<=n;i++){
		cout<<mqz[i]*t[i]+lft[i]<<' ';
	}

	return 0;
}