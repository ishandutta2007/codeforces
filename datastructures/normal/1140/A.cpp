#include <iostream>
#include <cstdio>
using namespace std;
int n,a[10005],ans;
int main(){
//	freopen("1140A.in","r",stdin);
//	freopen("1140A.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	int now=0,maxnum=0;
	while(now<n){
		ans++,now++,maxnum=a[now];
		while(now+1<=maxnum&&now<=n)now++,maxnum=max(maxnum,a[now]);
	}
	cout<<ans<<endl;
}