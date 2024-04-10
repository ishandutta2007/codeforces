#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n>>m;
		if(m%3==0){
			n%=m+1;
			if(n==0) cout<<"Bob"<<endl;
			else if(n==m||n%3) cout<<"Alice"<<endl;
			else cout<<"Bob"<<endl;
		}
		else{
			cout<<((n%3)?"Alice":"Bob")<<endl;
		}
	}
	return 0;
}