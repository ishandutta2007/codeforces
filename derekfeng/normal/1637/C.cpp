#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,a[200004];
ll ans;
void sol(){
	scanf("%d",&n);ans=0;
	bool notone=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(1<i&&i<n){
			ans+=(a[i]+1)/2;
			notone|=(a[i]!=1);
		}
	}
	if(!notone||(n==3&&a[2]%2==1))puts("-1");
	else printf("%lld\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)sol();
}