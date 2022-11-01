#include<iostream>
using namespace std;
#define R register int
int a[101],f[101],tag[101];
inline void Solve(){
	int n,ans=0;
	cin>>n;
	for(R i=1;i<=n;i++){
		cin>>a[i];
	}
	for(R i=1;i<=n;i++){
		f[i-1]=0;
		for(R j=i;j<=n;j++){
			f[j]=0;
			for(R k=0;k<=n;k++){
				tag[k]=false;
			}
			int cur=0;
			for(R k=j;k>=i;k--){
				if(a[k]<=n){
					tag[a[k]]=true;
				}
				while(tag[cur]==true){
					cur++;
				}
				if(f[k-1]+cur>=f[j]){
					f[j]=f[k-1]+cur+1;
				}
			}
			ans+=f[j];
		}
	}
	cout<<ans<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}