#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
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

void solve(){
	string s,t;
	cin>>s;
	int w=1,x=1,y=1,z=1,zr=0;
	for(char c:s){
		if(c=='1'&&w){w=0;continue;}
		if(c=='6'&&x){x=0;continue;}
		if(c=='8'&&y){y=0;continue;}
		if(c=='9'&&z){z=0;continue;}
		if(c=='0'){zr++;continue;}
		t.pb(c);
	}
	int n=0;
	for(char c:t){
		n=10*n+c-'0';
		n%=7;
	}
	cout<<t;
	switch(n){
		case 0:cout<<"9681";break;
		case 1:cout<<"6198";break;
		case 2:cout<<"1896";break;
		case 3:cout<<"6918";break;
		case 4:cout<<"1986";break;
		case 5:cout<<"1968";break;
		case 6:cout<<"8691";break;
	}
	for (int i = 0; i < zr; ++i)
	{
		cout<<0;
	}
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