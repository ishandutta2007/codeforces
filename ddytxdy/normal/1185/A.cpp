#include<bits/stdc++.h>
using namespace std;
int a[4],d,ans;
int main(){
	scanf("%d%d%d%d",&a[1],&a[2],&a[3],&d);
	sort(a+1,a+3+1);
	if(a[2]-a[1]<d)ans+=d-(a[2]-a[1]);
	if(a[3]-a[2]<d)ans+=d-(a[3]-a[2]);
	printf("%d",ans);
	return 0;
}