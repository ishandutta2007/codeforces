#include <iostream>
#include <cstdio>
using namespace std;
int t,a,b,c,d,k;
int chu(int a,int b){
	return (a-1)/b+1;
}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d>>k;
		int x=chu(a,c),y=chu(b,d);
		if (x+y>k)cout<<-1<<endl;
		else cout<<x<<' '<<y<<endl;
	}
	return 0;
}