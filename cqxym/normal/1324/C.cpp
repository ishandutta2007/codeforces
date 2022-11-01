#include<iostream>
using namespace std;
#define R register int
inline void Solve(){
	string s;
	cin>>s;
	int l=s.length(),lt=-1,ans=0;
	for(R i=0;i!=l;i++){
		if(s[i]=='R'){
			if(i-lt>ans){
				ans=i-lt;
			}
			lt=i;
		}
	}
	if(l-lt>ans){
		ans=l-lt;
	}
	printf("%d\n",ans);
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}