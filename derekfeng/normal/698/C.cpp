#include<bits/stdc++.h>
using namespace std;
typedef double db;
const db EPS=1e-9;
db f[1048676],a[22],ans[22];
int n,k,nn;
int main(){
	cin>>n>>k;nn=n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]<EPS)nn--;
	}
	if(nn<k){
		for(int i=0;i<n;i++)
			if(a[i]>EPS)cout<<"1 ";
			else cout<<"0 ";
		return 0;
	}
	f[0]=1;
	for(int i=0;i<(1<<n);i++){
		int tmp=__builtin_popcount(i);
		if(tmp>=k)continue;
		db all=0;
		for(int j=0;j<n;j++)if(!((1<<j)&i))all+=a[j];
		if(all<EPS)continue;
		for(int j=0;j<n;j++)if(!((1<<j)&i))
			f[i|(1<<j)]+=f[i]*a[j]/all;
	}
	for(int i=0;i<(1<<n);i++)if(__builtin_popcount(i)==k)
		for(int j=0;j<n;j++)if((1<<j)&i)ans[j]+=f[i];
	for(int i=0;i<n;i++)printf("%.6lf ",ans[i]);
}