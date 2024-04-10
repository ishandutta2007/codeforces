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
const int MAXN = 100100;
const int MAXL = 3100;

struct StaticSum{
	int M;
	int A[MAXL][MAXL];
	StaticSum(int _M):M(_M){}
	void fill(){
		for (int i=1;i<=M;++i)for (int j=1;j<=M;++j){
			A[i][j] = A[i][j] + A[i-1][j] + A[i][j-1] - A[i-1][j-1];
		}
	}
	int query(pi a, pi b){
		return A[b.f][b.s] - A[a.f-1][b.s] - A[b.f][a.s-1] + A[a.f-1][a.s-1];
	}
}*A,*B,*C,*D,*E;

int G[MAXL][MAXL];
pi L[MAXN];
pi R[MAXN];
int out[MAXN];
int N,a,b,c,d;
vpi starts[2*MAXL];
vpi stop[2*MAXL];
int off = 3001;

int main(){
	cin>>N;
	ll M = 0;
	for (int i=1;i<=N;++i){
		cin>>L[i].f>>L[i].s>>R[i].f>>R[i].s;
		++L[i].f;++L[i].s;
		if (L[i].f == R[i].f && L[i].s == R[i].s){
			cout<<"YES 1\n"<<i<<'\n';
			return 0;
		}
		M = max({M,L[i].f,L[i].s,R[i].f,R[i].s});
	}

	A = new StaticSum(M);
	B = new StaticSum(M);
	C = new StaticSum(M);
	D = new StaticSum(M);
	E = new StaticSum(M);

	for (int i=1;i<=N;++i){
		for (int a=L[i].f;a<=R[i].f;++a){
			for (int b=L[i].s;b<=R[i].s;++b){
				assert(G[a][b] == 0);
				G[a][b] = i;
				A->A[a][b] = 1;
			}
		}
		for (int a=L[i].f;a<=R[i].f;++a){
			B->A[a][L[i].s]++;
			C->A[a][R[i].s]++;
		}
		for (int a=L[i].s;a<=R[i].s;++a){
			D->A[L[i].f][a]++;
			E->A[R[i].f][a]++;
		}
	}

	A->fill();B->fill();C->fill();D->fill();E->fill();

	for (int i=1;i<=N;++i){
		// if(i!=6)continue;
		pi lh = L[i];
		int l = L[i].s - L[i].f+off;
		int llb = 0; int upb = M;
		while (upb > llb){
			// cerr<<llb<<' '<<upb<<'\n';
			int mid = (upb+llb+1)/2;
			// //cout<<"Ask "<<mid<<'\n';
			int can = 1;
			pi rh = mp(L[i].f+mid, L[i].s+mid);
			if (rh.f>M||rh.s>M)can = 0;
			// //cout<<rh.f<<' '<<rh.s<<'\n';
			else if (A->query(lh, rh) != (mid+1)*(mid+1))can = 0;
			else if (D->query(mp(lh.f, lh.s), mp(lh.f, rh.s)) != mid+1)can=0;
			else if (B->query(mp(lh.f, lh.s), mp(rh.f, lh.s)) != mid+1)can=0;
			if (can)llb = mid;
			else upb = mid-1;
		}
		// cout<<"Starting at "<<L[i].f<<' '<<L[i].s<<" maximum length "<<llb<<'\n';
		starts[l].pb(L[i].f , llb);

		int r = R[i].s - R[i].f+off;
		pi rh = R[i];
		l = R[i].f-R[i].s+off;
		llb=0;upb=M;
		while (upb > llb){
			// cerr<<llb<<' '<<upb<<'\n';
			int mid = (upb+llb+1)/2;
			// //cout<<"Ask "<<mid<<'\n';
			int can = 1;
			pi lh = mp(R[i].f-mid, R[i].s-mid);
			// //cout<<lh.f<<' '<<lh.s<<'\n';
			if (lh.f<=0||lh.s<=0)can = 0;
			else if (A->query(lh, rh) != (mid+1)*(mid+1))can = 0;
			else if (C->query(mp(lh.f, rh.s), mp(rh.f, rh.s)) != mid+1)can=0;
			else if (E->query(mp(rh.f, lh.s), mp(rh.f, rh.s)) != mid+1)can=0;
			if (can)llb = mid;
			else upb = mid-1;
		}

		// //cout<<"Ending at "<<R[i].f<<' '<<R[i].s<<" maximum length "<<llb<<'\n';
		stop[r].pb(llb, i);
	}

	int answer = -1;
	int leftmost[MAXN];

	for (int grad = -M; grad <= M;++grad){
		if (answer!=-1)break;
		int corr = grad + off;
		if (corr < 0 || corr > 6200)continue;
		// //cout<<SZ(starts[corr])<<' '<<SZ(stop[corr])<<'\n';
		// cout<<corr<<'\n';
		vpi V;

		for (auto t:stop[corr]){
			pi r = R[t.s];
			int minleft = r.f - t.f;
			leftmost[t.s] = minleft;
			V.pb(minleft, t.s);
		}

		sort(ALL(V)); reverse(ALL(V));
		sort(ALL(starts[corr]));

		// for (auto i : V){
		// 	//cout<<"Latest left "<<i.f<<" index "<<i.s<<'\n';
		// }

		set<pi> S;
		priority_queue<pi, vpi, greater<pi>> pq;

		for (auto x : starts[corr]){
			int leftind = x.f;
			int maxright = x.s+leftind;
			// cout<<"Currently at "<<leftind<<' '<<maxright<<'\n';
			// Add everything that can accomodate
			while (SZ(V) && V.back().f <= leftind){
				// Index = V.back().s
				int i = V.back().s;
				// Leftmost position is V.back().f
				S.insert(mp(R[i].f, i));
				// cout<< "Adding index "<<i<<'\n';
				pq.emplace(R[i].f, i);
				V.pop_back();
			}
			while (SZ(pq) && pq.top().f <= leftind){
				int i = pq.top().s; pq.pop();
				S.erase(mp(R[i].f, i));
				//cout<<"Removing index "<<i<<'\n';
			}
			if (!SZ(S))continue;
			pi t = *(S.begin());
			assert(t.f >= leftind);
			assert(leftmost[t.s] <= leftind);
			assert(t.f == R[t.s].f);
			// cout<<t.f<<' '<<maxright<<'\n';
			if (t.f>maxright)continue;
			assert( t.f <= maxright);

			answer = 1;

			for (int a=leftind;a<=R[t.s].f;++a){
				for (int b=leftind+grad;b<=R[t.s].s;++b){
					out[G[a][b]] = 1;
				}
			}
			// if (N <100)continue;
			// cout<<"Right "<<R[t.s].f<<' '<<R[t.s].s<<'\n';
			// cout<<"Left "<<leftind<<' '<<leftind+grad<<'\n';
		}
	}

	// int ok = 0;
	// for (int x=1;x<=N;++x){
	// 	for (int y=1;y<=N;++y){
	// 		if (ok)continue;
	// 		pi a = L[x];
	// 		pi b = R[y];
	// 		if (a.f>b.f)swap(a,b);
	// 		if (a.s>b.s)continue;
	// 		if ((b.s-a.s) != (b.f-a.f))continue;
	// 		int area = (b.s-a.s+1) * (b.f-a.f+1);
	// 		int t = A->query(a,b);
	// 		if (t!=area)continue;
	// 		int len = (b.f-a.f+1);
			// if (B->query(mp(a.f, a.s), mp(b.f, a.s)) != len)continue;
			// if (C->query(mp(a.f, b.s), mp(b.f, b.s)) != len)continue;
			// if (D->query(mp(a.f, a.s), mp(a.f, b.s)) != len)continue;
			// if (E->query(mp(b.f, a.s), mp(b.f, b.s)) != len)continue;
	// 		// //cout<<a.f<<' '<<a.s<<' '<<b.f<<' '<<b.s<<'\n';
	// 		ok = 1;
			// for (int a=L[x].f;a<=R[y].f;++a){
			// 	for (int b=L[x].s;b<=R[y].s;++b){
			// 		out[G[a][b]] = 1;
			// 	}
			// }
	// 	}
	// }
	if (answer == -1){
		cout<<"NO";
		return 0;
	}
	int ans = 0;
	for (int i=1;i<=N;++i)if(out[i])++ans;
	cout<<"YES ";cout<<ans<<'\n';
	for (int i=1;i<=N;++i)if(out[i])cout<<i<<' ';
}