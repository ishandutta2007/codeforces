#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(LL i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (LL)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = (LL)INF * INF;
const int MAX = 8000000;
LL T[MAX];
LL lazy[MAX];

void push(int v)
{
	T[v] += lazy[v];
	lazy[v * 2] += lazy[v];
	lazy[v * 2 + 1] += lazy[v];
	lazy[v] = 0;
}
LL mx(int v , int tl , int tr , int l , int r)
{
	push(v);
	if(l > r)
		return 0;
	
	if(tl == l && tr == r)
	{
		return T[v];
	}
	int tm = (tl + tr) / 2;
	return max(mx(v * 2 , tl , tm , l , min(r , tm)) ,
	mx(v * 2 + 1 , tm + 1 , tr , max(l , tm + 1) , r));
}
void add(int v , int tl , int tr , int l , int r , LL val) 
{
	push(v);
	if(l > r)
	{
		return;
	}
	if(tl == l && tr == r)
	{
		lazy[v] += val;
		push(v);
		return;
	}
	int tm = (tl + tr) / 2;
	add(v * 2 , tl , tm , l , min(r , tm) , val);
	add(v * 2 + 1 , tm + 1 , tr , max(l , tm + 1) , r , val);
	T[v] = max(T[v * 2] , T[v * 2 + 1]);
}
void build(int v , int tl , int tr)
{
	if(tl == tr)
	{
		T[v] = tl;
		return;
	}
	int tm = (tl + tr) / 2;
	build(v * 2 , tl , tm);
	build(v * 2 + 1 , tm + 1 , tr);
	T[v] = max(T[v * 2] , T[v * 2 + 1]);
}
pair<int , int> events[300005];
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("In.txt" , "r" , stdin);
	int q;
	cin >> q;
	int sz = 1000005;
	
	build(1 , 0 , sz - 1);
	int idx = 0;
	while(q--)
	{
		char op;
		cin >> op;
		if(op == '+')
		{
			int t , d;
			cin >> t >> d;
			events[idx] = {t , d};
			add(1 , 0 , sz - 1 , 0 , t , d);
		}
		if(op == '-')
		{
			int i;
			cin >> i;
			i--;
			add(1 , 0 , sz - 1 , 0 , events[i].X , -events[i].Y);
		}
		if(op == '?')
		{
			int t;
			cin >> t;
			LL vidn = mx(1 , 0 , sz - 1 , t + 1 , t + 1) - (t + 1);
			//cout << vidn << endl;
			add(1 , 0 , sz - 1 , 0 , t , -vidn);
			//cout << mx(1 , 0 , sz - 1 , 0 , t) << " ";
			cout << max(0LL , mx(1 , 0 , sz - 1 , 0 , t) - t) << endl;
			add(1 , 0 , sz - 1 , 0 , t , +vidn);
		}
		idx++;
	}
	return 0;
}