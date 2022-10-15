#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const int MAXN = 1024;
const int MAXL = 10;

int N,X,Y;
vi queries[MAXL];
int res[MAXL];
int blk[MAXN];

int main(){
	cin>>N>>X>>Y;
	int Z=X^Y;
	for (int i=0;i<MAXL;++i){
		for (int j=1;j<=N;++j)if(j&(1<<i)){
			queries[i].pb(j);
		}
		// for (auto t:queries[i])cout<<t<<' ';cout<<endl;
	}
	int st = 0;
	for (;st<MAXL;++st){
		cout<<"? "<<SZ(queries[st])<<' ';for (auto x:queries[st])cout<<x<<' ';cout<<endl;
		int t;
		cin>>t;
		// If they are in different sides
		if (t == Y || t == Z){
			break;
		}
	}
	deque<int> T;
	for (auto x:queries[st])T.pb(x);
	// Break and resolve
	while (SZ(T) > 1){
		int H = SZ(T)/2;
		cout<<"? "<<H<<' ';
		for (int i=0;i<H;++i)cout<<T[i]<<' ';cout<<endl;
		int t;cin>>t;
		if (t == Y || t == Z){//inside
			while (SZ(T) > H)T.pop_back();
		}else{
			for (int i=0;i<H;++i)T.pop_front();
		}
	}
	int l = T[0];
	for (int x=0;x<st;++x){
		int is_l = 0;
		for (auto i : queries[x])if (i == l)is_l=1;
		if (is_l == 0)for (auto i : queries[x])blk[i]++;
		else {
			for (int i=1;i<=N;++i)blk[i]++;
			for (auto t:queries[x])blk[t]--;
		}
	}
	int is_l = 0;
	for (auto i : queries[st])if (i == l)is_l=1;
	if (is_l == 1)for (auto i : queries[st])blk[i]++;
	else {
		for (int i=1;i<=N;++i)blk[i]++;
		for (auto t:queries[st])blk[t]--;
	}
	T.clear();
	for (int i=1;i<=N;++i)if(blk[i] == 0&&i!=l)T.pb(i);
	// for (auto i : T)cout<<i<<' ';cout<<endl;
	// Break and resolve
	while (SZ(T) > 1){
		int H = SZ(T)/2;
		cout<<"? "<<H<<' ';
		for (int i=0;i<H;++i)cout<<T[i]<<' ';cout<<endl;
		int t;cin>>t;
		if (t == Y || t == Z){
			while (SZ(T) > H)T.pop_back();
		}else{
			// Not inside
			for (int i=0;i<H;++i)T.pop_front();			
		}
	}
	if (l>T[0])cout<<"! "<<T[0]<<' '<<l<<endl;
	else cout<<"! "<<l<<' '<<T[0]<<endl;
}