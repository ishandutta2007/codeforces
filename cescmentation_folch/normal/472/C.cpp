#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<string>
#include<stack>

using namespace std;

#define X first
#define Y second
#define rep(i,a,f) for(int i = a;i < f;++i)

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long ll;
typedef vector<ll> Vll;
typedef vector<Vll> VVll;
typedef pair<string, string> PS;
typedef vector<PS> VPS;
typedef pair<int, int> PI;
typedef vector<PI> VPI;

string comp(string a, string b, string c){
	if(a < b && a < c){
		return (b < c)? b : c;
	}
	if(a < c) return c;
	if(a < b) return b;
	return "-1";
}

int main(){
	int n;
	cin>>n;
	VI F(n);
	VPS T(n);
	rep(i,0,n) cin>>T[i].X>>T[i].Y;
	rep(i,0,n) cin>>F[i];
	string a = "";
	bool xec = true;
	rep(i,0,n){
		int x = F[i]-1;
		a = comp(a,T[x].X,T[x].Y);
		if(a == "-1"){
			xec = false;
			break;
		}
	}
	if(xec) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}