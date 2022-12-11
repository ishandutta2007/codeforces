#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n,m,ans,a[N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1,j=n/2+1;i<=n/2&&j<=n;){
		if(a[j]-a[i]>=m)i++,j++,ans++;
		else j++;
	}
	printf("%d",ans);
}