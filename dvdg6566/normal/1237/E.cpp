#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define MAXN 210000
#define MAXL 18

vi works;

int main(){
	int N;
	cin>>N;
	int a = 1;
	while(a<MAXN*10){
		if (a == N || a+1 == N){
			cout<<1;
			return 0;
		}
		if (a%2 == 1){++a;a*=2;}
		else {a*=2;++a;}
	}
	cout<<0;
}