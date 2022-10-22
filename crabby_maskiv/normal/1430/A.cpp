#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,m;

int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		if(n%3==1){
			if(n/3<2) cout<<-1<<endl;
			else cout<<n/3-2<<" "<<0<<" "<<1<<endl;
		}
		else if(n%3==2){
			if(n/3<1) cout<<-1<<endl;
			else cout<<n/3-1<<" "<<1<<" "<<0<<endl;
		}
		else cout<<n/3<<" "<<0<<" "<<0<<endl;
	}
	return 0;
}