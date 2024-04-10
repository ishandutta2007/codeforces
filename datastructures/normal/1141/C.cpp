#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define f*** ccf
using namespace std;
int a[200005],n;
int r[200005],book[200005];
int sum[200005];
int main(){
//	freopen("1141C.in","r",stdin);
//	freopen("1141C.out","w",st
	cin>>n;
	for (int i=2;i<=n;i++)cin>>a[i];
	for (int i=2;i<=n;i++)sum[i]=a[i]+sum[i-1];
	int mina=2e9;
	for (int i=2;i<=n;i++)mina=min(mina,sum[i]);
	if (mina>1){
		cout<<-1<<endl;
		return 0;
	}
	r[1]=(mina==1)?1:(-mina+1);
	for (int i=1;i<=n;i++)r[i]=r[1]+sum[i];
	for (int i=1;i<=n;i++)
		if (r[i]>0&&r[i]<=n)book[r[i]]=1;
	for (int i=1;i<=n;i++)
		if (book[i]==0){
			cout<<-1<<endl;
			return 0;
		}
	for (int i=1;i<=n;i++)cout<<r[i]<<' ';
	cout<<endl;
	return 0; 
}