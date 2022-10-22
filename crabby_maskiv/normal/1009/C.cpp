#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=300005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;

int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n>>m;
	ll sum=0;
	while(m--){
		ll x,y;cin>>x>>y;
		sum+=n*x;
		if(y>0){
			sum+=y*(n)*(n-1)/2;
		}
		else{
			if(n&1) sum+=y*(n/2)*(n/2+1);
			else{
				sum+=y*(n/2)*(n/2+1)/2;
				sum+=y*(n/2)*(n/2-1)/2;
			}
		}
	}
	printf("%.9lf",sum/double(n));
	return 0;
}