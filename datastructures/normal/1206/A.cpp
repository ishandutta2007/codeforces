#include <iostream>
#include <cstdio>
using namespace std;
int n,m,a[205],b[205];
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	cin>>m;
	for (int i=1;i<=m;i++)cin>>b[i];
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			int flag=1;
			for (int k=1;k<=n;k++)
				if (a[i]+b[j]==a[k])flag=0;
			for (int k=1;k<=m;k++)
				if (a[i]+b[j]==b[k])flag=0;
			if (flag){
				cout<<a[i]<<' '<<b[j]<<endl;
				return 0;
			}
		}
	}
	return 0;
}