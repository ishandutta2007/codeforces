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
		int x;cin>>x;
		cout<<x/7+bool(x%7)<<endl;
	} 
	return 0;
}