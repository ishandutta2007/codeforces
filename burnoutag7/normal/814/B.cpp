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

int a[1005],b[1005],p[1005];
int n;
int cnt;
bool u[1005];

bool check(){
	int difa=0,difb=0;
	for(int i=1;i<=n;i++){
		difa+=(a[i]!=p[i]);
	}
	for(int i=1;i<=n;i++){
		difb+=(b[i]!=p[i]);
	}
	if(difa==1 && difb==1){
		return true;
	}else{
		return false;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i]){
			continue;
		}else{
			u[a[i]]=true;
			p[i]=a[i];
		}
	}
	vector<int> faq;
	for(int i=1;i<=n;i++){
		if(p[i]==0){
			faq.push_back(i);
			for(int j=1;j<=n;j++){
				if(!u[j]){
					u[j]=1;
					p[i]=j;
					break;
				}
			}
		}
	}
	if(!check()){
		int t=p[faq[0]];
		p[faq[0]]=p[faq[1]];
		p[faq[1]]=t;
	}
	for(int i=1;i<=n;i++){
		cout<<p[i]<<' ';
	}
	
	return 0;
}