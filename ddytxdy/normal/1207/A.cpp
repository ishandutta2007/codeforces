#include<bits/stdc++.h>
using namespace std;
int t,a,b,c,n,m;
void solve(){
	scanf("%d%d%d%d%d",&a,&b,&c,&n,&m);
	if(a>=(b+c)*2){printf("%d\n",n*b+m*c);return;}
	if(n<m)swap(n,m),swap(b,c);
	if(a<b*2){printf("%d\n",a/2*n);return;}
	printf("%d\n",n*b+(a-b*2)/2*m);
}
int main(){
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}