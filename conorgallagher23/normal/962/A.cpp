#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+5;
int n,a[N],totw;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),totw+=a[i];
	for(int i=1,s=0;i<=n;i++)if(((s+=a[i])<<1)>=totw){printf("%d\n",i);return 0;}
	return 0;
}