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
#define MAXL 20

vi des;
set<pi> S;
int N,a,b;
vpi V;

int main(){
	cin>>N;
	for (int i=0;i<N;++i){
		cin>>a>>b;
		des.pb(a);
		des.pb(b);
		V.pb(a,b);
	}
	sort(ALL(des));
	des.resize(unique(ALL(des)) - des.begin());
	for (auto &i : V){
		i.f = lb(ALL(des), i.f)-des.begin();
		i.s = lb(ALL(des), i.s)-des.begin();
	}
	S.insert(mp(-1,-1));
	S.insert(mp(1000000, 1000000));
	for (auto i : V){
		int s = i.f;
		int e = i.s;
		while (1){
			auto x = --S.ub(mp(i.f,1000100));
			// cout<<"Lower "<<x->f<<' '<<x->s<<'\n';
			if (x->s >= i.f){
				s = min(s, x->f);
				e = max(e, x->s);
				S.erase(x);
				// cout<<"Erase L "<<x->f<<' '<<x->s<<'\n';
			}
			else break;
		}
		while (1){
			auto x = --S.ub(mp(i.s,1000100));
			if (x->f >= i.f){
				e = max(e, x->s);
				S.erase(x);
				// cout<<"Erase U "<<x->f<<' '<<x->s<<'\n';
			}
			else break;
		}
		S.insert(mp(s,e));
		// cout<<"Insert "<<s<<' '<<e<<'\n';
		cout<<SZ(S)-2<<' ';
		// return 0;	
	}
}