#include <iostream>
#include <cstdio> 
#include <cmath>
#include <cstring>
#define int long long
using namespace std;
int n,a[5005],ans[5005],id[5005],tot,book[5005];
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	for (int i=1;i<=n;i++){
		for (register int j=1;j<i;j++){
			int x=a[i]*a[j];
			if (x<=0)continue;
			int sq=(int)(sqrt(x));
			int fg=0;
			for (register int k=max(0ll,sq-3);k<=sq+3;k++)
				if (k*k==x)fg=1;
			if (fg==1){
				id[i]=id[j];
				break;
			}
		}
		if (id[i]==0)id[i]=++tot;
	}
	for (register int i=1;i<=n;i++){
		memset(book,0,sizeof(book));
		register int num=0;
		for (register int j=i;j<=n;j++){
			if (a[j]!=0)book[id[j]]++;
			if (book[id[j]]==1)num++;
			if (num!=0)ans[num]++;
			else ans[1]++;
		}
	}
	for  (register int i=1;i<=n;i++)cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}