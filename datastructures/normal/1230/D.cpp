#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define int long long
using namespace std;
int cnt[10005],n,a[10005],b[10005],ans,num;
int q[7005],head,tail;
bool can[7005][7005],book[7005];
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	for (int i=1;i<=n;i++)cin>>b[i];
	for (register int i=1;i<=n;i++)
		for (register int j=1;j<=n;j++){
			if (i==j)continue;
			if ((a[i]|a[j])!=a[j])can[i][j]=1,cnt[i]++;
		}
	for (register int i=1;i<=n;i++)ans+=b[i];
	head=1,tail=0,num=n-1;
	for (register int i=1;i<=n;i++)
		if (cnt[i]==num)q[++tail]=i,book[i]=1;
	while(head<=tail&&num>0){
		int c=q[head];
		head++;
		ans-=b[c];
		num--;
		for (register int i=1;i<=n;i++){
			if (book[i]==1)continue;
			if (can[i][c])cnt[i]--;
			if (cnt[i]==num){
				q[++tail]=i;
				book[i]=1;
			}
		}
	}
	if (num>=1)cout<<ans<<endl;
	else cout<<0<<endl;
	return 0;
}