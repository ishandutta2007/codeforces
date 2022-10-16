#include <iostream>
#include <cstdio>
using namespace std;
int t,n,a[100005],pos[100005],book[100005];
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)scanf("%d",&a[i]),pos[a[i]]=i;
		int fg=1;
		for (int i=1;i<=n;i++){
			int p=pos[i];
			if (book[p]==1)continue;
			book[p]=1;
			p++;
			while(p<=n&&book[p]==0){
				if (a[p]!=a[p-1]+1)fg=0;
				book[p]=1;
				p++;
			}
		}
		if (fg==1)puts("Yes");
		else puts("No");
		for (int i=1;i<=n;i++)book[i]=pos[i]=0;
	}
	return 0;
}