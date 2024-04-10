#include<bits/stdc++.h>
using namespace std;
const int N=5+1e6;
int a[N];
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n,k; scanf("%d%d",&n,&k);
		multiset<int> s;
		bool flag=0;
		for(int i=1;i<=n;++i){
			int x; scanf("%d",&x);
			if(s.find(x+k)!=s.end()||s.find(x-k)!=s.end())
				flag=1;
			s.insert(x);
		}
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}