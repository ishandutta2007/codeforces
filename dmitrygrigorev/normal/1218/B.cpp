#include <bits/stdc++.h>

using namespace std;
#define db long double

struct pt{int x; int y;};

struct Rectangle{vector<pt> v;};

struct Line{
	db xa; db ya; db xb; db yb; bool is_true;

	Line(){
		is_true = false;
	}

	Line(db a, db b, db c, db d, bool e){
		xa=a, ya=b, xb=c, yb=d, is_true=e;
	}

};

db PI = acos(-1);

db norm(db x){
	while (x < 0) x += 2*PI;
	while (x >= 2*PI) x -= 2*PI;
	return x;
}

bool cmp(pair<int, int> &a, pair<int, int> &b){
	db A = norm(atan2((db) a.second, (db) a.first)), B = norm(atan2((db) b.second, (db) b.first));
	return (A<B);
}

vector<pair<Line, Line> > rmq;
int S;

vector<pair<int, int> > directions;

db gangle;

db eps = 1e-8;

pair<db, db> inter(Line &x){
	db X = cos(gangle), Y = sin(gangle);
	db Q = atan2(1., 3.);
	db v1 = x.xa*Y-x.ya*X;
	db v2 = x.xb*Y-x.yb*X;
	//cout << v1 << " " << v2 << endl;
	if (abs(v1) < eps) return {x.xa, x.ya};
	if (abs(v2) < eps) return {x.xb, x.yb};
	db L = 0, R = 1;
	for (int i=0;i<40; ++i){
		db M = (L+R)/2;
		pair<db, db> var = {x.xa*M+x.xb*(1.-M), x.ya*M+x.yb*(1.-M)};
		db vect = var.first*Y-var.second*X;
		//cout << M << " " << vect << endl;
		if (vect*v1 > 0) R = M;
		else L = M;
	}
	return {x.xa*L+x.xb*(1.-L), x.ya*L+x.yb*(1.-L)};
}

bool cmp2(Line &a, Line &b){
	if (!b.is_true) return true;
	if (!a.is_true) return false;
	pair<db, db> A = inter(a), B = inter(b);
	db Q = sqrt(A.first*A.first+A.second*A.second);
	db T = sqrt(B.first*B.first+B.second*B.second);
	return (Q<T);
}

void ins(pair<Line, Line> &Q, Line &t){
	if (cmp2(Q.first, t) && cmp2(Q.second, t)) return;
	if (cmp2(t, Q.first) && cmp2(Q.second, Q.first)) Q.first = t;
	else Q.second = t;
}

void change(int i, int l, int r, int l1, int r1, Line &t){
	if (l1 >= r1) return;
	if (l==l1 && r==r1){
		db X = atan2((db) directions[l].second, (db) directions[l].first);
		db Y = atan2((db) directions[r%S].second, (db) directions[r%S].first);
		gangle = norm((X+Y)/2);
		ins(rmq[i], t);
		return;
	}
	int mid = (l+r)/2;
	change(2*i+1, l, mid, l1, min(r1, mid), t);
	change(2*i+2, mid, r, max(l1, mid), r1, t);
}

void add(int x, int y, Line &l){
	if (x==y) return;
	y--;
	if (y<0) y += S;
	if (x <= y){
		change(0, 0, S, x, y+1, l);
	}
	else{
		change(0, 0, S, x, S, l);
		change(0, 0, S, 0, y+1, l);
	}
}

db ans = 0;

void print(vector<pair<db, db> > r){
	/*
	for (int i=0;i<4;++i){
		cout << r[i].first << " " << r[i].second << endl;
	}
	*/
	//exit(0);
}

void add_square(vector<pair<db, db> > k){
	if (k.size() == 4){
		print(k);
		add_square({k[0], k[1], k[2]});
		add_square({k[0], k[2], k[3]});
		return;
	}
	db xa = k[1].first-k[0].first, ya = k[1].second-k[0].second, xb = k[2].first - k[0].first, yb = k[2].second-k[0].second;
	db res = abs(xa*yb-xb*ya);
	ans += res/2.;
}

void dfs(int i, int l, int r, pair<Line, Line> t){
	ins(t, rmq[i].first);
	ins(t, rmq[i].second);
	if (r-l==1){
		if (!t.first.is_true || !t.second.is_true) return;
		gangle = norm(atan2((db) directions[l].second, (db) directions[l].first));
		//cout << gangle << endl;
		pair<db, db> A = inter(t.first), B = inter(t.second);
		gangle = norm(atan2((db) directions[r%S].second, (db) directions[r%S].first));
		//cout << gangle << endl;
		pair<db, db> C = inter(t.second), D = inter(t.first);
		vector<pair<db, db> > tut = {A, B, C, D};
		add_square(tut);
		return;
	}
	int mid = (l+r)/2;
	dfs(2*i+1, l, mid, t);
	dfs(2*i+2, mid, r, t);
}

int gcd(int x, int y){
	if (y==0) return x;
	return gcd(y, x%y);
}

main(){
	#ifdef LOCAL
	    freopen("H_input.txt", "r", stdin);
	    //freopen("B_output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<Rectangle> arr;

	for (int i=0;i<n;++i){
		Rectangle t;
		int k;
		cin >> k;
		for (int j=0; j < k; ++j){
			int x, y;
			cin >> x >> y;
			t.v.push_back({x, y});
		}
		arr.push_back(t);
	}

	set<pair<int, int> > possible;

	for (int i=0;i<n;++i) for (int j=0; j < arr[i].v.size(); ++j){
		int x = arr[i].v[j].x, y = arr[i].v[j].y;
		int G = abs(gcd(x, y));
		x /= G, y /= G;
		if (possible.count({x, y})) continue;
		possible.insert({x, y});
		directions.push_back({x, y});
	}

	sort(directions.begin(), directions.end(), cmp);

	map<pair<int, int>, int> indi;
	for (int i=0; i < directions.size(); ++i){
		indi[directions[i]] = i;
		//cout << "!!" << directions[i].first << " " << directions[i].second << endl;
	}

	S = directions.size();
	rmq.assign(4*S, {});

	for (int i=0;i<n;++i){
		int Q = arr[i].v.size();
		for (int j=0; j < Q; j++){
			pt a = arr[i].v[j], b = arr[i].v[(j+1)%Q];
			//cout << a.x << " " << a.y << " " << b.x << " " << b.y << endl;
			if (a.x * b.y - a.y * b.x < 0){
				//cout << 1488 << endl;
				swap(a, b);
			}
			int G1 = abs(gcd(a.x, a.y)), G2 = abs(gcd(b.x, b.y));
			a.x/=G1, a.y/=G1, b.x/=G2, b.y/=G2;
			int A = indi[{a.x, a.y}], B = indi[{b.x, b.y}];
			Line l = {a.x*G1, a.y*G1, b.x*G2, b.y*G2, true};
			//cout << l.xa << " " << l.ya << " " << l.xb << " " << l.yb << endl;
			//cout << A << " " << B << endl;
			add(A, B, l);
		}
	}
	//cout << S << endl;
	pair<Line, Line> Q;
	dfs(0, 0, S, Q);

	cout.precision(10);
	cout << fixed << ans;



}