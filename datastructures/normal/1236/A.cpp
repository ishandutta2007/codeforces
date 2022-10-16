#include <iostream>
#include <cstdio>
using namespace std;
int t,a,b,c;
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		int ans=0;
		while(b&&c>1){
			b--,c-=2;
			ans+=3;
		}
		while(a&&b>1){
			a--,b-=2;
			ans+=3;
		}
		cout<<ans<<endl;
	}
	return 0;
}