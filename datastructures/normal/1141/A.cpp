#include <iostream>
#include <cstdio>
using namespace std;
int a,b,ans;
int main(){
//	freopen("1141A.in","r",stdin);
//	freopen("1141A.out","w",stdout);
	cin>>a>>b;
	while(b%a==0){
		if (a==b)break;
		if ((b/a)%2==0)a*=2,ans++;
		else if ((b/a)%3==0)a*=3,ans++;
		else break;
	}
	if (a!=b)cout<<-1<<endl;
	else cout<<ans<<endl;
}