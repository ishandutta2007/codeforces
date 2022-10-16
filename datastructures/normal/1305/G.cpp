#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define ll long long
#define maxn 200000
using namespace std;
int n,a[200005],cnt[200005],fg[200005],p[200005];
int dsu[200005];
struct node{
	int x,y;
	bool operator <(const node &a)const{
		return x+y<a.x+a.y;
	}
}c[200005];
int tot;
int mx;
ll sum,ans;
int dsu_find(int x){
	if (x==dsu[x])return x;
	return dsu[x]=dsu_find(dsu[x]);
}
vector<int> pos[200005];
void merge(int x,int y){
	if (dsu_find(x)==dsu_find(y))return;
	int c1=1,c2=1;
	if (fg[x]==0)c1=cnt[x],fg[x]=1;
	if (fg[y]==0)c2=cnt[y],fg[y]=1;
	ans+=1ll*(c1+c2-1)*(x+y);
	x=dsu_find(x),y=dsu_find(y);
	dsu[x]=y; 
	return;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]),cnt[a[i]]++,mx=max(mx,a[i]),sum+=a[i];
	ans=mx*cnt[0];
	cnt[0]=1;
	memset(dsu,-1,sizeof(dsu));
	for (int i=0;i<=maxn;i++)
		if (cnt[i]>0){
			dsu[i]=i;
			p[i]=(262143^i);
			while(p[i]>maxn)p[i]=((p[i]-1)&(262143^i));
		}
	for (int T=1;T<=20;T++){
		for (int i=1;i<=maxn;i++)
			if (cnt[i]>0){
				dsu[i]=dsu_find(i);
				pos[dsu[i]].push_back(i);
			}
		tot=0;
		for (int i=1;i<=maxn;i++){
			if (pos[i].size()==0)continue;
			int mx=-1,x=-1,y=-1;
			for (int j=0;j<(int)pos[i].size();j++){
				int now=pos[i][j];
				while(p[now]>=0&&(cnt[p[now]]==0||dsu[now]==dsu[p[now]])){
					if (p[now]==0)p[now]=-1;
					else p[now]=((p[now]-1)&(262143^now));
				} 
				if (p[now]!=-1&&now+p[now]>mx)mx=now+p[now],x=now,y=p[now];
			}
			if (mx!=-1)++tot,c[tot].x=x,c[tot].y=y;
		}
		sort(c+1,c+1+tot);
		for (int i=tot;i>=1;i--)merge(c[i].x,c[i].y);
		for (int i=1;i<=maxn;i++)pos[i].clear();
	}
	ans-=sum;
	cout<<ans<<endl;
}