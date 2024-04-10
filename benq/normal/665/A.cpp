#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORd(i, a, b) for (int i=a-1; i>=b; i--)
#define F0Rd(i, a) for (int i=a-1; i>=0; i--)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
// #define b begin
#define e end
#define lb lower_bound
#define ub upper_bound
#define sz size
 
const int MOD = 1000000007;
double PI = 4*atan(1);

int a,ta,b,tb,time1=0, lowerlim, upperlim, z=0;

void findbegin() {
	int x = 300;
	while (x < lowerlim) x += b;
	int y = x;
	while (y<1440) y += b;
	y -= b;
	while (y > upperlim) y -= b;
	cout << (y-x)/b+1;
}

int main() {
	cin >> a >> ta >> b >> tb;
	string x;
	cin >> x;
	time1 += int(x[0]-'0')*600;
	time1 += int(x[1]-'0')*60;
	time1 += int(x[3]-'0')*10;
	time1 += int(x[4]-'0');
	upperlim = time1+ta-1;
	lowerlim = time1-tb+1;
	// cout << upperlim << " " << lowerlim << endl;
	findbegin();
	return 0;
}