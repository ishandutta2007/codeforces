#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int n,m,a[300005],b[300005];
int nowa,nowb,ans,flag;
inline int read(){
	register int x=0;
	register char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
signed main(){
//	freopen("1036D.in","r",stdin);
//	freopen("1036D.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)a[i]=read();
	cin>>m;
	for (int i=1;i<=m;i++)b[i]=read();
	while(nowa<n&&nowb<m){
		int sum=a[++nowa];
		ans++;
		while(sum!=0&&nowa<=n&&nowb<=m){
			if (sum>0)sum-=b[++nowb];
			if (sum<0)sum+=a[++nowa];
		}
		if (sum!=0)flag=1;
	}
	if (flag||nowa!=n||nowb!=m)cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}