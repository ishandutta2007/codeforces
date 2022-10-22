#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const ll inf=0x3f3f3f3f;
const int mod=998244353;
int n,m,k;
string s;
int vis[N];
int main(){
	int i,j;
	cin>>n;
	cin>>s;
	s=" "+s;
	int p1=1,p2=1;
	int len=n;
	while(len>11){
		while(p1<=n&&(vis[p1]||s[p1]=='8')) p1++;
		if(p1>n){
			cout<<"YES";
			return 0;
		}
		vis[p1]=1;
		len--;
		while(p2<=n&&(vis[p2]||s[p2]!='8')) p2++;
		if(p2>n){
			cout<<"NO";
			return 0;
		}
		vis[p2]=1;
		len--;
	}
	for(i=1;i<=n;i++){
		if(!vis[i]){
			if(s[i]=='8'){
				cout<<"YES";
				return 0;
			}
			else{
				cout<<"NO";
				return 0;
			}
		}
	}
	return 0;
}