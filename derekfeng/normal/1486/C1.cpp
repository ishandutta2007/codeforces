#include <bits/stdc++.h>
using namespace std;
int ask(int l,int r){
	fflush(stdout);
	int res;
	printf("? %d %d\n",l,r);
	cin>>res;
	fflush(stdout);
	return res;
}
int n,A;
int main(){
	cin>>n;
	A=ask(1,n);
	if(A>1&&ask(1,A)==A){
		int l=0,r=A;
		while(r>l+1){
			int mid=(l+r)/2;
			if(ask(mid,A)==A)l=mid;
			else r=mid;
		}
		printf("! %d",l);
	}else{
		int l=A,r=n+1;
		while(r>l+1){
			int mid=(l+r)/2;
			if(ask(A,mid)==A)r=mid;
			else l=mid;
		}
		printf("! %d",r);
	}
}