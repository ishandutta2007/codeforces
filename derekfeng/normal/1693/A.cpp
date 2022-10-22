#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,a[200004];
void sol(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	while(n&&a[n]==0)n--;
	if(n==0){puts("Yes");return;}
	ll s=0;
	for(int i=n;i;i--){
		ll A=-s+a[i];
		if(A>=0&&i>1){puts("No");return;}
		if(A!=0&&i==1){puts("No");return;}
		s=-A;
	}
	puts("Yes");
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}