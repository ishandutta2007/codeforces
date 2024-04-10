#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<char> VC;
typedef vector<VC> VVC;
typedef long long ll;
typedef vector<ll> Vll;
typedef vector<Vll> VVll;

int main(){
	int a,b,m,n,t;
	cin>>n>>m>>a>>b;
	if((b/m) >= a){
		t = n*a;
	}
	else {
		t = int(n/m)*b;
		if(n%m > 0) t += min((n%m)*a,b);
	}
	cout<<t<<endl;
}