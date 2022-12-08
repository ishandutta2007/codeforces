#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
int n,tot;
int a[maxn];
int main(){
	/*freopen(".in","r",stdin);
	freopen(".out","w",stdout);*/
	scanf("%d",&n);
	for (int i=2;i<=n;++i){
		if (a[i]) continue;
		++tot;
		for (int j=i;j<=n;j+=i){
			if (a[j]) continue;
			a[j]=tot;
		}
	}
	for (int i=2;i<=n;++i)	
	printf("%d ",a[i]);
}