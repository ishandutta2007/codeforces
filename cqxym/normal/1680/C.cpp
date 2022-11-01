#include<iostream>
#include<string.h>
using namespace std;
#define R register int
char s[200002];
int sum[200001];
inline void Solve(){
	cin>>s+1;
	int n=strlen(s+1),l,ans=999999,c;
	for(R i=1;i<=n;i++){
		sum[i]=sum[i-1]+(s[i]^'1');
	}
	l=n-sum[n];
	for(R i=l;i<=n;i++){
		c=sum[i]-sum[i-l];
		if(c<ans){
			ans=c;
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