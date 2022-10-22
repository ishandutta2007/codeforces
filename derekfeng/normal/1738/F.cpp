#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,f[1004],d[1004];
int F(int x){return f[x]==x?x:f[x]=F(f[x]);}
bool used[1004];int col[1004];
void sol(){
	memset(used,0,sizeof(used));
	scanf("%d",&n);vector<pii>vec;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=n;i++)scanf("%d",&d[i]),vec.push_back({d[i],i});
	sort(vec.begin(),vec.end(),greater<pii>());
	fflush(stdout);
	for(auto [a,p]:vec){
		if(used[p])continue;
		used[p]=1;
		for(int i=0;i<d[p];i++){
			printf("? %d\n",p);fflush(stdout);
			int x;scanf("%d",&x);fflush(stdout);
			if(used[x]){
				f[p]=F(x);
				break;
			}else{
				used[x]=1;
				f[x]=p;
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)if(F(i)==i)col[i]=++cnt;
	printf("! ");
	for(int i=1;i<=n;i++)printf("%d ",col[F(i)]);
	puts("");
	fflush(stdout);
}
int main(){
	int tc;scanf("%d",&tc);
	fflush(stdout);
	while(tc--)sol();
}