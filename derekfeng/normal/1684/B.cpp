#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b,c;
ll x,y,z;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d%d%d",&a,&b,&c);
		z=c,y=b+c,x=a+b+c;
		printf("%lld %lld %lld\n",x,y,z);
	}
}