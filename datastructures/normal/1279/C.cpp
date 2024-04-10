#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#define int long long
using namespace std;
int t,n,m,a[100005],b[100005],book[100005],now,ans;
signed main(){
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for (int i=1;i<=n;i++)scanf("%I64d",&a[i]);
		for (int i=1;i<=m;i++)scanf("%I64d",&b[i]);
		memset(book,0,sizeof(book));
		now=0,ans=0;
		for (int i=1;i<=n;i++)book[a[i]]=i;
		for (int i=1;i<=m;i++)b[i]=book[b[i]];
		for (int i=1;i<=m;i++){
			if (b[i]>now)ans+=(b[i]-i)*2+1,now=b[i];
			else ans++;
		}
		cout<<ans<<endl;
	} 
	return 0;
}