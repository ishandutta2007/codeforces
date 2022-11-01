#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<vector>

using namespace std;
#define ll long long
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define travel(i,x) for(int i=h[x];i;i=pre[i])

const int OUT_LEN = 10000000;
char obuf[OUT_LEN], *ooh = obuf;
inline void print(char c) {
	if (ooh == obuf + OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout), ooh = obuf;
	*ooh++ = c;
}
template<class T>
inline void print(T x) {
	static int buf[30], cnt;
	if (x == 0) print('0');
	else {
		if (x < 0) print('-'), x = -x;
		for (cnt = 0; x; x /= 10) buf[++cnt] = x % 10 + 48;
		while (cnt) print((char)buf[cnt--]);
	}
}
inline void flush() { fwrite(obuf, 1, ooh - obuf, stdout); }
const int N = 200005;
bool swapped;
char s[N], t[N];
vector<pair<char,int>> a, b;
vector<pair<int,int>> ans;
inline void convert(vector<pair<char,int>> &a, char *s){
	for(int i=0, j; j=i, s[i]; i=j+1){
		while(s[j+1]==s[j]) ++j;
		a.emplace_back(s[i], j-i+1);
	}
	reverse(a.begin(), a.end());
}
inline void add(vector<pair<char,int>> &x, const vector<pair<char,int>> &px){
	for(int i=px.size()-1; ~i; --i) if(!x.empty() && x.back().first==px[i].first) x.back().second+=px[i].second; else x.push_back(px[i]);
}
inline vector<pair<char,int>> extract(vector<pair<char,int>> &x, int lx){
	vector<pair<char,int>> res;
	while(lx--) res.push_back(x.back()), x.pop_back();
	return res;
}
inline int len(const vector<pair<char,int>> &a){
	int tot=0;
	for(auto &i:a) tot+=i.second;
	return tot;
}
inline void query(int la, int lb){
	auto pa=extract(a, la), pb=extract(b, lb);
	int lena=len(pa), lenb=len(pb);
	if(swapped) ans.emplace_back(lenb, lena); else ans.emplace_back(lena, lenb);
	add(a, pb), add(b, pa);
}
int main() {
	scanf("%s%s", s, t);
	convert(a, s), convert(b, t);
	while(a.size()>1 || b.size()>1){
		int la=a.size(), lb=b.size();
		// printf("%d %d\n", a.back().first, b.back().first);
		if(la<lb) swap(la, lb), swap(a, b), swapped^=1;
		if(a.back().first!=b.back().first)
			if(lb<=2)
				if(la<=3) query(1, 1);
				else query(3, 1);
			else query(1, 1);
		else
			if(lb==1)
				if(la<=3) query(1, 0);
				else query(3, 0);
			else if(lb==2)
				if(la==2) query(1, 0);
				else query(2, 1);///
			else query(3, 2);
	}
	print(ans.size()), print('\n');
	for(auto &i:ans) print(i.first), print(' '), print(i.second), print('\n');
	return flush(), 0;
}