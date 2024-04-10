#include<bits/stdc++.h>
using namespace std;

const int N=1005000;
int p[N],c,phi[N],v[N];

void init(){
	for(int i=2;i<N;i++){
		if(!v[i])phi[i]=i-1,p[++c]=i;
		for(int j=1;i*p[j]<N;j++){
			phi[i*p[j]]=phi[i]*p[j];
			v[i*p[j]]=1;
			if(i%p[j]==0)break;
			phi[i*p[j]]=phi[i]*(p[j]-1);
		}
	}
} 

int main(){
	ios::sync_with_stdio(false);
	int n,k;cin>>n>>k;
	if(k==1)cout<<3,exit(0);
	init();
	sort(phi+3,phi+1+n);
	long long ans=0;
	for(int i=3;i<3+k;i++)
		ans+=phi[i];
	cout<<ans+2<<endl;
}