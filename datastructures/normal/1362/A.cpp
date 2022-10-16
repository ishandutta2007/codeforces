#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
int t,n,a,b;
signed main(){
	cin>>t;
	while(t--){
		cin>>a>>b;
		int ans=0;
		if (a>b)swap(a,b);
		while(a<b){
			if (a*8<=b)a*=8,ans++;
			else if (a*4<=b)a*=4,ans++;
			else a*=2,ans++;
		}
		if (a!=b)puts("-1");
		else cout<<ans<<endl;
	}
	return 0;
}