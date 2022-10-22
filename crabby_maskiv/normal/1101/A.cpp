#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=305;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;

int main(){
	ios::sync_with_stdio(0);
	int i,j;
	int T;cin>>T;
	while(T--){
		ll x,y,d;cin>>x>>y>>d;
		if(x>d){
			cout<<d<<endl;
			continue;
		}
		cout<<(y+d)/d*d<<endl;
	}
	return 0;
}