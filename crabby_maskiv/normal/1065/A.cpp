#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;

int main(){
	ios::sync_with_stdio(0);
	int i,j;
	int T;cin>>T;
	while(T--){
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		cout<<a/d+(a/d/b)*c<<endl;
	}
	return 0;
}