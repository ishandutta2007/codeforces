#include<bits/stdc++.h>
using namespace std;
int t,n,k,dat,dat2;bool flag;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		if(k%3!=0)puts(n%3==0?"Bob":"Alice");
		else puts(n%(k+1)%3==0&&n%(k+1)!=k?"Bob":"Alice");
	}
	return 0;
}