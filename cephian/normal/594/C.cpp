#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 1e5+5;
ll x[N],y[N];

int X[N],Y[N];

bool cmpx(int i, int j) {
	return x[i] < x[j];
}

bool cmpy(int i, int j) {
	return y[i] < y[j];
}

vi xl,xh,yl,yh;
int used[N]={0};

int do_count(const vi& v, ll* p, int l, int r, int d) {
	int b=0;
	for(int i = 0; p[v[i]] < l || r < p[v[i]]; ++i) {
		// if(used[v[i]] == 0) {
		// 	cout << "marking " << v[i] << endl;
		// }
		b += used[v[i]] == 0;
		used[v[i]]+=d;
	}
	return b;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n,k;
	cin >> n >> k;
	for(int i = 0; i < n; ++i) {
		ll a,b,c,d;
		cin >> a >> b >> c >> d;
		x[i] = a+c;
		y[i] = b+d;
		X[i] = Y[i] = i;
	}

	sort(X,X+n,cmpx);
	sort(Y,Y+n,cmpy);
	for(int i = 0; i <= k; ++i) {
		xl.push_back(X[i]);
		xh.push_back(X[n-1-i]);
		yl.push_back(Y[i]);
		yh.push_back(Y[n-1-i]);
	}
	ll best = 0x7fffffffffffffffLL;
	for(int a = 0; a <= k; ++a) {
		for(int b = 0; b <= k; ++b) {
			for(int c = 0; c <= k; ++c) {
				for(int d = 0; d <= k; ++d) {
					int x_l = x[xl[a]];
					int x_h = x[xh[b]];
					int y_l = y[yl[c]];
					int y_h = y[yh[d]];
					if(x_h < x_l) continue;
					if(y_h < y_l) continue;
					
					int A = do_count(xl,x,x_l,x_h,1);
					int B = do_count(xh,x,x_l,x_h,1);
					int C = do_count(yl,y,y_l,y_h,1);
					int D = do_count(yh,y,y_l,y_h,1);

					if(A+B+C+D <= k) {
						ll nx = x_h - x_l;
						ll ny = y_h - y_l;
						nx += nx==0;
						ny += ny==0;
						nx += nx&1;
						ny += ny&1;
						best = min(best,nx*ny/4);
					}
					do_count(xl,x,x_l,x_h,-1);
					do_count(xh,x,x_l,x_h,-1);
					do_count(yl,y,y_l,y_h,-1);
					do_count(yh,y,y_l,y_h,-1);
					
				}
			}
		}
	}
	cout << best << "\n";
	return 0;
}