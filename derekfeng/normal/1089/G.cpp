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

int tests;
int t,a[8];
int cnt,days;

int func(int st){
	int res=0;
	int cur=0;
	for(int i=st;i<=7;i++){
		cur+=a[i];
		res++;
	}
	cur+=t/cnt*cnt;
	res+=t/cnt*7;
	//cout<<cur<<' '<<res<<endl;
	while(cur>t){
		cur-=cnt;
		res-=7;
	}
	//cout<<cur<<' '<<res<<endl;
	if(cur==t){
		for(int i=7;i>=1;i--){
			if(!a[i]){
				res--;
			}else{
				break;
			}
		}
	}
	//cout<<cur<<' '<<res<<endl;
	for(int i=1;cur<t;i++){
		cur+=a[i];
		res++;
	}
	return res;
}

int main(){

	cin>>tests;
	for(int time=1;time<=tests;time++){
		cnt=0;
		days=2e9;
		cin>>t;
		for(int i=1;i<=7;i++){
			cin>>a[i];
			cnt+=a[i];
		}
		for(int i=1;i<=7;i++){
			days=min(days,func(i));
		}
		cout<<days<<endl;
	}

	return 0;
}