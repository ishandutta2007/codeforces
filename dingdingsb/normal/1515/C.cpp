#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
const int N=1e5+100;
signed main(){
	int t;scanf("%d",&t);
	while(t--){
		int n,m,x;scanf("%d%d%d",&n,&m,&x);
		puts("YES");
		set<pair<int,int>>s;
		for(int i=1;i<=m;i++)s.insert(mp(0,i));
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			auto a=*s.begin();
			s.erase(s.begin());
			printf("%d ",a.second);
			a.first+=x;
			s.insert(a);
		}
		puts("");
	}
}