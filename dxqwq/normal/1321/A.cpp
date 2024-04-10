#include<bits/stdc++.h>
using namespace std;
int n,a[100003],b[100003]; 
int main()
{
	int n,k=0,l=0;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	for(int i=1; i<=n; i++) scanf("%d",&b[i]);
	for(int i=1; i<=n; i++) if(!a[i]) if(!b[i]) continue; else k++; else if(b[i]) continue; else l++;
	if(!l) return 0&printf("-1");
	if(!k) return 0&printf("1");
	printf("%d",k/l+1);
	return 0;
}