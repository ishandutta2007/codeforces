#include<bits/stdc++.h>
using namespace std;
const int maxn=100000;
int a[maxn],x;
bool z=0;
int main(){
	int n;
	scanf("%d",&n);
	scanf("%d",&a[1]);
	x=a[1];
	for (int i=2;i<=2*n;++i){
		scanf("%d",&a[i]);
		if (x!=a[i]) z=1;
	}
	if (z==0) printf("-1"); else {
		sort(a+1,a+1+2*n);
		for (int i=1;i<=2*n;++i)
		printf("%d ",a[i]);
	}
	return 0;
}