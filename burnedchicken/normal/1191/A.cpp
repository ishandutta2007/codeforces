#include <bits/stdc++.h>
 
#define ll long long
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<(int(a)); i++)
#define forall(a,type) for(type::iterator it=a.begin(); it!=a.end(); it++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define pow2(x) (1ll<<(x))
 
using namespace std;

const int Mod=1e9+7;

char f(int x){
	switch(x%4){
		case 0: return 'D';
		case 1: return 'A';
		case 2: return 'C';
		case 3: return 'B';
	}
}
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int x,y;
	cin >> x;
	y=x;
	if(f(x+1)<f(y)) y=x+1;
	if(f(x+2)<f(y)) y=x+2;
	cout << y-x << ' ' << f(y) << "\n"; 
	return 0;
}