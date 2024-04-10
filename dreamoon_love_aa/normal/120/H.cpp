// m(_ _)m
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VII;

char s[1005];
map<string, int> id;
string w[1<<18];
vector<int> a[205];
int XY[205], YX[1<<18];
int u[205], ucs=0;
bool go(int x) {
	u[x] = ucs;
	for(int i=0;i<(int)a[x].size();i++) {
		if(YX[a[x][i]]==-1) {
			XY[x] = a[x][i];
			YX[a[x][i]] = x;
			return 1;
		}
	}
	for(int i=0;i<(int)a[x].size();i++) {
		if(u[YX[a[x][i]]]!=ucs && go(YX[a[x][i]])) {
			YX[a[x][i]] = x;
			XY[x] = a[x][i];
			return 1;
		}
	}
	return false;
}

int main()
{
#ifdef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d",&n);
	for(int c=1;c<=n;c++) {
		scanf("%s", s);
		char t[15];
		for(int i=0;s[i];i++) {
			t[0] = s[i];
			t[1] = 0;
			string str = string(t);
			if(id.count(str)==0) {int v=id.size(); id[t] = v; w[v] = t;}
			a[c].push_back(id[t]);
			for(int j=i+1;s[j];j++) {
				t[1] = s[j];
				t[2] = 0;
				str = string(t);
				if(id.count(str)==0) {int v=id.size(); id[t] = v; w[v] = t;}
				a[c].push_back(id[t]);
				for(int k=j+1;s[k];k++) {
					t[2] = s[k];
					t[3] = 0;
					str = string(t);
					if(id.count(str)==0) {int v=id.size(); id[t] = v; w[v] = t;}
					a[c].push_back(id[t]);
					for(int l=k+1;s[l];l++) {
						t[3]=s[l];
						t[4]=0;
						str = string(t);
						if(id.count(str)==0) { int v=id.size(); id[t] = v; w[v] = t;}
						a[c].push_back(id[t]);
					}
				}
			}
		}
	}
	for(int i=0;i<(int)id.size();i++)
		YX[i] = -1;
	for(int i=1;i<=n;i++) {
		++ucs;
		if(!go(i)) { puts("-1"); return 0;}
	}
	for(int i=1;i<=n;i++) {
		printf("%s\n", w[XY[i]].c_str());
	}
	return 0;
}