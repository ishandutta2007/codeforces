#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
#define mod 998244353
using namespace std;
int n,m,a[1000005],l[505],r[505];
int log_2[1000005],st[1000005][25];
int tot,s[1005];
int c[1005];
int f[1005][1005],g[1005][1005];
int dl[1005][1005],dr[1005][1005],qwq[1005];
int ask(int l,int r){
	int ovo=log_2[r-l+1];
	return min(st[l][ovo],st[r-(1<<ovo)+1][ovo]);
}
int lower(int x){
	int l=1,r=tot,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (s[mid]<=x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
bool check(int x,int y){
	for (int i=1;i<=n;i++)
		if (!((l[i]>=x&&r[i]<=y)||(l[i]<=x&&r[i]>=y)||(r[i]<=x)||(l[i]>=y)))return 0;
	return 1;
}
signed main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++)cin>>a[i];
	for (int i=2;i<=m;i++)log_2[i]=log_2[i/2]+1;
	for (int i=1;i<=m;i++)st[i][0]=a[i];
	for (int j=1;j<=20;j++)
		for (int i=1;i+(1<<j)-1<=m;i++)
			st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	for (int i=1;i<=m;i++){
		if (l[a[i]]==0)l[a[i]]=i;
		r[a[i]]=i;
	}
	int fg=1;
	for (int i=1;i<=n;i++)
		if (ask(l[i],r[i])<i)fg=0;
	if (fg==0){
		puts("0");
		return 0;
	}
	for (int i=1;i<=n;i++){
		s[++tot]=l[i];
		if (l[i]!=r[i])s[++tot]=r[i];
	}
	sort(s+1,s+1+tot);
	for (int i=1;i<=n;i++)l[i]=lower(l[i]),r[i]=lower(r[i]);
	for (int i=1;i<=n;i++)c[l[i]]++,c[r[i]]--;
	for (int i=1;i<=n;i++){
		int pl=s[l[i]],pr=s[r[i]];
		int last=pl;
		for (int j=pl;j<=pr;j++){
			if (a[j]==i){
				if (last<j-1){
					++qwq[i];
					dl[i][qwq[i]]=lower(last+1);
					dr[i][qwq[i]]=lower(j-1);
				}
				last=j;
			}
		}
		if (last<pr-1){
			++qwq[i];
			dl[i][qwq[i]]=lower(last+1);
			dr[i][qwq[i]]=lower(pr-1);
		}
	}
	for (int i=1;i<=tot+1;i++)f[i][i]=f[i][i-1]=g[i][i]=g[i][i-1]=1;
	for (int len=2;len<=tot;len++)
		for (int i=1;i+len-1<=tot;i++){
			int j=i+len-1;
			if (check(i,j)==0)continue;
			int id=0,pl=0,pr=0;
			for (int k=1;k<=n;k++)
				if (l[k]>=i&&r[k]<=j){
					id=k;
					pl=l[k],pr=r[k];
					break;
				}
			g[i][j]=f[i][pl-1]*f[pr+1][j]%mod;
			for (int k=1;k<=qwq[id];k++)g[i][j]=g[i][j]*f[dl[id][k]][dr[id][k]]%mod;
			int s=0;
			for (int k=i;k<=j;k++){
				s+=c[k];
				if (s!=0)continue;
				f[i][j]=(f[i][j]+g[i][k]*f[k+1][j])%mod;
			}
		}
	cout<<f[1][tot]<<endl;
	return 0;
}