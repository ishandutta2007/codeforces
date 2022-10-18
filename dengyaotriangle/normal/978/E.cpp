#include<bits/stdc++.h>

using namespace std;

const int maxn=1005;

int n,w;
int chg[maxn];
int pfc[maxn];
int hmi=0x7FFFFFFF,hmx=0x80000000;

int main(){
	cin>>n>>w;
	for(int i=0;i<n;i++) cin>>chg[i];
	pfc[0]=0;
	for(int i=1;i<=n;i++) pfc[i]=pfc[i-1]+chg[i-1];
	for(int i=0;i<=n;i++){
		hmi=min(pfc[i],hmi);
		hmx=max(pfc[i],hmx);
	}
	cout<<max(0,w-hmx+hmi+1);
	return 0;
}