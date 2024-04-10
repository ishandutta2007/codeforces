#include<iostream>
using namespace std;
#define R register int
bool vis[65536];
inline void Solve(){
	int n,k;
	cin>>n>>k;
	for(R i=0;i!=n;i++){
		vis[i]=false;
	}
	n--;
	if(k==n){
		if(n==3){
			cout<<"-1\n";
			return;
		}
		vis[n]=vis[0]=vis[2]=vis[1]=vis[n-1]=vis[n-2]=true;
		cout<<n<<" "<<n-1<<"\n1 "<<n-2<<"\n0 2\n";
	}else{
		vis[k]=vis[n]=vis[k^n]=vis[0]=true;
		cout<<k<<" "<<n<<"\n";
		if(k!=0){
			cout<<(k^n)<<" 0\n";
		}
	}
	for(R i=0;i!=n;i++){
		if(vis[i]==false){
			vis[i]=vis[i^n]=true;
			cout<<i<<" "<<(i^n)<<"\n";
		}
	}
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}