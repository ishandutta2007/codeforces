#include<bits/stdc++.h>
using namespace std;
int n,m,cg,cs,r;
struct road{
	int x,y,g,s;
}f[50003];
bool del[50003];
int fa[203];
bool cmp(road a,road b){
	if(a.g<b.g)
		return 1;
	else
		return 0;
}
bool cmp2(road a,road b){
	if(a.s<b.s)
		return 1;
	else
		return 0;
}
inline int find(int x){
	if(fa[x]==-1)
		return x;
	else
	{
		fa[x]=find(fa[x]);
		return find(fa[x]);
	}
}
int main(){
	cin>>n>>m>>cg>>cs;
	for(int i=0;i<m;i++)
		cin>>f[i].x>>f[i].y>>f[i].g>>f[i].s;
/*		f[i].x--,
		f[i].y--;*/
	sort(f,f+m,cmp);
	long long ans=2000000000000000000;
	for(int i=0;i<m;i++){
		int g0=f[i].g;
		f[r++]=f[i];
		inplace_merge(f,f+r-1,f+r,cmp2);
		for(int j=1;j<=n;j++)fa[j]=-1;
		int cnt=0;
		for(int j=0;j<r;j++)del[j]=0;
		int j;
		for(j=0;j<r;j++){
			int xx=find(f[j].x),yy=find(f[j].y);
			if(xx!=yy){
				cnt++;
				fa[xx]=yy;
			}else
				del[j]=1;
			if(cnt==n-1)break;
		}
		//cout<<g0*cg<<' '<<f[j].s*cs<<endl;
		if(cnt==n-1)ans=min(ans,1ll*g0*cg+1ll*f[j].s*cs);
		//cout<<ans<<endl;
		int k;
		for(k=0,j=0;j<r;j++)
			if(!del[j])
				f[k++]=f[j];
		r=k;
	}
	if(ans==2000000000000000000)
		cout<<-1;
	else
		cout<<ans;
}