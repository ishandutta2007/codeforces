#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int>	Point;
#define X first
#define Y second

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dis(Point a, Point b){return (a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y);}

bool ok(Point a, Point b, Point c){
	vector<int>	dist;
	dist.push_back(dis(a, b));
	dist.push_back(dis(a, c));
	dist.push_back(dis(b, c));
	sort(dist.begin(), dist.end());
	return dist[0] + dist[1] == dist[2] && dist[0];
}

int main(){
	Point a, b, c;
	cin >> a.X >> a.Y >> b.X >> b.Y >> c.X >> c.Y;
	if (ok(a, b, c))
		cout << "RIGHT\n";
	else{
		for (int w = 0; w < 4; w++)
			if (ok({a.X + dx[w], a.Y + dy[w]}, b, c) || ok(a, {b.X + dx[w], b.Y + dy[w]}, c) || ok(a, b, {c.X + dx[w], c.Y + dy[w]})){
				cout << "ALMOST\n";
				return 0;
			}
		cout << "NEITHER\n";
	}
	return 0;
}