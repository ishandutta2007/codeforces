#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n;
double a[maxn];
int b[maxn],c[maxn],d[maxn];
int num1,num2;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%lf",&a[i]); 
		b[i]=floor(a[i]); num1+=b[i];
		c[i]=ceil(a[i]); num2+=c[i];
		if (b[i]==c[i]) d[i]=0; else d[i]=1;
	}
	int now=0; int zz;
	for (int i=1;i<=n;++i){
		printf("%d\n",c[i]);
		now+=d[i];
		if (now==abs(num1)){
			zz=i+1;
			break;
		}
	}
	for (int i=zz;i<=n;++i)
	printf("%d\n",b[i]);
}