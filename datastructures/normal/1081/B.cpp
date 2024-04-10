#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int n,a[1000005];
vector<int> pos[1000005];
int tot,ans[1000005];
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]=n-a[i];
		pos[a[i]].push_back(i);
	}
	for (int i=1;i<=n;i++){
		int len=pos[i].size();
		if (len%i!=0){
			puts("Impossible");
			return 0;
		}
		for (int j=0;j<len;j++)ans[pos[i][j]]=tot+j/i+1;
		tot+=len/i;
	}
	puts("Possible");
	for (int i=1;i<=n;i++)printf("%d ",ans[i]);
	printf("\n");
	return 0;
}