#include <iostream>
#include <cstdio>
using namespace std;
int t,n,a[200005],ans[200005],c[200005],d[200005],tot;
int book[200005];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		tot=0;
		int mx=0,fg=1;
		c[0]=1;
		for (int i=1;i<=n;i++){
			mx=max(mx,a[i]);
			book[a[i]]++;
			if (book[a[i]]>1)fg=0;
			if (mx==i&&fg==1)c[i]=1;
			else c[i]=0;
			
		}
		mx=0;
		for (int i=1;i<=n;i++)book[a[i]]--;
		d[n+1]=1;
		fg=1;
		for (int i=n;i>=1;i--){
			mx=max(mx,a[i]);
			book[a[i]]++;
			if (book[a[i]]>1)fg=0;
			if (mx==n-i+1&&fg==1)d[i]=1;
			else d[i]=0;
		}
		for (int i=1;i<=n;i++)book[a[i]]--;
		for (int i=1;i<n;i++)
			if (c[i]&&d[i+1])ans[++tot]=i;
		cout<<tot<<endl;
		for (int i=1;i<=tot;i++)printf("%d %d\n",ans[i],n-ans[i]);
	}
	return 0;
}