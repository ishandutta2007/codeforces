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
int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int pw(int a,int b,int p){
	if(b==0)return 1;
	int t=pw(a,b/2,p);
	if(b%2)return (((a*t)%p)*t)%p;
	else return ((t*t)%p);
}

void solve(){
	int a,b,p,q;
	cin>>a>>b;
	int c=gcd(a,b);pii x;
	p=a/c;q=b/c;
	for(int i=1;i<c;i++){
		int d=c*c-i*i;int e=sqrt(d);
		if(e*e==d){
			x={i,e};
			break;
		}
	}
	if(x.fr==0){
		cout<<"NO";
		return;
	}
	cout<<"YES\n";
	cout<<"0 0\n";
	cout<<p*x.fr<<" "<<p*x.sc<<"\n";
	if(p*x.sc==q*x.fr)
	cout<<q*x.sc<<" "<<-q*x.fr<<"\n";
	else
	cout<<-q*x.sc<<" "<<q*x.fr<<"\n";
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