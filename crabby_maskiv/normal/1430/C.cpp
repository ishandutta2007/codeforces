#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,m;

int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n;
		cout<<2<<endl;
		if(n==2){
			cout<<1<<" "<<2<<endl;
			continue;
		}
		cout<<n<<" "<<n-2<<endl;
		cout<<n-1<<" "<<n-1<<endl;
		for(i=n-1;i>=3;i--) cout<<i<<" "<<i-2<<endl;
	}
	return 0;
}