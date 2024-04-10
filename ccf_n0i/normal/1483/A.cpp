#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define dzd(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
using namespace std;
int n,m,i,c[100005],t,ans[100005];
vector<int> v[100005];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		rep(i,n) c[i]=0;
		rep(i,m){
			v[i].clear();
			int x;scanf("%d",&x);
			while(x--){
				int y;scanf("%d",&y);
				v[i].push_back(y);
			}
		}
		rep(i,m)if(v[i].size()==1){
			if((++c[ans[i]=v[i][0]])>(m+1)/2){
				break;
			}
		}
		if(i<=m){
			puts("NO");
			continue;
		}
		puts("YES");
		rep(i,m)if(v[i].size()>=2){
			ans[i]=(c[v[i][0]]<c[v[i][1]]?v[i][0]:v[i][1]);
			c[ans[i]]++;
		}
		rep(i,m){
			printf("%d ",ans[i]);
		}
		puts("");
	}
	return 0;
}