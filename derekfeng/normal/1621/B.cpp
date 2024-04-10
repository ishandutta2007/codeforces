#include<bits/stdc++.h>
using namespace std;
int n;
int fi,ed,wl,wr;
int w,ans,l[100004],r[100004],c[100004];
void sol(){
	scanf("%d",&n);
	fi=1e9+1,ed=0,wl=1e9,wr=1e9,w=2e9;
	ans=2e9;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&l[i],&r[i],&c[i]);
		if(fi>l[i])fi=l[i],wl=c[i],w=2e9;
		else if(fi==l[i]&&wl>c[i])wl=c[i];
		if(ed<r[i])ed=r[i],wr=c[i],w=2e9;
		else if(ed==r[i]&&wr>c[i])wr=c[i];
		if(fi==l[i]&&r[i]==ed)w=min(w,c[i]);
		printf("%d\n",min(w,wl+wr));
	}
}
int main(){
	int T;scanf("%d",&T);
	while(T--)sol();
}