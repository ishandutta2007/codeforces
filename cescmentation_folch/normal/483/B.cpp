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
	ll a = 0,b = 5e9;
	ll c1,c2,x,y;
	cin>>c1>>c2>>x>>y;
	while(a+1<b){
		ll c = (a+b)/2;
		if((c-(c/(x*y))) >= c1+c2 && c1 <= (c-(c/x)) && c2 <= (c-(c/y))) b = c;
		else a = c;
	}
	cout<<b<<endl;
}