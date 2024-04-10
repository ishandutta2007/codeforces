#include <iostream>
#include <cstdio>
using namespace std;
int n,r[100005],a[100005],tot,ans;
int findit(int now,int x){
	while(now+1<=n&&r[now+1]==x)now++;
	return now;
}
int main(){
//	freopen("1138A.in","r",stdin);
//	freopen("1138A.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)cin>>r[i];
	for (int i=1;i<=n;i++){
		int nxt=findit(i,r[i]);
		a[++tot]=nxt-i+1;
		i=nxt;
	}
	for (int i=2;i<=tot;i++)ans=max(ans,2*min(a[i],a[i-1]));
	cout<<ans<<endl;
	return 0;
}