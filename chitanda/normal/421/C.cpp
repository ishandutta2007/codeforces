#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
#define ll long long

set<int>q,pq,gx;
int n,m,x[101000];
char ch[10];
int ans[101000];
bool chuxian[101000],ok[101000],qq[101000],cc[101000];

int main(){
	//freopen("C.in","r",stdin);
	//freopen("C.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%s%d",ch+1,&x[i]);
		if (ch[1]=='+') qq[i]=1; else qq[i]=0;
		if (qq[i]) {
			pq.insert(x[i]); cc[x[i]]=1;		
		}else{
			if (pq.find(x[i])==pq.end()){
				q.insert(x[i]); chuxian[x[i]]=1;
			}else pq.erase(x[i]);
		}
	}
	for(int i=1;i<=n;i++)ok[i]=1;
	if (q.size()){ for(int i=1;i<=n;i++) if (!chuxian[i] && cc[i]) ok[i]=0; }
	else for(int i=1;i<=n;i++) if (!chuxian[i] && cc[i]) gx.insert(i);
	for(int i=1;i<=m;i++){
		if (qq[i]){
			if (gx.find(x[i])!=gx.end()) gx.erase(x[i]);
			if (!q.size()){
				set<int>::iterator it=gx.begin();
				while(gx.size()){
					ok[*it]=0;
					gx.erase(it);
					it=gx.begin();
				}
			}
			q.insert(x[i]);
		}else{
			q.erase(x[i]);
			if (q.size()) ok[x[i]]=0;
			if (ok[x[i]]) gx.insert(x[i]);
		}
	}
	int tot=0;
	for(int i=1;i<=n;i++)
		if (ok[i]) ans[++tot]=i;
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++) printf("%d ",ans[i]);
	return 0;
}