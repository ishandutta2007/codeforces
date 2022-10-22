#include<bits/stdc++.h>
using namespace std;
int n,a[500005],l[500005],r[500005],f[500005],cnt[500005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(!l[a[i]])l[a[i]]=i;
	}
	for(int i=n;i;i--)if(!r[a[i]])r[a[i]]=i;
	for(int i=n;i;i--){
		cnt[a[i]]++;
		if(l[a[i]]==i)f[i]=f[r[a[i]]+1]+cnt[a[i]];
		else f[i]=cnt[a[i]];
		f[i]=max(f[i],f[i+1]);
	}
	printf("%d",n-f[1]);
}