#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using pib = pair<int,bool>;
using ll = long long;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#ifdef fread_unlocked
#define fread fread_unlocked
#define fwrite fwrite_unlocked
#endif
#define lc ind<<1
#define rc ind<<1|1
const int MN = 1e5+4, MOD = 1e9+7, BASE = 31;
char s[MN], t[MN], ret[MN];
int main () { 
	int n,go;
	scanf ("%d %d",&n,&go);
	scanf ("%s\n%s",s,t);
	int ree = 0;
	vector<int> diff;
	for (int i = 0; i < n; i++) {
		if (s[i] != t[i]) {++ree; diff.push_back(i);}
	}
	int best = (ree+1)/2;
	if (go < best) return !printf ("-1\n");
	int worst = ree, done = 0;
	while (worst > go) {
		--worst; ++done;
		ret[diff.back()] = s[diff.back()];
		diff.pop_back();
		ret[diff.back()] = t[diff.back()];
		diff.pop_back();
	}
	for (int i = 0; i < n; i++) {
		if (s[i] != t[i] && !ret[i] && done < go) {
			++done;
			ret[i] = 'a';
			while (ret[i]==s[i]||ret[i]==t[i])++ret[i];
		}
	}
	for (int i = 0; i < n; i++) {
		if (s[i] != t[i]) assert(ret[i]);
		else if (done < go) {
			++done; ret[i] = s[i]=='a'?'b':'a';
		} else ret[i]=s[i];
	}
	printf ("%s\n",ret);
	return 0;
}