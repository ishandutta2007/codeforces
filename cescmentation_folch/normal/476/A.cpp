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
#define FOR(i,a,f) for(int i = a;i < f;++i)
#define ROF(i,a,f) for(int i = a;i > f;--i)

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long ll;
typedef vector<ll> Vll;
typedef vector<Vll> VVll;
typedef pair<int, int> PI;
typedef pair<bool , int> PBI;
typedef pair<PI,PBI> PIB;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef priority_queue<PI> PQPI;
typedef queue<PI> QPI;
typedef queue<PIB> QPIB;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector<VC> VVC;

int main(){
	int n,m;
	cin>>n>>m;
	int k = (n+1)/2;
	int j = (k+m-1)/m;
	j *= m;
	if(j > n) cout<<-1<<endl;
	else cout<<j<<endl;
}