#include <bits/stdc++.h>
using namespace std;
int a[13];
bool f(int n){
	if(n<=10) return 1;
	int k=0;
	while(n)
	{
		k++;
		a[k]=n%10;
		n/=10;
	}
	for(int i=1; i<=k; i++) for(int j=i+1; j<=k; j++) if(a[i]==a[j]) return 0;
	return 1;
}
int main() {
	int l,r;
	scanf("%d%d",&l,&r);
	for(int i=l; i<=r; i++) if(f(i)) return 0&printf("%d",i);
	printf("-1");
	return 0;
}
//QAQQAQQAQ