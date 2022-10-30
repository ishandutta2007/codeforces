#include<bits/stdc++.h>
const int N=514514;
using namespace std;

int f[N],n,a[N],b[N],ans,cnt,t; 

int gf(int k){
	return k==f[k]?k:(f[k]=gf(f[k]));
}

void mrg(int x,int y){
	int fx=gf(x),fy=gf(y);
	if(fx!=fy)f[fx]=fy,cnt--;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n),cnt=n,ans=1;
		for(int i=1;i<=n;i++)f[i]=i,scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)scanf("%d",&b[i]),mrg(a[i],b[i]);
		for(int i=1;i<=cnt;i++)ans=ans*2%1000000007;
		printf("%d\n",ans); 
	}
}