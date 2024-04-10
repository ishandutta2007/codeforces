#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
int t,n,m,a[MAXN],b[MAXN],c[MAXN],vis[MAXN],cnt[MAXN],ans[MAXN],use[MAXN];
vector<int>e[MAXN];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			vis[i]=cnt[i]=0;
			cin>>a[i];
			e[i].clear();
		}
		for(int i=1;i<=n;i++){
			cin>>b[i];
		}
		for(int i=1;i<=m;i++){
			ans[i]=use[i]=0;
			cin>>c[i];
			cnt[c[i]]++;
			e[c[i]].push_back(i);
		}
		int flag=0;
		for(int i=1;i<=n;i++){
			if(b[i]==c[m]){
				flag=1;break;
			}
		}
		if(!flag){
			printf("NO\n");continue;
		}
		for(int i=1;i<=n;i++){
			if(a[i]!=b[i])vis[b[i]]++;
		}
		flag=1;
		for(int i=1;i<=n;i++){
			if(cnt[i]<vis[i]){
				printf("NO\n");
				flag=0;
				break;
			}
		}
		if(!flag)continue;
		printf("YES\n");
		for(int i=1;i<=n;i++){
			if(a[i]!=b[i]){
				ans[e[b[i]].back()]=i;
				e[b[i]].pop_back();
			}
		}		
		if(!ans[m]){
			for(int i=1;i<=n;i++){
				if(b[i]==c[m]){
					ans[m]=i;
					break;
				}
			}
		}
		for(int i=1;i<=m;i++){
			if(!ans[i])ans[i]=ans[m];
		}
		for(int i=1;i<=m;i++){
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
	return 0;
}