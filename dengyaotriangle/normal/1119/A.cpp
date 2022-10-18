#include<bits/stdc++.h>

using namespace std;

const int maxn=300005;

int n;
int c[maxn];
int mc[maxn],xc[maxn];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	memset(mc,0x3f,sizeof(mc));
	for(int i=1;i<=n;i++){
		mc[c[i]]=min(mc[c[i]],i);
		xc[c[i]]=i;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(mc[i]!=0x3f3f3f3f&&xc[i]!=0){
			if(xc[i]!=n){
				ans=max(ans,n-mc[i]);
			}
			if(mc[i]!=1)ans=max(ans,xc[i]-1);
		}
	}
	cout<<ans;
	return 0;
}