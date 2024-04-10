#include<iostream>
#include<map>
using namespace std;
#define R register int
inline void Solve(){
	int sum=0,l;
	cin>>l;
	string s;
	cin>>s;
	long long ans=0;
	map<int,int>Q;
	Q[0]=1;
	for(R i=0;i!=l;i++){
		sum+=s[i]-'1';
		ans+=Q[sum];
		Q[sum]++;
	}
	printf("%lld\n",ans);
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}