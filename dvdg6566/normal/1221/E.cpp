#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define MAXN 210000
#define INF 1e9
#define MAXL 20

vi V,V2;
int T,N,a,b,A,B;
string S;

bool run(){
	a = 0;
	for (auto i : S){
		if (i == '.')++a;
		else if (a){
			V.pb(a);
			a = 0;
		}
	}
	if(a)V.pb(a);
	b = 0; // Counter
	for (auto i : V){
		if (i < B){
			continue;
		}else if (i < A){
			return 0;
		}else V2.pb(i);
	}
	
	int danger = -1;
	for (auto i : V2){
		if (i >= 2*B){
			if (danger != -1)return 0; // If more than one then die
			danger = i;
		}else ++b;
	}

	if (danger == -1){
		if (b%2 == 1)return 1;
		return 0;
	}

	int s = 0;
	int e = s + A - 1;
	while (e < danger){
		int bef = s;
		int aft = danger - e - 1;
		if (bef >= 2*B || aft >= 2*B){
			++s;++e;
			continue;
		}
		if ((bef < A  && bef >= B)|| (aft < A && aft >= B)){
			++s;++e;
			continue;
		}
		int t = b;
		if (bef >= A)++t;
		if (aft >= A)++t;
		if (t%2 == 0){
			return 1;
		}
		++e;++s;
	}
	return 0;
}

int main(){
	cin>>T;
	while(T--){
		V.clear();
		V2.clear();
		cin>>A>>B>>S;
		if (run())cout<<"YES\n";
		else cout<<"NO\n";
	}
}