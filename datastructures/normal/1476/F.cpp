#include <iostream>
#include <cstdio>
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int t,n,a[300005],f[300005],opt[300005],last[300005],ans[300005],st[300005][25],lg[300005];
int ask(int l,int r){
	if (l>r)return -1e9;
	int len=lg[r-l+1];
	return max(st[l][len],st[r-(1<<len)+1][len]);
}
int main(){
	for (int i=1;i<=300000;i++){
		while((1<<lg[i])<=i)lg[i]++;
		lg[i]--;
	}
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)a[i]=read();
		for (int i=1;i<=n;i++)st[i][0]=i+a[i];
		for (int i=1;i<=20;i++)
			for (int j=1;j+(1<<i)-1<=n;j++)
				st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
		for (int i=1;i<=n;i++){
			last[i]=i-1,opt[i]=1;
			f[i]=f[i-1];
			if (f[i-1]>=i)f[i]=max(f[i],i+a[i]);
			int l=0,r=i-1,t=-1;
			while(l<=r){
				int mid=(l+r)/2;
				if (f[mid]>=i-a[i]-1)t=mid,r=mid-1;
				else l=mid+1;
			}
			if (t>=0&&max(i-1,ask(t+1,i-1))>f[i]){
				last[i]=t,opt[i]=0;
				f[i]=max(i-1,ask(t+1,i-1));
			}
		}
		if (f[n]<n){
			puts("NO");
			continue;
		}
		puts("YES");
		int now=n;
		while(now>0){
			ans[now]=opt[now];
			for (int i=last[now]+1;i<now;i++)ans[i]=1;
			now=last[now];
		}
		for (int i=1;i<=n;i++){
			if (ans[i]==0)putchar('L');
			else putchar('R');
		}
		puts("");
	}
	return 0;
}