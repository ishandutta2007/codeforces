#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n,sum;int m;
LL power(int x,int y){
	LL ret=1;
	while(y){
		if(y&1)ret*=x;
		x*=x;y>>=1;
	}
	return ret;
}
int main(){
	cin>>n;
	for(m=1;;m++){
		LL xx=m*9*power(10,m-1);
		if(n>xx)n-=xx,sum+=xx/m;
		else break;
	}
	LL x=n/m;
	LL y=sum+x;
	int z=n-1ll*x*m;
//	cout<<n<<" "<<m<<" "<<y<<" "<<z<<" ";
	LL xx=(y+1)/power(10,m-z);
	if(!z)cout<<y%10;
	else cout<<xx%10;
	return 0;
}