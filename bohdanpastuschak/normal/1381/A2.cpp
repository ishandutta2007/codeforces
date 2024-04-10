#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cerr << #a << " = " << a << endl;

template<typename T> void setmax(T& x, T y) {x = max(x, y);}
template<typename T> void setmin(T& x, T y) {x = min(x, y);}

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class Treap
{
private:
	
	struct Node
	{
		int x;//element's value
		int left;//left son
		int right;//right son
		int y;//priotity
		int size;//size of subtree
		bool reversed;//whether subtree should be reversed
		bool sum;//sum in subtree
		bool add;//how many should be added to every element in subtre
		
		Node(){};
		
		Node(int _x)
		{
			x = _x;
			sum = _x;
			add = 0;
			left = right = -1;
			size = 1;
			reversed = false;
			y = rng();
		}
	};

	int root;//root of treap
	vector<Node> a;//array, corresponding to this treap
	//-1 always stands for non-existing vertex
	 
	int getSize(int v)
	{
		if (v == -1)
			return 0;
		return a[v].size;
	}

	bool getSum(int v)
	{
		if (v == -1)
			return 0;
		return a[v].sum;
	}
			
	void push(int v)//pushing updates from vertex to sons
	{
		if (v == -1)
			return;
		
		if (a[v].reversed == true)
		{	
			if (a[v].left != -1)
				a[a[v].left].reversed ^= 1;//promising to reverse n future
				
			if (a[v].right != -1)
				a[a[v].right].reversed ^= 1;//promising to reverse n future
				
			swap(a[v].left, a[v].right);//swapping sons			
			a[v].reversed = false;
		}
		
		if (a[v].add > 0)
		{
			if (a[v].left != -1)
				a[a[v].left].add ^= a[v].add;//promising to add in future
			if (a[v].right != -1)
				a[a[v].right].add ^= a[v].add;//promising to add in future
			
			a[v].x ^= a[v].add;//updating value
			a[v].sum ^= (a[v].add * a[v].size) & 1;//updating sum
			a[v].add = 0;			
		}
	}

	void update(int v)//updating vertex
	{
		if (v == -1)
			return;
		
		push(v);
		push(a[v].left);
		push(a[v].right);
		
		a[v].sum = a[v].x ^ getSum(a[v].left) ^ getSum(a[v].right);	
		a[v].size = 1 + getSize(a[v].left) + getSize(a[v].right);	
	}

	int merge(int l, int r)//merging two trees
	{
		if (l == -1)
			return r;
		if (r == -1)
			return l;
		
		push(l);
		push(r);
		
		if (a[l].y > a[r].y)
		{
			//now l should be root
			a[l].right = merge(a[l].right, r);//recursive call
			update(l);//updating root
			return l; 
		}
		else
		{
			//now r should be root
			a[r].left = merge(l, a[r].left);//recursive call
			update(r);//updating root
			return r;
		}	
	}

	pair<int, int> split(int v, int c)//spliting tree on two
	{
		if (v == -1)
			return {-1, -1};
		if (c == 0)
			return {-1, v};
		
		push(v);
		if (getSize(a[v].left) >= c)
		{
			//should split in left subtree
			pair<int, int> res = split(a[v].left, c);
			a[v].left = res.second;
			update(v);
			return {res.first, v};
		}
		else
		{
			//should split in right subtree
			pair<int, int> res = split(a[v].right, c - getSize(a[v].left) - 1);
			a[v].right = res.first;
			update(v);
			return {v, res.second};
		}	
	}
	
	int erase(int l, int len)
	{
		pair<int, int> s = split(root, l);
		pair<int, int> t = split(s.second, len);
		
		root = merge(s.first, t.second);
		return t.first;
	}
		
public:
	
	Treap()
	{
		root = -1;
	}
	
	Treap(int size)
	{
		root = -1;
		a.reserve(size);
	}
	
	Treap(vector<int>& el)//creating treap, corresponding to array
	{
		a.resize(el.size());
		root = -1;
		for (int i = 0; i < (int)el.size(); i++)
		{
			a[i] = Node(el[i]);
			root = merge(root, i);
		}
	}
	
	void reverseSegment(int l, int len)//reverseing segment
	{
		pair<int, int> s = split(root, l);
		pair<int, int> t = split(s.second, len);
		
		a[t.first].reversed ^= 1;
		root = merge(s.first, merge(t.first, t.second));	
	}
	
	void addOnSegment(int l, int len)//add value on segment
	{		
		pair<int, int> s = split(root, l);
		pair<int, int> t = split(s.second, len);
		
		a[t.first].add ^= 1;
		root = merge(s.first, merge(t.first, t.second));	
	}	

	bool sumOnSegment(int l, int len = 1)//find sum on segment
	{
		pair<int, int> s = split(root, l);
		pair<int, int> t = split(s.second, len);
		
		bool result = a[t.first].sum;
		root = merge(s.first, merge(t.first, t.second));	
		return result;
	}	
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--){			
		int n;
		string a, b;
		cin >> n >> a >> b;
		for(auto& i: a) i -= '0';
		for(auto& i: b) i -= '0';
		
		vector<int> ans;
		vector<int> A(n);
		FOR(i, 0, n) if (a[i] == 0) A[i] = 0;
		else A[i] = 1;
		
		Treap tr(A);
		RFOR(i, n, 0){
			int Su = tr.sumOnSegment(i, 1);
			
			if (Su == (int)b[i]) continue;
			
			if (tr.sumOnSegment(0, 1) != Su){
				tr.addOnSegment(0, 1);
				ans.PB(1);
			}
			
			ans.PB(i + 1);
			tr.reverseSegment(0, i + 1);
			tr.addOnSegment(0, i + 1);
		}
		
		cout << SZ(ans);
		for(auto i: ans) cout << ' ' << i;
		cout << endl;
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}