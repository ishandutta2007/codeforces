#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define vc                vector
#define pii               pair<int,int>
#define msi               map<string,int>
#define mii               map<int,int>
#define psi               pair<string,int>
#define pis               pair<int,string>
#define piii              pair<int,pii>
/*int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int pw(int a,int b,int p){
    if(b==0)return 1;
    int t=pw(a,b/2,p);
    if(b%2)return ((a*t*t)%p);
    else return ((t*t)%p);
}*/


void solve(){
	int n,p;
	cin>>n>>p;
	char c='a'-1+p;
	string s;
	cin>>s;
	if(p==1){cout<<"NO";return;}
	int pos=n-1;
	s[pos]++;
	if(s[pos]>c){if(pos==0){cout<<"NO";return;};s[pos]='a';pos--;s[pos]++;}
	while(1){
		if(pos==0)break;
		if(pos==1&&s[pos]!=s[pos-1])break;
	if(pos>1&&s[pos]!=s[pos-1]&&s[pos]!=s[pos-2])
	break;
		s[pos]++;
		while(s[pos]>c){if(pos==0){cout<<"NO";return;};s[pos]='a';pos--;s[pos]++;}
	}
	pos++;
	while(1){
		if(pos==n)break;
		if(pos==1)pos++;if(pos==n)break;
		while(s[pos]==s[pos-1]||s[pos]==s[pos-2])
		s[pos]++;
		pos++;
	}
	cout<<s;
}
signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}