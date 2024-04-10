#include<bits/stdc++.h>
using namespace std;
int T,n,m;
void sol(){
	scanf("%d%d",&n,&m);
	if(n>m)swap(n,m);
	if(n==1){
		if(m>1)puts("1");
		else puts("0");
	}else puts("2");
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}