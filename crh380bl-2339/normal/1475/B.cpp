#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n,x,y;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		x=n/2020;
		y=n%2020;
		if(x>=y)puts("YES");
		else puts("NO");
	}
	return 0;
}