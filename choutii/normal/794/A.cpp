#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,i,j,k;
int main(){
	scanf("%d%d%d",&a,&b,&c);
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&j);
		if(j>b&&j<c)k++;
	}
	cout<<k;
}