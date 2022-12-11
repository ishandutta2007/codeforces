#include<bits/stdc++.h>
#define LL long long
using namespace std;
int t;LL n,k,num;
int main(){
	scanf("%d",&t);
	while(t--){
		cin>>n>>k;num=0;
		while(n){
			if(n%k==0)n/=k,num++;
			else num+=n%k,n-=n%k;
		}
		cout<<num<<endl;
	}
	return 0;
}