#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
int gcd(int x,int y){
	if(!y) return x;
	return gcd(y,x%y);
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	int T;cin>>T;
	while(T--){
		int x;cin>>x;x*=2;
		int g=gcd(x,360);
		if(g==360-x){
			cout<<720/g<<endl;
		}
		else cout<<360/g<<endl;
	}
	return 0;
}