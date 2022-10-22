#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n,a,b,half;
signed main(){
	scanf("%I64d",&T);
	while(T--){
		scanf("%I64d%I64d%I64d",&n,&a,&b);
		half=(n+1)/2;
		if(!(half%a))printf("%I64d\n",max((half/a)*(a+b)-b,n));
		else printf("%I64d\n",max((half/a)*(a+b)+(half%a),n));
	}
	return 0;
}