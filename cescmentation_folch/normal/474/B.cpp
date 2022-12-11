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

VI G;
int n;

int construct(int x){
	if(x >= n) return G[x];
	return G[x] = max(construct(2*x+1),construct(2*x));
}

void find(int x, int v){
	if(x >= n){
		cout<<x-n+1<<endl;
		return;
	}
	//cout<<"-"<<x<<endl;
	if(G[2*x] >= v) find(2*x,v);
	else find(2*x+1,v);
}

int main(){
	cin>>n;
	int n1 = n;
	n |= n>>1;
	n |= n>>2;
	n |= n>>4;
	n |= n>>8;
	n |= n>>16;
	n++;
	G = VI(2*n,0);
	
	int t = 0;
	for(int i = 0;i < n1;++i){
		int k;
		cin>>k;
		t += k;
		G[n+i] = t;
		//cout<<G[n+i]<<endl;
	}
	construct(1);
	
	int m;
	cin>>m;
	
	for(int i = 0;i < m;++i){
		int k;
		cin>>k;
		find(1,k);
	}
}