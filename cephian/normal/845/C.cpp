#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int e1=-1,e2=-1,n;
vector<pii> v;

int main() {
	scanf("%d",&n);	
	for(int i = 0; i < n; ++i) {
		int l,r;
		scanf("%d%d",&l,&r);
		v.emplace_back(l,r);
	}
	sort(v.begin(),v.end());
	for(pii &p : v) {
		if(e1 < p.first)
			e1 = p.second;
		else if(e2 < p.first)
			e2 = p.second;
		else {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
}