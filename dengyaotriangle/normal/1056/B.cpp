#include<bits/stdc++.h>
using namespace std;

const int maxm=1005;

long long n,m;
long long cnt[maxm];
long long ans;
long long c0[maxm];

int main(){
	cin>>n>>m;
	long long lft=n%m;
	long long bas=n/m;
	if(lft==0){
		for(int i=0;i<m;i++) c0[i]=bas;
	}else{
		c0[0]=bas;
		for(int i=1;i<=lft;i++) c0[i]=bas+1;
		for(int i=lft+1;i<m;i++) c0[i]=bas;
	}
	for(int i=0;i<m;i++){
		cnt[(i*i)%m]+=c0[i];
	}
	ans+=cnt[0]*cnt[0];
	for(int i=1;i<m;i++){
		ans+=cnt[i]*cnt[m-i];
	}
	cout<<ans;
	return 0;
}