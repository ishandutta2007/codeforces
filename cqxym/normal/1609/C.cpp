#include<iostream>
using namespace std;
#define R register int
#define N 1000001
int a[200000],f[200000],g[200000];
bool vis[N];
inline void Solve(){
	int n,e;
	cin>>n>>e;
	for(R i=0;i!=n;i++){
		cin>>a[i];
	}
	long long ans=0;
	for(R i=n-1;i!=-1;i--){
		if(a[i]==1){
			f[i]=i+e<n?f[i+e]+1:1;
			g[i]=i+e<n?g[i+e]+1:1;
		}else{
			f[i]=0;
			if(vis[a[i]]==false){
				g[i]=i+e<n?f[i+e]+1:1;
			}else{
				g[i]=0;
			}
		}
		if(g[i]>f[i]){
			ans+=g[i]-f[i];
			if(a[i]!=1&&vis[a[i]]==false){
				ans--;
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	for(R i=2;i!=N;i++){
		if(vis[i]==false){
			for(R j=i<<1;j<N;j+=i){
				vis[j]=true;
			}
		}
	}
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}