#include<bits/stdc++.h>
using namespace std;
int T,n,num[2010];
bool odd,even;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),odd=even=false;
		for(int i=1;i<=n;i++){
			scanf("%d",&num[i]);	
			if(num[i]&1)odd=true;
			else even=true;
		}
		if(n&1)puts(odd?"YES":"NO");
		else puts((odd&&even)?"YES":"NO");
	}
	return 0;
}