#include<bits/stdc++.h>
using namespace std;
int a,b,c,n,d;
int main(){
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int ans=0;
	if (a>b) swap(a,b);
	if (b>c) swap(a,b);
	if (a>c) swap(a,c);
	if (a>b) swap(a,b);
	if (b>c) swap(a,b);
	if (a>c) swap(a,c);
	if (a>b) swap(a,b);
	if (b>c) swap(a,b);
	if (a>c) swap(a,c);
	if (a>b) swap(a,b);
	if (b>c) swap(a,b);
	if (a>c) swap(a,c);
	
	if (b-a<d) ans+=d-(b-a);
	if (c-b<d) ans+=d-(c-b);
	printf("%d",ans);
	return 0;
}