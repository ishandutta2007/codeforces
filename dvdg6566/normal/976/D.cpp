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
#define MAXN 1010000
#define MAXL 20

int l,r,N,a;
deque<int> A;
int lc,rc;
vpi out;
int chk[MAXN];

int main(){
	cin>>N;
	for (int i=1;i<=N;++i){
		cin>>a;
		A.pb(a);
	}
	int T = A.back();
	l = 0;
	r = A.back();
	while(SZ(A)){
		// cout<<"From  "<<l<<' '<<r<<'\n';
		int t = A.back();
		int c = A.front() - lc;
		rc = A.back();
		// cout<<"Copies "<<c<<'\n';
		for (int i=0;i<c;++i){
			int ind = r - i;
			// cout<<"Ind "<<ind<<'\n';
			for (int j=l;j<ind;++j){
				// cout<<"Draw Edge "<<j<<' '<<ind<<'\n';
				out.pb(ind,j);
			}
		}
		r -= c;
		A.pop_back();
		if (SZ(A) == 0)break;
		lc=A[0];
		t = A[0];
		c = rc - A.back();
		// cout<<"Copes "<<c<<'\n';
		l += c;
		A.pop_front();
	}
	cout<<SZ(out)<<'\n';
	for (auto v : out)cout<<v.f+1<<' '<<v.s+1<<'\n';
	// for (auto v : out){
	// 	chk[v.f+1]++;
	// 	chk[v.s+1]++;
	// }
	// for (int i=1;i<=T+1;++i)cout<<chk[i]<<' ';
}