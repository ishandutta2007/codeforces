#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

map<int,int> M;

int grundy(int a) {
	if(M.count(a)) return M[a];
	vector<int> tmp;
	for(int p = 1; (a>>p)!= 0; ++p) {
		int lh = a&((1<<p)-1);
		int uh = (a>>p);
		tmp.push_back(grundy(lh|uh));
	}
	int gr = 0;
	sort(tmp.rbegin(),tmp.rend());
	while(tmp.size() && gr == tmp.back()) {
		while(tmp.size() && gr == tmp.back())
			tmp.pop_back();
		++gr;
	}
	return M[a] = gr;
}

map<int,int> pr;

void load(int a) {
	for(int p = 2; p*p <= a; ++p) {
		int pw = 0;
		while(a%p == 0)
			++pw, a/=p;
		if(pw)
			pr[p] |= 1|(1<<pw);
	}
	if(a != 1)
		pr[a] |= 3;
}

int main() {	
	M[1] = 0;
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; ++i) {
		int a;
		scanf("%d",&a);
		load(a);
	}
	int nim = 0;
	for(auto &p : pr) {
		nim ^= grundy(p.second);
	}
	if(nim == 0) printf("Arpa\n");
	else printf("Mojtaba\n");

}