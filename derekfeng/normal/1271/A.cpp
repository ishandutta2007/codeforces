#include <bits/stdc++.h>	
using namespace std;
int main(){
	int a,b,c,d,e,f,ans=0;
	cin>>a>>b>>c>>d>>e>>f;
	for (int i=0;i<=min(a,d);i++){
		ans=max(ans,i*e+min(min(d-i,b),c)*f);
	}
	cout<<ans;
}