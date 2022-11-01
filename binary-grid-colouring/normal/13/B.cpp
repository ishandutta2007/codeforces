#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <bitset>
#include <iomanip>
#include <list>
#include <stack>
#include <utility>
using namespace std;
#pragma GCC optimize ("O3")
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
const double eps = 1e-8;
const int INF = 1e9+7;
const ll inf =(1LL<<62) ;
const int MOD = 1e9 + 7;
const ll mod = 1e9 + 7;
const int N =1e6+6;
const int M=100010;
const int maxn=1001;
#define mst(a) memset(a, 0, sizeof(a))
#define M_P(x,y) make_pair(x,y)
#define pi acos(-1.0)
#define IN freopen("in.txt","r",stdin)
#define rep(i,j,k) for (int i = j; i <= k; i++)
#define per(i,j,k) for (int i = j; i >= k; i--)
#define lson x << 1, l, mid
#define rson x << 1 | 1, mid + 1, r
const int lowbit(int x) { return x&-x; }
int read(){ int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
/*
ios::sync_with_stdio(0);
cin.tie(0);
*/
/***************************timer******************************/
struct timer
{
   double t;
   timer() { t=clock(); }
   ~timer() { printf("\nruntime %.3f s\n", get_time()); }
   double get_time() { return (clock()-t)/CLOCKS_PER_SEC; }
};
/*************************************************************/

struct Point
{
    long long x, y;

    Point(long long x = 0, long long y = 0): x(x), y(y) {
    }

    long long norm2() {
        return x * x + y * y;
    }
};

bool operator ==(const Point &a, const Point &b)
{
    return a.x == b.x && a.y == b.y;
}

istream &operator >>(istream &in, Point &p)
{
    return cin >> p.x >> p.y;
}

long long det(const Point &a, const Point &b)
{
    return a.x * b.y - a.y * b.x;
}

long long dot(const Point &a, const Point &b)
{
    return a.x * b.x + a.y * b.y;
}

Point operator -(const Point &a, const Point &b)
{
    return Point(a.x - b.x, a.y - b.y);
}

Point segments[3][2];

bool check_angle(const Point &a, const Point &b)
{
    return det(a, b) != 0 && dot(a, b) >= 0;
}

bool online(const Point &p, const Point &a, const Point &b)
{
    return det(p - a, p - b) == 0 && dot(p - a, p - b) <= 0;
}

bool check_segment(const Point &p, const Point &a, const Point &b)
{
    if (online(p, a, b))
	{
        long long large_part = (p - a).norm2();
        long long small_part = (p - b).norm2();
        if (large_part < small_part)
		{
            swap(large_part, small_part);
        }
        return small_part * 16 >= large_part;
    }
    return false;
}

bool check()
{
    for (int first = 0; first < 3; ++ first)
	{
        for (int second = first + 1; second < 3; ++ second)
		{
            bool found = false;
            Point common;
            for (int i = 0; i < 2 && found==false; ++ i)
			{
                for (int j = 0; j < 2 && found==false; ++ j)
				{
                    if (segments[first][i] == segments[second][j])
					{
                        found = true;
                        common = segments[first][i];
                    }
                }
            }
            if (found)
			{
                if (segments[first][0] == common)
				{
                    swap(segments[first][0], segments[first][1]);
                }
                if (segments[second][0] == common)
				{
                    swap(segments[second][0], segments[second][1]);
                }
                if (check_angle(segments[first][0] - common, segments[second][0] - common))
				{
                    int thrid = 3 ^ first ^ second;
                    for (int k = 0; k < 2; ++ k)
					{
                        if (check_segment(segments[thrid][k], segments[first][0], segments[first][1]) )
						{
							if(check_segment(segments[thrid][k ^ 1], segments[second][0], segments[second][1])){
								return true;
							}
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
	{
        for (int i = 0; i < 3; ++ i)
		{
            for (int j = 0; j < 2; ++ j)
			{
                cin >> segments[i][j];
            }
        }
        puts(check()? "YES": "NO");
    }
    return 0;
}