#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n,m;

int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		int x,y;cin>>x>>y;
		if(y<2*x) cout<<"-1 -1"<<endl;
		else cout<<x<<" "<<2*x<<endl;
	}
	return 0;
}