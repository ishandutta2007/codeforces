#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[100004],p[100004],ret;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		ret=n;
		for(int i=1;i<=n;){
			int j=i+1;
			for(;j<=n&&a[j]<a[i];j++);
			for(int k=j-1;k>=i;k--)p[ret--]=a[k];
			i=j;
		}
		for(int i=1;i<=n;i++)printf("%d ",p[i]);puts("");
	}
}