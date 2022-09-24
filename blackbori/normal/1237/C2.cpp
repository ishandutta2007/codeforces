#include <bits/stdc++.h>

using namespace std;

struct point{
	int x, y, z, i;
	point() : i(-1) {}
	point(int x, int y, int z, int i) : x(x), y(y), z(z), i(i) {}
};

vector <point> V;
int n;

point solve1d(vector <point> &X)
{
	int i;
	
	for(i=0; i+1<X.size(); i+=2){
		cout << X[i].i << " " << X[i + 1].i << "\n";
	}
	
	if(X.size() & 1) return X.back();
	else return point();
}

point solve2d(vector <point> &X)
{
	vector <point> Y, Z;
	int i, j;
	
	for(i=0; i<X.size(); i=j){
		Y.clear();
		for(j=i; j<X.size() && X[j].y == X[i].y; j++){
			Y.push_back(X[j]);
		}
		point p = solve1d(Y);
		if(p.i != -1) Z.push_back(p);
	}
	
	for(i=0; i+1<Z.size(); i+=2){
		cout << Z[i].i << " " << Z[i + 1].i << "\n";
	}
	
	if(Z.size() & 1) return Z.back();
	else return point();
}

void solve3d(vector <point> &X)
{
	vector <point> Y, Z;
	int i, j;
	
	for(i=0; i<X.size(); i=j){
		Y.clear();
		for(j=i; j<X.size() && X[j].z == X[i].z; j++){
			Y.push_back(X[j]);
		}
		point p = solve2d(Y);
		if(p.i != -1) Z.push_back(p);
	}
	
	for(i=0; i+1<Z.size(); i+=2){
		cout << Z[i].i << " " << Z[i + 1].i << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int x, y, z, i;
	
	cin >> n;
	
	for(i=0; i<n; i++){
		cin >> x >> y >> z;
		V.emplace_back(x, y, z, i + 1);
	}
	
	sort(V.begin(), V.end(), [&](point &pa, point &pb){
		return tuple <int, int, int> (pa.z, pa.y, pa.x) <
			tuple <int, int, int> (pb.z, pb.y, pb.x);
	});
	
	solve3d(V);
	
	return 0;
}