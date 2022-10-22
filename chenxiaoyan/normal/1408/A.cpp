/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
void mian(){
	int n;
	cin>>n;
	vector<int> a(n+1),b(n+1),c(n+1),ans(n+1);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	for(int i=1;i<=n;i++){
		if(i==1)ans[i]=a[i];
		else if(i<n)ans[i]=a[i]==ans[i-1]?b[i]:a[i];
		else ans[i]=a[i]==ans[i-1]||a[i]==ans[1]?b[i]==ans[i-1]||b[i]==ans[1]?c[i]:b[i]:a[i];
		printf("%d ",ans[i]);
	}
	puts("");
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}