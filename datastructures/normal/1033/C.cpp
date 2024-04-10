#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,a[100005],pos[100005],ans[100005];
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]),pos[a[i]]=i;
	for (int i=n;i>=1;i--){
		int p=pos[i];
		for (int j=i;j<=n;j+=i){
			if (p-j>=1&&a[p-j]>i&&ans[p-j]==0)ans[p]=1;
			if (p+j<=n&&a[p+j]>i&&ans[p+j]==0)ans[p]=1;
		}
	}
	for (int i=1;i<=n;i++)
		if (ans[i]==1)putchar('A');
		else putchar('B');
	puts("");
	return 0;
}