#include<bits/stdc++.h>
using namespace std;
int n,a[1000003],lst[4000003],nxt[4000003],sum[4000003];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	for(int i=1;i<n;i++)
		a[i]=a[i]-a[0];
	for(int i=1;i<n;i++)
		lst[a[i]]=i,
		nxt[a[i]]=i,
		sum[a[i]]=1;
	for(int i=1;i<4000003;i++){
		if(!lst[i])
			lst[i]=lst[i-1];
		sum[i]+=sum[i-1];
	}
	for(int i=4000002;i>=0;i--)
		if(!nxt[i])
			nxt[i]=nxt[i+1];
	for(int i=1;i<=2000000;i++){
		bool ok=1;
		int maxr=i,minl=max(0ll,a[0]-1ll*i*i);
		for(int j=0,nw=0;j<1420;j++){
			int l=nw,r=l+(i+j<<1);
			if(sum[r-i]-sum[l+i+j]){
				ok=0;
				break;
			}
			if(nxt[r-i+1]&&a[nxt[r-i+1]]<=r)
				minl=max(minl,r-a[nxt[r-i+1]]+1);
			if(lst[l+i+j]&&a[lst[l+i+j]]>=l+j+1)
				maxr=min(maxr,l+i+j-a[lst[l+i+j]]);
			nw=r+1;
			if(r>=1999999)
				break;
		}
		if(maxr>=minl&&ok){
			cout<<1ll*i*i+minl-a[0];
			return 0;
		}
	}
}