#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define MAXN 210000
#define INF 1e9
#define MAXL 20

struct Trie{
	int cnt,o,ind;
	Trie *A[27];
	Trie(){
		for (int i=0;i<26;++i)A[i] = nullptr;
		cnt = 1;
		o = 0;
		ind = -1;
	}
}*T;

string S;
string X;
vector<string> V;
int ans;
unordered_map<string, bool> SM;

int main(){
	while(!cin.eof()){
		getline(cin,S);
		if(cin.eof())break;
		++ans;
		X = "";
		int c = 0;
		while (c < SZ(S)){
			if (isalpha(S[c])){
				X += S[c];
			}else{
				// cout<<S[c]<<'\n';
				++ans;
				if(X != "")V.pb(X);
				X = "";
			}
			++c;
		}
		if (X!="")V.pb(X);
	}

	T = new Trie();
	int GIND = 0;

	for (auto i : V){
		bool flag = 1;
		if (SM[i])flag = 0;

		Trie* C = T;
		int tm = 0;
		int in = 0;
		int block = 0;

		while (in < SZ(i)){
			int t = i[in] - 'a';
			if (C->A[t] == nullptr){
				// cout<<"Creating "<<i[in]<<'\n';
				assert(flag);
				C->o += flag;
				C->A[t] = new Trie();
				C = C->A[t];
				C->ind = GIND;
				++tm;
				++in;
				continue;
			}
			// cout<<"At "<<(char)('a' + t)<<" value of O is "<<C->o<<'\n';

			if (C->o == 1 && C->A[t] != nullptr && C!=T && !block){ //Use of autocorrect function
				++tm;
				Trie *D = C;
				int oldin = in;
				int H = -1;
				// cout<<i[in]<<' '<<V[H]<<'\n';

				while (D->o == 1 && in < SZ(i) && D->A[i[in] - 'a'] != nullptr){
					// cout<<"Express "<<i[in]<<' '<<flag<<'\n';
					D->o += flag;
					D = D->A[i[in] - 'a'];
					if (H == -1)H = D->ind;
					D->ind = GIND;
					++in;
				}
				// cout<<in<<' '<<SZ(V[H])<<'\n';

				if (in == SZ(V[H])){
					// Then is ok
					C = D;
					continue;
				}else{
					// cout<<"Blocked "<<oldin<<'\n';
					block = 1;
					in = oldin;
					--tm;
				}

			}else{	// Go normally
				// cout<<"Normally "<<i[in]<<'\n';
				++tm;
				C->o += flag;
				C = C->A[t];
				C->ind = GIND;
				++in;
			}
		}
		C->o += flag;
		ans += tm;
		// cout<<"At "<<i<<" "<<tm<<' '<<flag<<'\n';
		SM[i] = 1;
		++GIND;
	}
	cout<<ans;
}