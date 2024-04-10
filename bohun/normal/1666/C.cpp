#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define x first
#define y second
#define f first
#define s second
#define pb push_back
using point = pair <int,int>;

const int inf = 1000000005;

point p[3];

void flip(point& p){
	p.y = -p.y;
}

int main()
{
	rep(i, 0, 2){
		scanf("%d%d", &p[i].x, &p[i].y);
	}
	
	point a = {inf, inf};
	point c = {-inf, -inf};
	
	rep(i, 0, 2){
		a = min(a, p[i]);
		c = max(c, p[i]);
	}

	point b;

	rep(i, 0, 2){
		if (p[i] != a && p[i] != c){
			b = p[i];
		}
	}
	
	assert(a.x <= b.x && b.x <= c.x);

	//printf("(%d,%d), (%d,%d), (%d,%d)\n", a.x, a.y, b.x, b.y, c.x, c.y);

	bool flipped = false;

	if (a.y > c.y){
		flip(a);
		flip(b);
		flip(c);
		flipped = true;
	}


	assert(a.y <= c.y);

	vector < pair <point, point> > out;

	if (b.y <= a.y){
		point d = point(c.x, a.y);
		out.pb({a, d});
		out.pb({d, c});
		point e = point(b.x, a.y);
		out.pb({b, e});
	}else if(b.y >= c.y){
		point d = point(a.x, c.y);
		out.pb({a, d});
		out.pb({d, c});
		point e = point(b.x, c.y);
		out.pb({b, e});
	}else{
		point d = point(b.x, a.y);
		point e = point(c.x, b.y);
		out.pb({a, d});
		out.pb({d, b});
		out.pb({b, e});
		out.pb({e, c});
	}
	
	if (flipped){
		for (pair <point, point>& p : out){
			flip(p.f);
			flip(p.s);
		}
	}
	
	vector < pair <point, point> > vec;

	for (auto p : out){
		if (p.f != p.s)
			vec.pb(p);
	}

	printf("%d\n", (int)(vec.size()));
	
	for (auto p : vec){
		printf("%d %d %d %d\n", p.f.x, p.f.y, p.s.x, p.s.y);
	}

	return 0;
}