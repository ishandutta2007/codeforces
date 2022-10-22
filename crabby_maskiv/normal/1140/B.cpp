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
		cin>>n;
		string s;cin>>s;s=" "+s;
		int mn=inf,mx=0;
		for(i=1;i<=n;i++){
			if(s[i]=='<') mx=max(mx,i);
			else mn=min(mn,i);
		}
		cout<<min(mn-1,n-mx)<<endl;
	}
	return 0;
}