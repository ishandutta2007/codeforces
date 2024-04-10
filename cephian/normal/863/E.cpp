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

vector<pii> v;
set<int> s;
bool need[200005]={};

int main() {	
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; ++i) {
		int l,r;
		scanf("%d%d",&l,&r);
		v.emplace_back(l,i);
		v.emplace_back(r+1,i);
	}
	sort(v.begin(),v.end());
	for(int i = 0; i < v.size();) {
		int j = i;
		while(j < v.size() && v[j].fi == v[i].fi) {
			if(s.count(v[j].se)) s.erase(v[j].se);
			else s.insert(v[j].se);
			++j;
		}
		if(s.size() == 1)
			need[*s.begin()] = true;
		i = j;
	}
	for(int i = 0; i < n; ++i) {
		if(!need[i]) {
			printf("%d\n",i+1);
			return 0;
		}
	}
	printf("-1\n");
}