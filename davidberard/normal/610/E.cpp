#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

inline int nn(char c){
	return c-'a';
}

inline char cc(int n)
{
	return (char) (n+'a');
}

struct info {
	char begin;
	char end;
	vector<int> transitions;
	info() : transitions(100, 0) {}
	info(char a, char b, vector<int> c) : begin(a), end(b), transitions(c) {}
	void print() {
		for(int i=0;i<10;++i)
		{
			for(int j=0;j<10;++j)
			{
				cerr << cc(i) << cc(j) << transitions[i*10+j] << " ";
			}
			cerr << "\n";
		}
		cerr << endl;
	}
};

info zinfo('z', 'z', vector<int>(100, 0));

info merge(info a, info b)
{
	////cerr << " merge:: " << a.begin << " " << a.end << ", " << b.begin << " " << b.end << endl;
	//a.print();
	//b.print();
	info out;
	out.begin = a.begin;
	out.end = b.end;
	for(int i=0;i<100;++i)
	{
		out.transitions[i] = a.transitions[i] + b.transitions[i];
	}
	if(a.end < 'o' && b.begin < 'o')
	{
		out.transitions[nn(a.end)*10+nn(b.begin)]++;
	}
	return out;
}

struct segtree {
	vector<info> t;
	vector<char> d;
	int n, h;
	segtree(string s) {
		int sz = s.size();
		h = sizeof(int)*8 - __builtin_clz(sz);
		n = 1<<h;
		t = vector<info>(n<<1, zinfo);
		d = vector<char>(n<<1, 0);
		for(int i=0;i<sz;++i)
		{
			t[i+n].begin = s[i];
			t[i+n].end = s[i];
		}
		for(int i=n-1;i>0;--i)
		{
			pull(i);
			/*
			for(int j=0;j<10;++j)
			{
				for(int k=0;k<10;++k)
				{
					//cerr << t[i].begin << t[i].end << t[i].transitions[j*10+k] << " ";
				} //cerr << endl;
			} */
		}
	}
	void apply(int x, char c)
	{
		//cerr << " apply " << c << " to " << x << endl;
		int g = sizeof(int)*8 - __builtin_clz(x);
		int amt = 1<<(h-g+1);
		t[x] = info();
		t[x].begin = c;
		t[x].end = c;
		t[x].transitions[nn(c)*11] = amt-1;
		d[x] = c;
	}
	void push(int x)
	{
		if(x < n && d[x] != 0)
		{
			apply(x<<1, d[x]);
			apply(x<<1|1, d[x]);
			d[x] = 0;
		}
	}
	void push_to(int x)
	{
		for(int i=0;i<=h;++i)
		{
			push(x>>(h-i));
		}
	}
	void pull(int x)
	{
		//cerr << " pulling from " << x << " " << d.size() << endl;
		if(x == 0) return;
		assert(x < n);
		assert(d[x] == 0);
		//cerr << " will merge " << (x<<1) << " " << (x<<1|1) << endl;
		t[x] = merge(t[x<<1], t[x<<1|1]);
	}
	void pull_from(int x)
	{
		for(x/=2;x>0;x/=2)
		{
			pull(x);
		}
	}
	void insert(int l, int r, char c)
	{
		l += n;
		r += n;
		int l0 = l;
		int r0 = r;
		push_to(l);
		push_to(r-1);
		int lst = 0;
		int lf = 0, rf = 0;
		for(;l<r;l/=2,r/=2)
		{
			lst = l;
			if(l%2) {
				lf = max(lf, l);
				apply(l++, c);
			}
			if(r%2) {
				apply(--r, c);
				rf = max(rf, r);
			}
			/*
			pull(lst/2);
			if(r/2 != lst/2) {
				pull(r/2);
			} */
		}
		pull_from(rf);
		pull_from(lf);
	}
	int query(string s)
	{
		int amt = 1;
		vector<int> pos(10, -1);
		for(int i = 0;i<s.size();++i)
		{
			pos[nn(s[i])] = i;
		}
		for(int i=0;i<s.size();++i)
		{
			for(int j=0;j<s.size();++j)
			{
				if(pos[i] >= pos[j]) {
					amt += t[1].transitions[i*10+j];
				}
			}
		}
		return amt;
	}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, m, k;
	string s;
	cin >> n >> m >> k;
	cin >> s;
	segtree st(s);
	for(int i=0;i<m;++i)
	{
		int type;
		cin >> type;
		if(type == 1)
		{
			int l, r;
			string s;
			cin >> l >> r;
			cin >> s;
			char c = s[0];
			st.insert(l-1, r, c);
		}
		else
		{
			string s;
			cin >> s;
			cout << st.query(s) << "\n";
		}
		//st.t[1].print();
	}
	return 0;
}