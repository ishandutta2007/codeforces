#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REPD(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
#define eps 1.0e-11
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

LL n;

inline LL calc(LL a, LL b, LL c)
{
	return (a+b)*(b+c)*(a+c);
}

inline LL calc2(LL a, LL b, LL c)
{
	return a*a*(b+c) + b*b*(a+c) + c*c*(a+b) + 2*a*b*c;
}

inline bool getc(LL x, LL& res)
{
	res = sqrt((double)x);
	LL val;
	while ((val=res*res) < x)
		++res;
	if (val > x && res > 0)
	{
		--res;
		while (res > 0 && (val=res*res) > x)
			--res;
	}
	return val == x;
}

int main()
{
	//freopen("data.in","r",stdin);
	cin >> n;

	/*int ln = 10;
	REP(i,ln) REP(j,ln) REP(k,ln)
		if (calc(i,j,k)==n)
			printf("%d %d %d\n",i,j,k);*/

	if (n%3 != 0)
	{
		printf("0\n");
		return 0;
	}
	n/=3;

	LL res = 0;
	LL mxb = 1;
	LL k = 0;
	for (LL ab = 2; ab*ab*ab <= n; ab++)
	{
		//if (ab%1000 == 0) printf("= %d\n",(int)ab);
		//while (calc(a,a,c) > n) --c,++k;
		if (n%ab != 0) continue;
		LL nn = n/ab;
		LL mn;
		LL A = 1;
		LL B = ab;
		LL C = -nn;
		LL det = B*B-4*A*C;
		getc(det,mn);
		mn -= B;
		mn /= 2*A;
		for (LL ac = max(mn,ab); true; ++ac)
		{
			LL bc = nn / ac;
			if (bc < ac) break;
			if (bc+2 > ab+ac)
			{
				++k;
				continue;
			}
			if (nn%(ac) != 0) continue;
			LL sum = ab+bc+ac;
			if (sum%2 != 0) continue;
			sum/=2;
			LL a = sum-bc;
			LL b = sum-ac;
			LL c = sum-ab;
			if (a>b || b>c)
			{
				printf("BAD\n");
				continue;
			}
			if (a==b&&a==c)
				++res;
			else if (a==b || a==c || b==c)
				res+=3;
			else
				res+=6;
			/*LL A = a+b;
			LL B = (a+b)*(a+b);
			LL C = a*b*(a+b)-n;
			if (A*b*b + B*b + C > 0) break;
			LL det = B*B-4*A*C;
			LL root;
			++k;
			if (getc(det,root))
			{
				LL c = -B+root;
				if (c > 0 && (c%(2*A)) == 0)
				{
					c /= 2*A;
					if (a==b&&a==c)
						++res;
					else if (a==b || a==c || b==c)
						res+=3;
					else
						res+=6;
				}
			}*/
		}
	}
	cout << res << endl;
	//cout << k << endl;
	return 0;
}