#include<bits/stdc++.h>
using namespace std;
const int M=333;
int sz[333],lzy[333];
int n,q,a[100004];
int nxt[100004];
int cnt[100004];
int l,r,x,opt;
int go(int x){
	if(x/M*M>a[x]-lzy[x/M])return a[x]-lzy[x/M];
	return a[nxt[x]];
}
int main(){
	scanf("%d%d",&n,&q);
	sz[0]++;
	for(int i=1;i<n;i++){
		scanf("%d",&a[i]);a[i]--;
		sz[i/M]++;
		int L=i/M*M;
		if(a[i]<L)nxt[i]=i;
		else nxt[i]=nxt[a[i]];
	}
	while(q--){
		scanf("%d%d%d",&opt,&l,&r);
		l--,r--;
		if(opt==1){
			scanf("%d",&x);
			int L=l/M,R=r/M;
			for(int i=L;i<=R;i++){
				if(sz[i]>0||i==L||i==R){
					if(lzy[i]>0){
						for(int j=i*M;j<min(i*M+M,n);j++)a[j]=max(a[j]-lzy[i],0);
						lzy[i]=0;
					}
					for(int j=i*M;j<min(i*M+M,n);j++){
						if(l<=j&&j<=r){
							a[j]=max(a[j]-x,0);
							cnt[j]++;
							if(cnt[j]==M)sz[i]--;
						}
						if(a[j]<i*M)nxt[j]=j;
						if(a[j]>=i*M)nxt[j]=nxt[a[j]];
					}
				}else{
					lzy[i]=min(lzy[i]+x,100000);
				}
			}
			continue;
		}
		if(l==r){
			printf("%d\n",l+1);
			continue;
		}
		int L=l,R=r;
		if(l>r)swap(l,r);
		int	lstr=0;
		while(1){
			lstr=r/M;
			r=max(go(r),0);
			if(r<l)swap(l,r);
			if(l==r)break;
		}
		while(L/M>lstr)L=max(go(L),0);
		while(R/M>lstr)R=max(go(R),0);
		bool ok=0;
		for(int i=min(lstr*M+M-1,n-1);i>=lstr*M;i--){
			if(max(a[L]-lzy[lstr],0)==i)L=max(0,a[L]-lzy[lstr]);
			if(max(a[R]-lzy[lstr],0)==i)R=max(0,a[R]-lzy[lstr]);
			if(L==R){
				printf("%d\n",i+1);
				ok=1;
				break;
			}
		}
		if(!ok)printf("%d\n",l+1);
	}
}