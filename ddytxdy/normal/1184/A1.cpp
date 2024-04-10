#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL r;
int main(){
	cin>>r;
	for(int i=1;i<=r;i++){
		LL re=r-1ll*i*i-i-1;
		if(re<=0)break;
		if(re%(2ll*i)==0)cout<<i<<" "<<re/(2ll*i),exit(0);
	}
	puts("NO");
	return 0;
}