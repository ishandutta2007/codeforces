#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <cassert>
#include <set>
#include <queue>
using namespace std;

const int MAXN = 200;
const int MAXV = MAXN * MAXN;
const int MAXE = MAXV * 6;
const double eps = 1e-8;

int sign(double x) {
	return x < -eps ? -1 : x > eps;
}

struct Point {
	double x, y;
	
	Point(int x, int y) : x(x), y(y) {}
	Point() {}
	
	Point &operator +=(const Point &o) {
		x += o.x;
		y += o.y;
		return *this;
	}
	
	Point &operator -=(const Point &o) {
		x -= o.x;
		y -= o.y;
		return *this;
	}
	
	Point &operator *=(double k) {
		x *= k;
		y *= k;
		return *this;
	}
	
	Point &operator /=(double k) {
		x /= k;
		y /= k;
		return *this;
	}
	
	double norm2() const {
		return x * x + y * y;
	}
	
	double norm() const {
		return sqrt(norm2());
	}
	
	double arg() const {
		return atan2(y, x);
	}
	
	bool on(const Point &, const Point &) const;
	bool in(const vector<Point> &) const;
};

bool operator <(const Point &a, const Point &b) {
	return sign(a.x - b.x) < 0 || sign(a.x - b.x) == 0 && sign(a.y - b.y) < 0;
}

bool operator ==(const Point &a, const Point &b) {
	return sign(a.x - b.x) == 0 && sign(a.y - b.y) == 0;
}

Point operator +(Point a, const Point &b) {
	return a += b;
}

Point operator -(Point a, const Point &b) {
	return a -= b;
}

Point operator /(Point a, double k) {
	return a /= k;
}

Point operator *(Point a, double k) {
	return a *= k;
}

Point operator *(double k, Point a) {
	return a *= k;
}

double det(const Point &a, const Point &b) {
	return a.x * b.y - b.x * a.y;
}

double dot(const Point &a, const Point &b) {
	return a.x * b.x + a.y * b.y;
}

bool parallel(const Point &a, const Point &b, const Point &c, const Point &d) {
	return sign(det(b - a, d - c)) == 0;
}

Point intersect(const Point &a, const Point &b, const Point &c, const Point &d) {
	double s1 = det(b - a, c - a);
	double s2 = det(b - a, d - a);
	return (c * s2 - d * s1) / (s2 - s1);
}

bool Point::on(const Point &a, const Point &b) const {
	const Point &p = *this;
	return sign(det(p - a, p - b)) == 0 && sign(dot(p - a, p - b)) <= 0;
} 

bool Point::in(const vector<Point> &polygon) const {
	const Point &p = *this;
	int n = polygon.size();
	int count = 0;
	for (int i = 0; i < n; ++ i) {
		const Point &a = polygon[i];
		const Point &b = polygon[(i + 1) % n];
		if (p.on(a, b)){
			return false;
		}
		int t0 = sign(det(a - p, b - p));
		int t1 = sign(a.y - p.y);
		int t2 = sign(b.y - p.y);
		count += t0 > 0 && t1 <= 0 && t2 > 0;
		count -= t0 < 0 && t2 <= 0 && t1 > 0;
	}
	return count != 0;
}

struct eglist {
	int other[MAXE], succ[MAXE], last[MAXE], sum;
	set<pair<int, int> > Edges; 
	void clear() {
		memset(last, -1, sizeof(last));
		sum = 0;
		Edges.clear();
	}
	void addEdge(int a, int b) {
		if (Edges.count(make_pair(a, b)))
			return;
		Edges.insert(make_pair(a, b));
		other[sum] = b, succ[sum] = last[a], last[a] = sum;
		sum++;
	}
	void _addEdge(int a, int b) {
		addEdge(a, b);
		addEdge(b, a);
	}
}e, topo;

vector<Point> Points;

Point segments[MAXE][2];
double W, H;
int n, next[MAXE];
vector<double> areas, allAreas;
vector<vector<Point> > regions;

void addSegment(Point a, Point b) {
	segments[n][0] = a;
	segments[n][1] = b;
	n++;
}

int getPointID(const Point &p) {
	return lower_bound(Points.begin(), Points.end(), p) - Points.begin();
}

const int VERTEX = 0;
const int EDGE = 1;
const int REGION = 2;

int getID(int type, int id) {
	if (type == VERTEX) {
		return id;
	}
	if (type == EDGE) {
		return id + Points.size();
	}
	if (type == REGION) {
		return id + Points.size() + e.sum / 2;
	}
	assert(false);
}

double getArea(int id) {
	id -= Points.size() + e.sum / 2;
	return id < 0 ? 0 : areas[id];
}

int locate(const Point &p) {
	for (int i = 0; i < e.sum; i += 2) {
		if (p.on(Points[e.other[i]], Points[e.other[i ^ 1]])) {
			return getID(EDGE, i >> 1);
		}
	}
	int best = -1;
	for (int i = 0; i < regions.size(); ++i) {
		if (p.in(regions[i]) && (best == -1 || allAreas[best] > allAreas[i])) {
			best = i;
		}
	}
	return getID(REGION, best);
}

vector<string> colorNames;
map<string, int> colorIDs;

int getColorID(const char *color) {
	if (!colorIDs.count(color)) {
		colorNames.push_back(color);
		int newID = colorIDs.size();
		colorIDs[color] = newID;
	}
	return colorIDs[color];
}

