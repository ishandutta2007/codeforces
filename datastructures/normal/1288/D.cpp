#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m,a[300005][10],book[305],ans1,ans2;
inline bool check(int x){
	memset(book,0,sizeof(book));
	for (int i=1;i<=n;i++){
		int s=0;
		for (int j=1;j<=m;j++){
			if (a[i][j]>=x)s+=(1<<(j-1));
		}
		book[s]=i;
	}
	for (int i=0;i<=(1<<m);i++)
		for (int j=0;j<=(1<<m);j++){
			if (book[i]==0||book[j]==0)continue;
			if ((i|j)==(1<<m)-1){
				ans1=book[i],ans2=book[j];
				return 1;
			}
		}
	return 0;
}
int main(){
//	freopen("1288D.in","r",stdin);
//	freopen("1288D.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	int l=0,r=1000000000;
	while(l<=r){
		int mid=(l+r)/2;
		if (check(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<ans1<<' '<<ans2<<endl;
	return 0;
}