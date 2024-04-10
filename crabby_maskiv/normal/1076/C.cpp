#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
int main(){
	//ios::sync_with_stdio(0);
	int i,j;
	int T;cin>>T;
	while(T--){
		ll x;cin>>x;
		if(x&&x<4){
			printf("N\n");
			continue;
		}
		double p=x;
		double a=(-p-sqrtl(p*p-4*p))/(-2);
		double b=p-a;
		printf("Y %.9lf %.9lf\n",a,b);
	}
	return 0;
}