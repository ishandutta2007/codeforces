#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1e5 + 20;
const ld PI = 3.1415926535897932;

#define X	first
#define Y	second

int n;
pair<ld, ld>	vec[MAXN], sec[MAXN];
bool mark[MAXN];

bool cmp(pair<ld, ld> a, pair<ld, ld>	b)
{
	pair<ld, ld>	center(0, 0);
    if (a.X - center.X >= 0 && b.X - center.X < 0)
        return true;
    if (a.X - center.X < 0 && b.X - center.X >= 0)
        return false;
    if (a.X - center.X == 0 && b.X - center.X == 0) {
        if (a.Y - center.Y >= 0 || b.Y - center.Y >= 0)
            return a.Y > b.Y;
        return b.Y > a.Y;
    }

    ld det = (a.X - center.X) * (b.Y - center.Y) - (b.X - center.X) * (a.Y - center.Y);
    if (det < 0)
        return true;
	if (det > 0)
		return false;

	ld d1 = (a.X - center.X) * (a.X - center.X) + (a.Y - center.Y) * (a.Y - center.Y);
    ld d2 = (b.X - center.X) * (b.X - center.X) + (b.Y - center.Y) * (b.Y - center.Y);
    return d1 > d2;
}

bool ec(pair<ld, ld>	a, pair<ld, ld>	b){
	pair<ld, ld>	center(0, 0);
    if (a.X - center.X >= 0 && b.X - center.X < 0)
        return false;
    if (a.X - center.X < 0 && b.X - center.X >= 0)
        return false;
    if (a.X - center.X == 0 && b.X - center.X == 0) {
        if (a.Y - center.Y >= 0 || b.Y - center.Y >= 0)
            return false;
        return false;
    }

    ld det = (a.X - center.X) * (b.Y - center.Y) - (b.X - center.X) * (a.Y - center.Y);
    if (det < 0)
        return false;
	if (det > 0)
		return false;

	return	true;
}

ld cal(int a, int b){
	ld ret = (vec[a].X - vec[b].X) * (vec[a].X - vec[b].X);
	ret += (vec[a].Y - vec[b].Y) * (vec[a].Y - vec[b].Y);
	return	sqrt(ret);
}

ld get(int b, int c, int a = n){
	ld ret = acos((cal(a, b) * cal(a, b) + cal(a, c) * cal(a, c) - cal(b, c) * cal(b, c))
			/ (cal(a, b) * cal(a, c) * (ld)2.0));

	ll t = vec[b].X * vec[c].Y - vec[b].Y * vec[c].X;
	if (t == 0){
		if (b < c)	return	ret * (ld)180.0/PI;
		return	(ld)360.0 - ret * (ld)180/PI;
	}
	if (t <= 0)
		return	ret * (ld)180.0/PI;
	return	(ld)360.0 - ret * (ld)180/PI;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(12);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> vec[i].first >> vec[i].second;
	int zz = vec[0].first;
	sort(vec, vec + n, cmp);
	for (int i = 1; i < n; i++)
		if (ec(vec[i - 1], vec[i]))
			mark[i - 1] = 1;
	int g = 0;
	for (int i = 0; i < n; i++)
		if (mark[i] == 0)
			sec[g++] = vec[i];
	copy(sec, sec + g, vec);
	n = g;
	if (n == 1){
		cout << 0 << endl;
		return 0;
	}

	vec[n] = {0, 0};
	ld ans = 0;
	for (int i = 0; i < n; i++){
		ld a = i, b = (i + 1) % n;
		ans = max(ans, get(a, b));
	}
	ld ret = 360.0;
	cout << ret - ans << endl;
	return 0;
}