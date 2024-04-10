#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,a[1000005],book[1000005],cover[1000005],ans1,ans2;
int main(){
//	freopen("1283E.in","r",stdin);
//	freopen("1283.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		book[a[i]]++;
	}
	for (int i=1;i<=n;i++){
		if (book[i]==0)continue;
		if (book[i]==1){
			if (cover[i-1]==0)cover[i-1]=1,ans1++;
			else if (cover[i]==0)cover[i]=1,ans1++;
			else if (cover[i+1]==0)cover[i+1]=1,ans1++;
		}
		if (book[i]==2){
			int tot=0;
			if (tot<2&&cover[i-1]==0)cover[i-1]=1,ans1++,tot++;
			if (tot<2&&cover[i]==0)cover[i]=1,ans1++,tot++;
			if (tot<2&&cover[i+1]==0)cover[i+1]=1,ans1++,tot++;
		}
		if (book[i]>=3){
			if (cover[i-1]==0)ans1++;
			if (cover[i]==0)ans1++;
			if (cover[i+1]==0)ans1++;
			cover[i-1]=cover[i]=cover[i+1]=1;
		}
	}
	memset(cover,0,sizeof(cover));
	for (int i=1;i<=n;i++){
		if (book[i]==0)continue;
		if (cover[i-1]==1||cover[i]==1||cover[i+1]==1)continue;
		cover[i+1]=1,ans2++;
	}
	cout<<ans2<<' '<<ans1<<endl;
	return 0;
}