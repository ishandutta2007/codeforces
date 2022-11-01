#include<iostream>
using namespace std;
#define R register int
bool vis[100001];
inline void Solve(){
	int n,b,c,a,m;
	cin>>n>>m;
	for(R i=1;i<=n;i++){
		vis[i]=false;
	}
	for(R i=0;i!=m;i++){
		cin>>a>>b>>c;
		vis[b]=true;
	}
	for(R i=1;i<=n;i++){
		if(vis[i]==false){
			m=i;
			break;
		}
	}
	for(R i=1;i<=n;i++){
		if(i!=m){
			cout<<m<<' '<<i<<endl;
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