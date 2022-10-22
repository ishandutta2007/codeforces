#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;


#define PI (3.1415926535897932384626433832795028)

#define rad(x) (x / 180.0 * PI)

typedef double Real;
typedef pair<Real, Real> P;

Real len[324000];
Real deg[324000];

struct segnode{
	P place;
	Real deg;
	segnode(P p = P(0,0), Real d = 0){
		place = p;
		deg = d;
	}
	
	segnode operator+(segnode x){
		Real xx = x.place.first;
		Real yy = x.place.second;
		Real dd = x.deg;
		Real rdeg = deg + dd;
		P rp = P(place.first + xx*cos(rad(deg)) - yy * sin(rad(deg)),
				place.second + xx*sin(rad(deg)) + yy * cos(rad(deg)));
		return segnode(rp, rdeg); 
	}
	
};

segnode seg[1 << 20];
segnode ng = segnode(P(0, 0), 0);

segnode solve(int left, int right, int bottom = 0, int top = 1 << 19, int pos = 1){
	if(right <= bottom || top <= left)return ng;
	if(left <= bottom && top <= right)return seg[pos];
	int mid = (bottom + top) / 2;
	return solve(left, right, bottom, mid, pos * 2) + solve(left, right, mid, top, pos * 2 + 1);
}

segnode solve2(int zero, int x){
	segnode res;
	for(int i = 0;i < x;i++){
		res = res + seg[i + (1 << 19)];
	}
	return res;
}

int main(){
	int n, q, x, y, op;
	cin >> n >> q;
	for(int i = 0;i < n;i++){
		len[i] = 1;
		deg[i] = 0;
		seg[(1<<19) + i] = segnode(P(1, 0), 0);
	}
	for(int i = (1 << 19) - 1;i > 0;i--){
		seg[i] = seg[i*2] + seg[i*2+1];
	}
	
	for(int i = 0;i < q;i++){
		cin >> op >> x >> y;x--;
		if(op == 1){
			len[x] += y;			
		}
		if(op == 2){
			deg[x] -= y;
		}
		int xx = x;
		seg[x + (1 << 19)] = segnode(P(len[x] * cos(rad(deg[x])), len[x] * sin(rad(deg[x]))), deg[x]);
		x += 1 << 19;
		while(x /= 2){
			seg[x] = seg[x*2] + seg[x*2+1];
		}
		for(int i = n;i <= n;i++){
			P tmp = solve(0, i).place;
			printf("%.10lf %.10lf\n", tmp.first, tmp.second);
		}
	}
	return 0;
}