int color[MAXV * 10];

void paint(const Point &p, const char * c) {
	int start = locate(p);
	int old = color[start];
	int cid = getColorID(c);
	if (old == cid)
		return;
	queue<int> q;
	q.push(start);
	color[start] = cid;
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = topo.last[x]; ~i; i = topo.succ[i]) {
			int y = topo.other[i];
			if (color[y] == old) {
				color[y] = cid;
				q.push(y);
			}
		}
	}
}

int main() {
	scanf("%lf %lf %d", &W, &H, &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf %lf %lf %lf", &segments[i][0].x, &segments[i][0].y, &segments[i][1].x, &segments[i][1].y);
	}
	addSegment(Point(0, 0), Point(W, 0));
	addSegment(Point(W, 0), Point(W, H));
	addSegment(Point(W, H), Point(0, H));
	addSegment(Point(0, H), Point(0, 0));
	
	for (int i = 0; i < n; i++) {
		Points.push_back(segments[i][0]);
		Points.push_back(segments[i][1]);
		for (int j = 0; j < i; j++) {
			if (!parallel(segments[i][0], segments[i][1], segments[j][0], segments[j][1])) {
				Point p = intersect(segments[i][0], segments[i][1], segments[j][0], segments[j][1]);
				if (p.on(segments[i][0], segments[i][1]) && p.on(segments[j][0], segments[j][1])) {
					Points.push_back(p);
				}
			}
		}
	}
	sort(Points.begin(), Points.end());
	Points.erase(unique(Points.begin(), Points.end()), Points.end());
	
	e.clear();
	for (int i = 0; i < n; i++) {
		vector<pair<double, int> > pairs;
		for (int j = 0; j < Points.size(); j++) {
			if (Points[j].on(segments[i][0], segments[i][1]))
				pairs.push_back(make_pair((Points[j] - segments[i][0]).norm(), j));
		}
		sort(pairs.begin(), pairs.end());
		for (int i = 1; i < pairs.size(); i++) {
			e.addEdge(pairs[i - 1].second, pairs[i].second);
			e.addEdge(pairs[i].second, pairs[i - 1].second);
		}
	}
	
	for (int u = 0; u < Points.size(); u++) {
		vector<pair<double, int> > pairs;
		for (int iter = e.last[u]; ~iter; iter = e.succ[iter]) {
			pairs.push_back(make_pair((Points[e.other[iter]] - Points[u]).arg(), iter));
		}
		sort(pairs.begin(), pairs.end());
		for(int i = 0; i < pairs.size(); i++) {
			next[pairs[(i + 1) % pairs.size()].second ^ 1] = pairs[i].second;
		}
	}
	
	vector<pair<Point, double> > waits;
	static bool visit[MAXV];
	memset(visit, 0, sizeof(visit));
	for (int start = 0; start < e.sum; ++start) {
		if (!visit[start]) {
			int v = start;
			double totalArea = 0;
			vector <Point> region;
			for(; !visit[v]; v = next[v]) {
				visit[v] = true;
				totalArea += det(Points[e.other[v ^ 1]], Points[e.other[v]]);
				region.push_back(Points[e.other[v]]);
			}
			
			if (sign(totalArea) > 0) {
				regions.push_back(region);
				areas.push_back(totalArea);
				allAreas.push_back(totalArea);
			} else {
				waits.push_back(make_pair(region.front(), -totalArea));
			}
		}
	}
	
	//build
	topo.clear();
	for (int i = 0; i < e.sum; i++) {
		topo._addEdge(getID(EDGE, i >> 1), getID(VERTEX, e.other[i]));
	}
	for (int i = 0; i < regions.size(); i++) {
		topo._addEdge(getID(REGION, i), getID(VERTEX, getPointID(regions[i].front())));
	}
	for (int iter = 0; iter < waits.size(); iter++) {
		const Point &p = waits[iter].first;
		int best = -1;
		for (int i = 0; i < regions.size(); i++) {
			if (p.in(regions[i]) && (best == -1 || allAreas[best] > allAreas[i])) {
				best = i;
			}
		}
		if (best != -1) {
			areas[best] -= waits[iter].second;
			topo._addEdge(getID(REGION, best), getID(VERTEX, getPointID(p)));
		}
	}
	
	
	getColorID("white");
	getColorID("blake");
	getColorID("__COLOR__");
	
	for (int i = 0; i < regions.size(); i++) {
		color[getID(REGION, i)] = getColorID("white");
	}
	for (int i = 0; i < Points.size(); i++) {
		color[getID(VERTEX, i)] = getColorID("black");
	}
	for(int i = 0; i < e.sum / 2; i++) {
		color[getID(EDGE, i)] = getColorID("black");
	}
	paint(Point(0, 0), "__COLOR__");
	int m;
	scanf("%d", &m);
	while (m --) {
		Point p;
		char buffer[16];
		scanf("%lf %lf %s", &p.x, &p.y, buffer);
		paint(p, buffer);
	}
	
	map<string, double> answer;
	for (int i = 0; i < Points.size() + (e.sum >> 1) + regions.size(); ++i) {
		const string &name = colorNames[color[i]];
		if (name != "__COLOR__") {
			answer[name] += getArea(i);
		}
	}
	for (map<string, double> :: iterator iter = answer.begin(); iter != answer.end(); ++ iter) {
		printf("%s %.8lf\n", iter->first.c_str(), 0.5 * iter->second);
	}
}