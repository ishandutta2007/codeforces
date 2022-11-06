#include<bits/stdc++.h>
using namespace std;
int main(){
	int r,b,d,x;
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&r,&b,&d);
		if(r<b)swap(r,b);
		x=(r+b-1)/b;
		if(x-1>d)puts("NO");
		else puts("YES");
	}
	return 0;
}