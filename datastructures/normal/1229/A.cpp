#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int n;
int a[10005];
bool c[7005][7005];
int b[10005],ans;
int du[10005],q[10005],head,tail;
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	for (int i=1;i<=n;i++)cin>>b[i];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if ((a[i]&a[j])==a[j]&&i!=j)c[i][j]=1,du[j]++;
	for (int i=1;i<=n;i++)ans+=b[i];
	head=1;
	for (int i=1;i<=n;i++)
		if (du[i]==0)q[++tail]=i;
	while(head<=tail){
		int now=q[head];
		head++;
		ans-=b[now];
		for (int i=1;i<=n;i++)
			if (c[now][i]==1){
				du[i]--;
				if (du[i]==0)q[++tail]=i;
			}
	}
	cout<<ans<<endl;
	return 0;
}