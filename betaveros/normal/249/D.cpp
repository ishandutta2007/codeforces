#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 100005
//#define debug(code) code
#define debug(code) ((void)0)
using namespace std;
typedef long long lli;
typedef struct {
	lli x;
	lli y;
} pt;
vector<pt> stars, tStars;
lli a, b, c, d;
pt transform(pt star){
	pt ret;
	ret.x = c*star.x - d*star.y;
	ret.y = -a*star.x + b*star.y;
	return ret;
}

void readInput(){
	int starN;
	cin >> starN;
	cin >> a;
	cin.get();
	cin >> b;
	cin >> c;
	cin.get();
	cin >> d;
	debug(cout << a << " " << b << " " << c << " " << d << endl);
	for (int i = 0; i < starN; i++){
		pt st;
		lli inX, inY;
		cin >> inX >> inY;
		st.x = inX;
		st.y = inY;
		stars.push_back(st);
	}
}

void transformStars(){
	int ti;
	vector<pt>::iterator it;
	for (it = stars.begin(); it != stars.end(); it++){
		pt tStar = transform(*it);
		if (tStar.x > 0 && tStar.y > 0){
			tStars.push_back(tStar);
		}
	}
}

bool compare(const pt &a, const pt &b){
	return a.x < b.x || (a.x == b.x && a.y > b.y);
}

int iMinWithIncLen[MAXN];
int maxIncLen = 0;
inline lli yAt(int i){
	return tStars[i].y;
}

int bSearchIncLenIx(lli val, int lo, int hi){
	debug(cout << "  bsearch: " << val << " @ " << lo << " ~ " << hi << endl);
	if (hi - lo == 1) return lo;
	int mid = (lo + hi) / 2;
	debug(cout << "  competing with: " << yAt(iMinWithIncLen[mid - 1]) << " at index "
			<< (mid - 1) << endl);
	if (yAt(iMinWithIncLen[mid - 1]) < val){ // there's an off-by-one somewhere...
		return bSearchIncLenIx(val, mid, hi);
	} else {
		return bSearchIncLenIx(val, lo, mid);
	}
}

void debugDump(){
	for (int i = 0; i < maxIncLen; i++){
		cout << iMinWithIncLen[i] << ",";
	}
	cout << endl;
}

int computeLIS(){
	sort(tStars.begin(), tStars.end(), compare);

	for (int i = 0; i < tStars.size(); i++){
		debug(cout << "LIS: i=" << i << "; x = " << tStars[i].x << "; y = " << tStars[i].y << endl);
		int curIncLenIx = bSearchIncLenIx(yAt(i), 0, maxIncLen+1);
		debug(cout << "  IncLen - 1 = " << curIncLenIx << endl);
		if (curIncLenIx == maxIncLen || yAt(iMinWithIncLen[curIncLenIx]) > yAt(i)){
			iMinWithIncLen[curIncLenIx] = i;
			debug(cout << "  updated" << endl);
		}
		if (curIncLenIx == maxIncLen) {
			maxIncLen = curIncLenIx + 1;
			debug(cout << "  new maxIncLen = " << maxIncLen << endl);
		}
		debug(debugDump());
	}
	return maxIncLen;
}


int main(){
	readInput();
	transformStars();
	cout << computeLIS() << endl;
}