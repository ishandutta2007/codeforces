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

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long ll;
typedef vector<ll> Vll;
typedef vector<Vll> VVll;

bool prim(int x){
	for(int i = 2;i*i <= x;++i){
		if(x%i == 0) return false;
	}
	return true;
}

int main(){
	int n;
	cin>>n;
	for(int i = 4;i <= n/2;++i){
		if(!prim(i) && !prim(n-i)){
			cout<<i<<" "<<n-i<<endl;
			break;
		}
	}
}