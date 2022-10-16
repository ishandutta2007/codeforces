#include<bits/stdc++.h>
using namespace std;
const int B=400,mod=1000000007;
int n,q,a[100003],ed[17][100003],val[17][100003];
bool vis[100003];
struct node{
	int maxn,spe,ret;
}dat[503];
int calc(int l,int r,int given){
	if(given<0)return 0;
	for(int i=r;i>=l;i--)
		if(2ll*given+a[i]>=mod)
			return mod;
		else
			if(2*given+a[i]<0)
				return -1;
			else
				given=2*given+a[i];
	return given;
}
int sum[100003],pw[100003],inv[100003];
int query(int l,int r){
	return 1ll*(sum[r+1]-sum[l]+mod)*inv[l]%mod;
}
int lb[503],rb[503],m;
int main(){
//	freopen("d.in","r",stdin);
//	freopen("d.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	pw[0]=1;for(int i=1;i<100003;i++)pw[i]=2ll*pw[i-1]%mod;
	inv[0]=1;for(int i=1;i<100003;i++)inv[i]=500000004ll*inv[i-1]%mod;
	for(int i=0;i<n;i++)
		sum[i+1]=(sum[i]+1ll*pw[i+1]*(mod+a[i]))%mod;
	for(int i=0;i<n;i+=B){
		lb[m]=i;
		rb[m]=min(i+B,n)-1;
		vis[rb[m]]=1;
		int l=0,r=mod,mid;
		while(l!=r){
			mid=(l+r>>1);
			if(calc(lb[m],rb[m],mid)==mod)
				r=mid;
			else
				l=mid+1;
		}
		dat[m].maxn=l;
		int val=calc(lb[m],rb[m],l-1);
		if(val>=0)
			dat[m].spe=l-1,dat[m].ret=val;
		else
			dat[m].spe=-1;
		m++;
	}vis[n-1]=0;
	for(int i=0;i<n;i++){
		int given=0,j;
		for(j=i;j>=0;j--)
			if(!vis[j])
				if(2ll*given+a[j]>=mod){
					given=mod;
					ed[0][i]=0;
					break;
				}else
					if(2*given+a[j]<0){
						given=-1;
						ed[0][i]=j;
						break;
					}else
						given=2*given+a[j];
			else
				break;
		if(given>=0&&given<mod)
			while(j>=0){
				if(given>=dat[j/B].maxn){
					ed[0][i]=0;
					break;
				}else
					if(given==dat[j/B].spe)
						given=dat[j/B].ret;
					else{
						for(;;j--)
							if(2*given+a[j]<0){
								ed[0][i]=j;
								break;
							}else
								given=2*given+a[j];
						break;
					}
				j-=B;
			}
		if(j==-1)
			ed[0][i]=0;
	}
	for(int i=0;i<n;i++)
		val[0][i]=query(ed[0][i],i);
	for(int i=1;i<17;i++)
		for(int j=0;j<n;j++)
			if(ed[i-1][j]){
				ed[i][j]=ed[i-1][ed[i-1][j]-1];
				val[i][j]=(val[i-1][j]+val[i-1][ed[i-1][j]-1])%mod;
			}
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		if(l==r){
			printf("%d\n",(a[l-1]+mod)%mod);
			continue;
		}r--;
		int ans=(a[l-1]+mod)%mod;
		for(int i=16;i>=0;i--)
			if(ed[i][r]>l){
				ans=(ans+val[i][r])%mod;
				r=ed[i][r]-1;
			}
		ans=(ans+query(l,r))%mod;
		printf("%d\n",ans);
	}
}