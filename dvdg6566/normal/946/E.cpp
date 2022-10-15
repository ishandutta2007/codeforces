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

bool exists(int len, int bm){
	// cout<<"Query "<<len<<' '<<bm<<'\n';
	int p = __builtin_popcount(bm);
	if (p<=len)return 1;
	return 0;
}

int T,N;
string S;

void generate(int len, int bm, int v){
	for (int i=0;i+len+1<N;++i)cout<<S[i];
	cout<<v;
	int p =__builtin_popcount(bm);
	for (int i=p;p<len;++p)cout<<9;
	for (int i=9;i>=0;--i)if((1<<i) & bm){
		cout<<i;
	}
	cout<<'\n';
}


void query(){
	int bm = 0;
	for (auto i : S){
		int x = i-'0';
		bm ^= (1<<x);
	}
	N=SZ(S);
	int len=0;
	for (int i=N-1;i>=0;--i){
		int x = S[i]-'0';
		bm ^= (1<<x);
		// cout<<x<<' '<<bm<<'\n';
		int st = 0;
		if(i==0)st=1;
		for (int t=x-1;t>=st;--t){
			if (exists(len, bm^(1<<t))){
				generate(len, bm^(1<<t), t);
				return;
			}
		}
		++len;
	}
	if (N == 2){cout<<0;return;}
	for (int i=0;i<N-2;++i){cout<<'9';}cout<<'\n';
}

int main(){
	cin>>T;
	while(T--){
		cin>>S;
		query();
	}
}