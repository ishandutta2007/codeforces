//#pragma comment(linker, "/STACK:102400000,102400000")
//#include <bits/stdc++.h>
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
#include <complex>
#include <stack>
#include <utility> 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
const double eps = 1e-8;  
const int INF = 1e9+7; 
const ll inf =(1LL<<62) ;
const int MOD = 1e9 + 7;  
const ll mod = (1LL<<32);
const int N =1e6+6; 
const int M=100010;
const int maxn=1001;
#define mst(a) memset(a, 0, sizeof(a))
#define M_P(x,y) make_pair(x,y)
#define pi acos(-1.0)
#define in freopen("in.txt","r",stdin) 
#define rep(i,j,k) for (int i = j; i <= k; i++)  
#define per(i,j,k) for (int i = j; i >= k; i--)  
#define lson x << 1, l, mid  
#define rson x << 1 | 1, mid + 1, r  
const int lowbit(int x) { return x&-x; }
int read(){ int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
#define point complex<double>
double t1, t2;
point cinema, shop, house;

void readpoint(point &p)
{
  double x, y;
  scanf("%lf %lf", &x, &y);
  p = point(x, y);
}

bool inter(point a, double r_a, point b, double r_b, point c, double r_c) //ca b
{ 
  if (abs(c - a) <= r_a && abs(c - b) <= r_b) return true;
  b -= a; 
  c -= a; //a 
  point r = point(b.real() / abs(b), b.imag() / abs(b)); //xb
  b /= r; 
  c /= r;
  double d = (r_a * r_a - r_b * r_b + abs(b) * abs(b)) / (2 * abs(b));
  double h = sqrt(max(r_a * r_a - d * d, 0.0));
  if (abs(h * h + (d - abs(b)) * (d - abs(b))) - r_b * r_b > eps) return false;
  if (abs(point(d, h) - c) <= r_c || abs(point(d, -h) - c) <= r_c) return true;
  return false;
}

bool check(point a, double r_a, point b, double r_b, point c, double r_c) // 
{ 
  if (r_a <= eps || r_b <= eps || r_c <= eps) return false; // 
  r_a = max(r_a, 0.0); 
  r_b = max(r_b, 0.0); 
  r_c = max(r_c, 0.0);
  if (inter(a, r_a, c, r_c, b, r_b)) return true;
  if (inter(b, r_b, a, r_a, c, r_c)) return true;
  if (inter(c, r_c, b, r_b, a, r_a)) return true;
  return false;
}

int main()
{
  scanf("%lf %lf", &t1, &t2);
  readpoint(cinema); //cinema
  readpoint(house); //house
  readpoint(shop); //shop
  
  if (abs(shop - cinema) + abs(house - shop) <= abs(cinema - house) + t2)
  {
    printf("%lf\n", min(abs(cinema - house) + t2, abs(shop - cinema) + abs(house - shop) + t1));   
  } 
  else
  {
    double l, r, mid;
    l = 0; 
	r = min(abs(cinema - house) + t2, abs(shop - cinema) + abs(house - shop) + t1);
	
   	for(int i=1;i<=200;i++)
	{ 
      mid = (r + l) / 2;
      if (check(cinema, mid, shop, abs(shop - cinema) + t1 - mid, house, abs(house - cinema) + t2 - mid)){
        l = mid;
      } 
	  else {
        r = mid;
      }
    }
    printf("%.4lf\n", l);
  }
  return 0;
}