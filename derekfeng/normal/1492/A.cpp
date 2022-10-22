#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll t,a,b,c;
inline ll sol(ll x){return (x-t%x)%x;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%I64d%I64d%I64d%I64d",&t,&a,&b,&c);
		printf("%I64d\n",min(min(sol(a),sol(b)),sol(c)));
	}
}