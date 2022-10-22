#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
string s;
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n>>s;
		s=" "+s;
		for(i=1;i<=n-10;i++){
			if(s[i]=='8'){
				cout<<"YES"<<endl;
				break;
			}
		}
		if(i>n-10) cout<<"NO"<<endl;
	}
	return 0;
}