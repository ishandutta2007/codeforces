#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[5];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int i,y,x;
		for(i=1;i<=4;++i)scanf("%d",a+i);
		x=max(a[1],a[2]);y=max(a[3],a[4]);
		sort(a+1,a+1+4);
		if((x==a[4]&&y==a[3])||(x==a[3]&&y==a[4]))puts("YES");
		else puts("NO");
	} 
	return 0;
}