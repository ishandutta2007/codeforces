//in the name of Flying Spaghetti Monster

#include<bits/stdc++.h>

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = INF + 7;
const ld EPS = acosl(-1.0);

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define forn(i, n) fore(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define x first
#define y second
#define sz(a) (int)((a).size())

template<class A, class B> ostream& operator <<(ostream& out, pair<A, B> p)
{
	return out << "(" << p.x << ", " << p.y << ")";	
}

template<class A> ostream& operator <<(ostream& out, vector<A> v)
{
	out << "[";
	for(int i = 0; i < sz(v); i++)
	{
		if(i) out << ", ";
		out << v[i];
	}
	return out << "]";
}

mt19937 rnd(time(0));
mt19937_64 rnd64(time(0));

const int N = 100043;

li a[N];
int n;

bool gen()
{
	n = 10;
	forn(i, n) a[i] = rnd64() % (1 << 10) + 1;
	sort(a, a + n);
	for(int i = n - 1; i >= 1; i--)
		a[i] ^= a[i - 1];
	if(*min_element(a, a + n) == 0)
		return gen();
	return true;
}

bool read()
{
//	return gen();
	if(scanf("%d", &n) != 1)
		return false;
	forn(i, n) scanf("%lld", &a[i]);
	return true;	
}

vector<li> ans;

int highest_bit(li x)
{
	if(x == 1)
		return 0;
	return 1 + highest_bit(x / 2);
}

bool my_solution()
{
	sort(a, a + n);
	reverse(a, a + n);
	ans.clear();
	li cur = 0;
	vector<vector<li> > nums(60);
	forn(i, n) nums[highest_bit(a[i])].pb(a[i]);
	forn(i, n)
	{
		forn(k, 60)
		{
			if((cur & (1ll << k)) == 0 && sz(nums[k]) != 0)
			{
				ans.pb(nums[k].back());
				cur ^= nums[k].back();
				nums[k].pop_back();
				break;
			}
		}
		if(i + 1 > sz(ans)) return false;
	}
	cur = 0;
	forn(i, n)
	{
		assert((cur ^ ans[i]) > cur);
		cur ^= ans[i];
	}
	//cerr << ans << endl;
	return true;
}

bool naive()
{
	sort(a, a + n);
	do
	{
		bool good = true;
		li cur = 0;
		forn(i, n)
		{
			li newcur = cur ^ a[i];
			good &= (newcur > cur);
			cur = newcur;
		}
		if(good) return true;
	}
	while(next_permutation(a, a + n));
	return false;
}

void solve()
{
	if(!my_solution())
	{
		puts("No");
	}
	else
	{
		puts("Yes");
		forn(i, n) printf("%lld ", ans[i]);
		puts("");
	}
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	ld curt = clock();
#endif
	if(read())
	{
		solve();
#ifdef _DEBUG
		cerr << "Execution time: " << (clock() - curt) / CLOCKS_PER_SEC << endl;
#endif
	}
	return 0;
	

}