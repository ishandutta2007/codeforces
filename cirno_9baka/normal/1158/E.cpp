#include<bits/stdc++.h>
using namespace std;
const int N=1005;
const long double PI=acos(-1);
int n,k,d[N],p[N],dep,pp[3][N],k2,f[N];
struct str{
	int l,r;
	vector<int> g;
}a[N],b[N];
vector<int> A,B;
struct edge{
	int u,v;
};
vector<edge> e;
int que(){
	cout<<'?';
	for(int i=1;i<=n;++i)
		cout<<' '<<d[i];
	cout<<endl;
	int s=0;
	for(int i=1;i<=n;++i){
		scanf("%1d",&p[i]);
		s+=(p[i]||d[i]!=0);
	}
	return s;
}
int main(){
	scanf("%d",&n);
	int l=1,r=n;
	while(l<r){
		int mid=l+r>>1;
		d[1]=mid;
		if(que()==n)
			r=mid;
		else
			l=mid+1;
	}
	dep=l;
	d[1]=(dep+1)/2;
	que();
	p[1]=1;
	a[1].g.push_back(1);
	a[1].l=a[1].r=0;
	a[2].l=1,a[2].r=(dep+1)/2;
	a[3].l=(dep+1)/2+1,a[3].r=dep;
	k=min(3,dep+1);
	for(int i=2;i<=n;++i)
		if(p[i])
			a[2].g.push_back(i);
		else
			a[3].g.push_back(i);
	while(1){
		int i;
		for(i=1;i<=k;++i)
			if(a[i].l!=a[i].r)
				break;
		if(i>k)
			break;
		memset(d,0,sizeof(d));
		for(int i=1;i<=k;++i){
			if(i%3==1)
				if(a[i+1].l!=a[i+1].r){
					int dis=(a[i+1].r-a[i+1].l+2)/2;
					for(auto it:a[i].g)
						d[it]=dis;
				}
		}
		que();
		for(int i=1;i<=n;++i)
			pp[2][i]=p[i];
		memset(d,0,sizeof(d));
		for(int i=1;i<=k;++i){
			if(i%3==2)
				if(a[i+1].l!=a[i+1].r){
					int dis=(a[i+1].r-a[i+1].l+2)/2;
					for(auto it:a[i].g)
						d[it]=dis;
				}
		}
		que();
		for(int i=1;i<=n;++i)
			pp[0][i]=p[i];
		memset(d,0,sizeof(d));
		for(int i=1;i<=k;++i){
			if(i%3==0)
				if(a[i+1].l!=a[i+1].r){
					int dis=(a[i+1].r-a[i+1].l+2)/2;
					for(auto it:a[i].g)
						d[it]=dis;
				}
		}
		que();
		for(int i=1;i<=n;++i)
			pp[1][i]=p[i];
		k2=0;
		for(int i=1;i<=k;++i)
			if(a[i].l!=a[i].r){
				int mid=(a[i].l+a[i].r)/2;
				vector<int> u,v;
				for(auto it:a[i].g){
					if(pp[i%3][it]^(i==1))
						u.push_back(it);
					else
						v.push_back(it);
				}
				b[++k2]={a[i].l,mid,u};
				b[++k2]={mid+1,a[i].r,v};
			}
			else
				b[++k2]=a[i];
		k=k2;
		for(int i=1;i<=k;++i)
			a[i]=b[i];
	}
	for(int i=1;i<=3;++i){
		int mx=0;
		for(int j=i;j<=k;j+=3)
			mx=max(mx,(int)a[j].g.size());
		memset(f,0,sizeof(f));
		for(int z=0;(1<<z)<mx;++z){
			memset(d,0,sizeof(d));
			for(int j=i;j<=k;j+=3)
				for(int k=0;k<a[j].g.size();++k)
					d[a[j].g[k]]=k>>z&1;
			que();
			for(int j=i+1;j<=k;j+=3)
				for(int k=0;k<a[j].g.size();++k)
					f[a[j].g[k]]|=p[a[j].g[k]]<<z;
		}
		for(int j=i+1;j<=k;j+=3)
			for(auto it:a[j].g)
				e.push_back({it,a[j-1].g[f[it]]});
	}
	cout<<"!"<<endl;
	for(auto it:e)
		cout<<it.u<<' '<<it.v<<endl;
}