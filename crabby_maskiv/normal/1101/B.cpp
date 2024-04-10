#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m; 
string s;
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>s;n=s.length();s=" "+s;
	int fl=0,fr=0;
	int l,r;
	for(l=1;l<=n;l++){
		if(s[l]==':'){
			if(!fl) continue;
			break;
		}
		if(s[l]=='[') fl=l;
	}
	for(r=n;r;r--){
		if(s[r]==':'){
			if(!fr) continue;
			break;
		}
		if(s[r]==']') fr=r;
	}
	if(!fl||!fr||l>n||!r||l>=r){
		cout<<-1;
		return 0;
	}
	int ans=0;
	for(i=fl;i<=fr;i++){
		if(i!=fl&&i!=fr&&i!=l&&i!=r){
			if(i>l&&i<r&&s[i]=='|') continue;
			ans++;
		}
	}
	cout<<(fr-fl+1)-ans;
	return 0;
}