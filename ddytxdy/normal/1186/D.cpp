#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n,b[N],sum;double a[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lf",&a[i]);
	for(int i=1;i<=n;i++)b[i]=ceil(a[i]),sum+=b[i];
	for(int i=1;i<=n;i++){
		if(sum==0)break;
		if(floor(a[i])!=ceil(a[i]))b[i]=floor(a[i]),sum--;
	}
	for(int i=1;i<=n;i++)printf("%d ",b[i]);
	return 0;
}