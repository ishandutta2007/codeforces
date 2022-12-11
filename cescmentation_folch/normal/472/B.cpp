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

int main(){
	int n,k;
	cin>>n>>k;
	VI V(n);
	for(int i = 0;i < n;++i){
		cin>>V[i];
	}
	sort(V.begin(),V.end());
	
	int res = 0;
	
	for(int i = n-1;i >= 0;i -= k){
		res += 2*(V[i]-1);
	}
	cout<<res<<endl;
}