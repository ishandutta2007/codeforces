#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<string>
#include<stack>
#include<iomanip>

using namespace std;

#define X first
#define Y second
#define forl(i,a,f) for(int i = a;i < f;++i)
#define rofl(i,a,f) for(int i = a;i > f;--i)
#define pb push_back


typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long ll;
typedef vector<ll> Vll;
typedef vector<Vll> VVll;
typedef pair<ll ,ll> Pll;
typedef vector<Pll> VPll;
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
	int n,k;
	cin>>n>>k;
	int j = 1;
	int l = n+1;
	forl(i,0,k-1){
		if(i > 0) cout<<" ";
		cout<<j;
		l = j;
		j = n-j+1;
		if(j < n/2) ++j;
	}
	if(j > l){
		rofl(i,j,l) cout<<" "<<i;
	}
	else{
		forl(i,j,l){ 
			if(i > 1) cout<<" ";
			cout<<i;
		}
	}
	cout<<endl;
}