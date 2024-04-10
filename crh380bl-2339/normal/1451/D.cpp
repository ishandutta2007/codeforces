#include<bits/stdc++.h>
using namespace std;
bool bo[200005];
int main(){
	int T;
	long long d,k,x,y,x1;
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&d,&k);
		x=(long long)sqrt((double)d*d/2.0);
		x/=k;x*=k;
		y=(long long)sqrt((double)(d*d-x*x));
		y/=k;x/=k;
		if((y-x)&1LL)puts("Ashish");
		else puts("Utkarsh");
	}
	return 0;
}