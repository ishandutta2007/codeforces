#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	for(int i=1,x,mx=0;i<=n;i++){
		scanf("%d",&x);int val=mx+x;printf("%d ",val);mx=max(mx,val);
	}
	return 0;
}