#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
	scanf("%d",&t);
	while(t--){
		int n,ans=0;scanf("%d",&n);
		while(n--){
			int x;scanf("%d",&x);
			ans+=x-1;
		}
		if(ans&1)puts("errorgorn");
		else puts("maomao90");
	}
}