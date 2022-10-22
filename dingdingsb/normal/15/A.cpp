#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int n,t;
struct node{
	float st,ed;
	bool operator<(const node b)const{
		return st!=b.st?st<b.st:ed<b.ed;
	}
}A[1200];
int x,a,ans=0;
signed main(){
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x,&a);
		A[i].st=x-1.0*a/2;
		A[i].ed=A[i].st+a;
	}
	sort(A+1,A+1+n);
	for(int i=2;i<=n;i++){
		if(A[i].st-A[i-1].ed>t)
			ans+=2;
		else if(A[i].st-A[i-1].ed==t)
			ans+=1;
	}
	cout<<ans+2;
}