#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m; 
ll ans;
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	int T;cin>>T;
	while(T--){
		string s;cin>>s;
		n=s.length();s=" "+s;
		for(i=1;i<=n;i++){
			if(s[i]!=s[n-i+1]) break;
		}
		if(i<=n){
			for(i=1;i<=n;i++) cout<<s[i];
			cout<<endl;
			continue;
		}
		bool flag=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(s[i]!=s[j]){
					swap(s[i],s[j]);
					flag=1;
					break;
				}
			}
			if(flag) break;
		}
		if(!flag) cout<<-1<<endl;
		else{
			for(i=1;i<=n;i++) cout<<s[i];
			cout<<endl;
		}
	}
	
	
	return 0;
}