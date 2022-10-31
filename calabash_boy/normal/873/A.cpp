#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
int a[maxn];
int n,k,x;
int ans;
int main(){
	scanf("%d%d%d",&n,&k,&x);
	for (int i=0;i<n;i++){
		scanf("%d",a+i);
	}
	for (int i=0;i<n-k;i++){
		ans+=a[i];
	}
	for (int i=n-k;i<n;i++){
		ans+=x;
	}
	cout<<ans<<endl;
	return 0;
}