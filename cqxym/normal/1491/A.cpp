#include<iostream>
using namespace std;
#define R register int
int a[100000];
int main(){
	int n,q,x,k,ct=0;
	cin>>n>>q;
	for(R i=0;i!=n;i++){
		cin>>a[i];
		if(a[i]==0){
			ct++;
		}
	}
	for(R i=0;i!=q;i++){
		cin>>x>>k;
		if(x==1){
			k--;
			if(a[k]==0){
				ct--;
			}else{
				ct++;
			}
			a[k]^=1;
		}else if(n-ct>=k){
			puts("1");
		}else{
			puts("0");
		}
	}
	return 0;
}