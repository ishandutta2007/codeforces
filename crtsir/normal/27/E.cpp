#include<bits/stdc++.h>
using namespace std;
int p[14]={2,3,5,7,11,13,17,19,23,29,31,37,41,43},n;
long long go(int n,int i){
	long long v=n>1?pow(10,18):1;
	for(int d=2;d<n+1;d++)
		if(n%d==0){
			long long tmp=pow(p[i],(d-1))*go(n/d,i+1);
			if(tmp>0)v=min(v,tmp);
		}
	return v;
}
int main(){
	cin>>n;
	cout<<go(n,0);
}