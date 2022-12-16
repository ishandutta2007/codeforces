#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/**
 * Each node holds a vector of size 26 storing "how many of this character do I have"
 * Then to sort a range, take the relevant nodes (i.e. standard segtree nodes for a range)
 * And "sort" them - put all the character counts into a single array, and distribute
 * them in order. EG:
 *
 * sort nodes 10, 11:
 *  | 10| 11| : 10 -> {0,0,1,1}
 *  |c|d|a|c| : 11 -> {1,0,1,0}
 * SORT: get node totals {1,0,2,1}
 * REDISTRIBUTE: 10 -> {1,0,1,0}, 11 -> {0,0,1,1}
 * MARK: mark 10, 11 as "increasing" so that we know we need to apply the "incr" operation on children
 *
 * To pass a tag down to children, run the above function EXCEPT that we need to pass in different chars!
 * Now, we pass in the chars from the parent, in case they have changed.  For example, for children of 10,
 * we have to pass in chars {1,0,1,0} to be redistributed, instead of using {0,0,1,1} which corresponds
 * to the actual values of the children.  This is because we were lazy and did not update the children
 * when we sorted on the parents.
 */

struct segtree {
	vector<vector<int>> t;
	vector<int> d;
	int h, n, sz;

	inline void build_node(const int& x) {
		for(int j=0;j<26;++j) {
			t[x][j] = t[x<<1][j]+t[x<<1|1][j];
		}
	}

	inline void build(int x) {
		for(x/=2;x>0;x/=2) {
			if(d[x] == 0) {
				build_node(x);
			}
		}
	}


	segtree(const string& s) {
		sz = s.size();
		h = sizeof(int)*8 - __builtin_clz(sz);
		n = 1 << h;
		d = vector<int>(n<<1, 0);
		t = vector<vector<int>>(n<<1, vector<int>(26, 0));
		for(int i=0;i<sz;++i) {
			++t[i+n][s[i]-'a'];
		}
		for(int i=n-1;i>0;--i) {
			build_node(i);
		}
	}

	void apply(int x, int v) {
		//cerr << "Apply " << x << endl;
		if(x < n) {
			//assert(d[x] == 0);
			d[x] = v;
		}
	}

	void fill_nodes(const vector<int>& ind, const vector<int>& char_count, int dir) {
		//cerr << " Char counts : ";
		//cerr; for(int x : char_count) {
			//cerr << x << " ";
		//cerr; }
		//cerr << endl;

		for(const int& x : ind) {
			//cerr << x << " ";
			for(int i=0;i<26;++i) {
				t[x][i] = 0;
			}
		}
		int ch_type = (dir == 1 ? 0 : 25);
		int used_of_type = 0;
		for(int i=(dir==1 ? 0 : 0); i<ind.size(); ++i) {
			int x = ind[i];
			//cerr << "x = " << x << endl;
			int my_sz = 1<<(h - (sizeof(int)*8 - __builtin_clz(x)) + 1);
			int have = 0;
			for(;have<my_sz;(dir==1 ? ++ch_type : --ch_type)) {
				int take = min(my_sz-have, char_count[ch_type]-used_of_type);
				t[x][ch_type] += take;
				//cerr << " -> take " << take << " from char " << (char) (ch_type+'a') << " -> t[" << x << "][" << ch_type << "] = " << t[x][ch_type] << endl;
				have += take;
				used_of_type += take;
				if(have == my_sz) break;
				used_of_type = 0;
			}
		}
	}

	void sort_nodes(const vector<int>& ind, int dir) {
		vector<int> char_count(26, 0);
		//cerr << " NODES:  ";
		for(const int& x : ind) {
			//cerr << x << " ";
			for(int i=0;i<26;++i) {
				char_count[i] += t[x][i];
			}
		}
		fill_nodes(ind, char_count, dir);
		//cerr;for(auto x : ind) {
			//cerr << " SN t[" << x <<"] : ";
			//cerr; for(int& amt : t[x]) //cerr << amt;
			//cerr << endl;
		//cerr;}
	}

	void push_node(int x) {
		if(d[x] != 0) {
			//cerr << " t[" << x << "] : ";
			//cerr; for(int& amt : t[x]) //cerr << amt;
			//cerr << endl;
			fill_nodes(vector<int>({x<<1, x<<1|1}), t[x], d[x]);
			apply(x<<1  , d[x]);
			apply(x<<1|1, d[x]);
			d[x] = 0;
		}
	}

	void push(int x) {
		for(int s=h;s>0;--s) {
			int i = x>>s;
			if(d[i] != 0) {
				//cerr << " " << i << " -> " << (i<<1) << "," << (i<<1|1) << endl;
				push_node(i);
			}
		}
	}

	void set(int l, int r, int dir) {
		int l0 = l+n;
		int r0 = r+n;
		push(l0); push(r0-1);
		//cerr << " PUSHED! " << endl;
		vector<int> front, back;
		for(l+=n, r+=n; l<r; l/=2, r/=2) {
			if(l%2) {
				front.push_back(l);
				apply(l, dir);
				++l;
			}
			if(r%2) {
				--r;
				back.push_back(r);
				apply(r, dir);
			}
		}
		//cerr << " .. " << endl;
		reverse(back.begin(), back.end());
		front.insert(front.end(), back.begin(), back.end());
		//cerr << " BUILT " << endl;
		sort_nodes(front, dir);
		//cerr << " SORTED " << endl;
		//push(l0); push(r0-1);
		build(l0); build(r0-1);
		//cerr << " BUILT " << endl;
	}

	string to_string() {
		for(int i=1;i<n;++i) {
			push_node(i);
		}
		string s;
		s.resize(sz);
		for(int i=0;i<sz;++i) {
			//cerr << "!! ";
			for(int j=0;j<26;++j) {
				if(t[i+n][j] != 0) {
					//cerr << (char) (j+'a') << " ";
					s[i] = j+'a';
				}
			}
			//cerr << endl;
		}
		return s;
	}

};

char get() {
	static char buf[100000], *S=buf, *T=buf;
	if(S==T) {
		T=(S=buf)+fread(buf, 1, 100000, stdin);
		if(S==T)return EOF;
	}
	return *S++;
}

void read(int& x) {
	static char c;
	x = 0;
	for(c=get();c<'0'||c>'9';c=get());
	for(;c>='0'&&c<='9';c=get()) x = 10*x+c-'0';
}

void read(string& s) {
	static char cstr[100500], c;
	for(c=get();c==' '||c=='\n'||c=='\r';c=get());
	int i=0;
	for(;c!=' '&&c!='\n'&&c!='\r';c=get()) cstr[i++] = c;
	cstr[i] = 0;
	s.assign(cstr);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, Q; read(N);read(Q);
	string s; read(s);
	segtree st(s);
	for(int qq=0;qq<Q;++qq) {
		int i, j, k; read(i); read(j); read(k);
		st.set(i-1, j, (k==1 ? 1 : -1));
		//segtree cpy(st);
		//cerr << " -> " << cpy.to_string() << endl;
		//cerr << "--" << endl;
	}
	//cerr << "!! " << endl;
	cout << st.to_string() << "\n";

	return 0;
}