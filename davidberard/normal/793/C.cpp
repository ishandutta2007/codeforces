#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iomanip>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int X1, X2, Y1, Y2;
pdd pt1, pt2, pt3, pt4;

double cross(pdd a, pdd b)
{
	return (a.first*b.second-a.second*b.first);
}

bool isInside(pdd pt)
{
	if(pt.first > min(X1, X2) && pt.first < max(X1, X2))
		if(pt.second > min(Y1, Y2) && pt.second < max(Y1, Y2))
			return true;
	return false;
}

class mouse{
	public:
	double x,y,vx,vy;
	pdd pos, vel;
	double enterTime, exitTime;
	bool enterfound, exitfound;
	
	mouse() {}
	mouse(double a, double b, double c, double d) : x(a), y(b), vx(c), vy(d) {}
	void set(double a, double b, double c, double d) {
		x = a; y= b; vx = c; vy = d;
		pos.first = x;
		pos.second = y;
		vel.first = vx;
		vel.second = vy;

		enterfound = false, exitfound = false;

		if(isInside(pos))
		{
			enterTime = 0;
			enterfound=true;
		}
		if(enterfound == true && vx == 0 && vy == 0)
		{
			exitTime = 1e20;
			exitfound=true;
		}
		else {
		// check when gets to each x, each y
		vector< double > ts(4);
		ts[0] = ((double) (X1-x))/vx;
		ts[1] = ((double) (X2-x))/vx;
		ts[2] = ((double) (Y1-y))/vy;
		ts[3] = ((double) (Y2-y))/vy;
		sort(ts.begin(), ts.end());
		int i=-1;
		bool didStart = false;
		
		pdd enterpos(-1e99, -1e99);
		for(i=0;i<4 && !enterfound;++i)
		{
			didStart=true;
			if(isInside(pdd((ts[i]+.00000000001)*vx+x, (ts[i]+.00000000001)*vy+y)))
			{
				enterfound = true;
				enterTime = ts[i];
				enterpos = pdd(ts[i]*vx+x, ts[i]*vy+y);
				break;
			}
		}
		if(!didStart)
		{
			i=-1;
			enterpos=pdd(x,y);
		}
		for(i=i+1;i<4 && enterfound;++i)
		{
			if(isInside(pdd((ts[i]-.00000000001)*vx+x, (ts[i]-.00000000001)*vy+y)) && !(ts[i]*vx+x == enterpos.first && ts[i]*vy+y == enterpos.second) && ts[i] >= 0)
			{
				exitfound = true;
				exitTime = ts[i];
				//////cerr << "yup" << endl;
				break;
			}
		}
		//cerr << "Mouse times " << enterTime << " " << exitTime << " " << enterfound << " " << exitfound << endl;
	}
	}
	
};

vector<mouse> mice;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	cin >> X1 >> Y1 >> X2 >> Y2;
	pt1 = pdd(X1, Y1); // 1, 2, 3, 4 in order.
	pt2 = pdd(X1, Y2);
	pt3 = pdd(X2, Y2);
	pt4 = pdd(X2, Y1);
	int xi,yi,vix,viy;
	mice.resize(N);
	bool problem = false;
	double maxEnterTime = 0;
	double minEndTime = 1e29;
	for(int i=0;i<N;++i)
	{
		cin >> xi >> yi >> vix >> viy;
		mice[i].set(xi, yi, vix, viy);
		//////cerr << "::" <<  mice[i].enterfound << " " << mice[i].exitfound << endl;
		if(!problem && mice[i].enterfound && mice[i].exitfound)
		{
			if(mice[i].enterTime > maxEnterTime)
				maxEnterTime = mice[i].enterTime;
			if(mice[i].exitTime < minEndTime)
				minEndTime = mice[i].exitTime;
		}
		else
		{
			problem = 1;
		}
	}

/*
	if(N == 1 && X1 == 0 && Y1 == 0 && X2 == 10 && Y2 == 10)
		cout << maxEnterTime << " " << minEndTime << " " << problem << endl;
*/

	if(problem || maxEnterTime >= minEndTime)
		cout << -1 << endl;
	else
		cout << fixed << setprecision(15) << maxEnterTime << endl;

	return 0;
}