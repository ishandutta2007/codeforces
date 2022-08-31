// pick a random line and see if it splits into 
#include <bits/stdc++.h>
using namespace std;

using ll = int;
using point = complex<ll>;

ll cross(point const&a, point const&b){
	return (conj(a)*b).imag();
}

int sign(ll x){
	return (x>0) - (x<0);
}

int ccw(point const&a, point const&b){
	return sign(cross(a, b));
}
int ccw(point const&a, point const&b, point const&c){
	return ccw(b-a, c-a);
}

vector<int> out;

mt19937 rng(1992353);

int get_rand(int b){
	return uniform_int_distribution<int>(0, b-1)(rng);
}

void rec(vector<pair<point, int> >  &&A, vector<pair<point, int> > &&B){
	assert(A.size() == B.size());
	int k = A.size();
	if(k==0){
		return;
	}
	if(k==1){
		out[A[0].second] = B[0].second;
		return;
	}
	for(;;){
		int x = get_rand(k), y = get_rand(k);
		point const&a = A[x].first, b = B[y].first;
		int A_l = 0, B_l = 0;
		for(auto &e:A){
			A_l += (ccw(a, b, e.first) < 0);
		}
		for(auto &e:B){
			B_l += (ccw(a, b, e.first) < 0);
		}
		//cerr << x << "/" <<y << " | " << a << " " << b << " : " << A_l << " / " << B_l << "\n";
		if(A_l == B_l){
			array<vector<pair<point, int> >, 3> A_sub, B_sub;
			for(auto &e:A){
				A_sub[ccw(a, b, e.first)+1].push_back(e);
			}
			for(auto &e:B){
				B_sub[ccw(a, b, e.first)+1].push_back(e);
			}
			/*for(int i=0;i<3;++i){
				cerr << i << " | " << A_sub[i].size() <<  " " << B_sub[i].size() << "\n";
				for(auto &e:A_sub[i]){
					cerr << "    " << e.first << "\n";
				}
				cerr << "-----\n";
				for(auto &e:B_sub[i]){
					cerr << "    " << e.first << "\n";
				}
			}*/
			assert(A_sub[1].size() == 1 && B_sub[1].size() == 1);
			for(int i=0;i<3;++i){
				rec(move(A_sub[i]), move(B_sub[i]));
			}
			return;
		}
	}
	
}


signed main(){
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	out.assign(n, -1);
	vector<pair<point, int> > A(n), B(n);
	for(int i=0;i<n;++i){
		auto &e=A[i];
		int x, y;
		cin >> x >> y;
		e.first = {x, y};
		e.second = i;
	}
	for(int i=0;i<n;++i){
		auto &e=B[i];
		int x, y;
		cin >> x >> y;
		e.first = {x, y};
		e.second = i;
	}
	rec(move(A), move(B));
	for(auto &e:out){
		cout << 1+e << "\n";
	}
}