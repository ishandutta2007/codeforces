#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
int n,m;
string s="codeforces";
int main(){
	int i,j;
	ll k;cin>>k;
	ll t=pow(k,1.0/10);
	ll x=t*t*t*t*t*t*t*t*t*t;
	int cnt=0;
	while(x<k){
		x=x/t*(t+1);
		cnt++;
	}
	for(i=0;i<cnt;i++){
		for(j=1;j<=t+1;j++)
			cout<<s[i];
	}
	for(i=cnt;i<10;i++){
		for(j=1;j<=t;j++)
			cout<<s[i];
	}
	return 0;
}