#include<bits/stdc++.h>
using namespace std;
int n,a[500005],pos;
int f[500005][2],g[500005][2];
bool ok[500005];
map<int,bool>mp;
void calcf(){
	f[0][0]=f[0][1]=0;
	for(int i=1;i<=n;i++){
		if(i<pos){
			int tmp=2e9;
			if(a[i]>a[i-1])tmp=f[i-1][0];
			if(a[i]>f[i-1][0])tmp=min(tmp,a[i-1]);
			f[i][0]=f[i][1]=tmp;
		}else if(i==pos){
			int tmp=2e9;
			if(a[i]>a[i-1])tmp=f[i-1][0];
			if(a[i]>f[i-1][0])tmp=min(tmp,a[i-1]);
			f[i][0]=tmp,f[i][1]=0;
		}else{
			int tmp=2e9;
			if(a[i]<a[i-1])tmp=f[i-1][0];
			if(a[i]<f[i-1][1])tmp=min(tmp,a[i-1]);
			f[i][0]=tmp;
			tmp=0;
			if(a[i]>a[i-1])tmp=f[i-1][1];
			if(a[i]>f[i-1][0])tmp=max(tmp,a[i-1]);
			f[i][1]=tmp;
		}
	}
}
void calcg(){
	g[n+1][0]=g[n+1][1]=0;
	for(int i=n;i;i--){
		if(i>pos){
			int tmp=2e9;
			if(a[i]>a[i+1])tmp=g[i+1][0];
			if(a[i]>g[i+1][0])tmp=min(tmp,a[i+1]);
			g[i][0]=g[i][1]=tmp;
		}else if(i==pos){
			int tmp=2e9;
			if(a[i]>a[i+1])tmp=g[i+1][0];
			if(a[i]>g[i+1][0])tmp=min(tmp,a[i+1]);
			g[i][0]=tmp,g[i][1]=0;
		}else{
			int tmp=2e9;
			if(a[i]<a[i+1])tmp=g[i+1][0];
			if(a[i]<g[i+1][1])tmp=min(tmp,a[i+1]);
			g[i][0]=tmp;
			tmp=0;
			if(a[i]>a[i+1])tmp=g[i+1][1];
			if(a[i]>g[i+1][0])tmp=max(tmp,a[i+1]);
			g[i][1]=tmp;
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[pos]<a[i])pos=i;
	}
	calcf(),calcg();
	for(int i=1;i<=n;i++)if(i!=pos){
		if(i<pos){
			int z=f[i][1];
			if(z<a[i+1]&&a[i]>g[i+1][0])mp[a[i]]=1;
			if(z<g[i+1][1]&&a[i]>a[i+1])mp[a[i]]=1;
		}else{
			int z=g[i][1];
			if(z<a[i-1]&&a[i]>f[i-1][0])mp[a[i]]=1;
			if(z<f[i-1][1]&&a[i]>a[i-1])mp[a[i]]=1;
		}
	}
	printf("%d",mp.size());
}