#include<bits/stdc++.h>
using namespace std;
int n,x,s,t,f;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x),s+=x/1000;
		if(x==1000)f=1;
	}
	t=s*10/11;
	if(s<=11)t=s-x/1000;
	if(!f&&(t&1))t--;
	printf("%d",s*1000-t*100);
}