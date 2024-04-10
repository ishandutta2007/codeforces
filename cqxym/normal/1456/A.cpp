#include<iostream>
using namespace std;
#define R register int
int f[100001];
char s[100001];
inline void Solve(){
	int n,p,k;
	cin>>n>>p>>k;
	string s;
	cin>>s;
	for(R i=n;i!=0;i--){
		if(s[i-1]=='0'){
			f[i]=1;
		}else{
			f[i]=0;
		}
		int t=i+k;
		if(t<=n){
			f[i]+=f[t];
		}
	}
	int x,y,ans=2e9;
	cin>>x>>y;
	for(R i=p;i<=n;i++){
		int tem=y*(i-p)+f[i]*x;
		if(tem<ans){
			ans=tem;
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