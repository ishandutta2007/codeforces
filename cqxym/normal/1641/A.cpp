#include<iostream>
#include<map>
using namespace std;
#define R register int
inline void Solve(){
	int n,x,ans=0,k;
	cin>>n>>k;
	map<long long,int>S;
	for(R i=0;i!=n;i++){
		cin>>x;
		S[x]++;
	}
	while(n!=0){
		while(S.begin()->second==0){
			S.erase(S.begin());
		}
		x=S.begin()->first;
		S[x]--;
		n--;
		long long t=(long long)k*x;
		if(t>1000000000||S[t]==0){
			ans++;
		}else{
			n--;
			S[t]--;
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