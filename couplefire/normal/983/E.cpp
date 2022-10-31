#include <bits/stdc++.h>
using namespace std;
 
#define MAX 200002
 
int n;
 
vector<int> v[MAX];
#define MAX_LOG 20
int lcc[MAX_LOG][MAX];
int dep[MAX];
 
int star[MAX];
int en[MAX];
 
int ordd;
 
inline void dfs(int b,int pr=-1,int d=0){
	lcc[0][b]=pr;
	dep[b]=d;
	star[b]=ordd;
	ordd++;
	for(int go:v[b]){
		dfs(go,b,d+1);
	}
	en[b]=ordd;
}
 
void init(){
	for(int i=0;i+1<MAX_LOG;i++){
		for(int j=0;j<n;j++){
			if(lcc[i][j]==-1){
				lcc[i+1][j]=-1;
			}
			else{
				lcc[i+1][j]=lcc[i][lcc[i][j]];
			}
		}
	}
}
int lca(int a,int b){
	if(dep[a]<dep[b])swap(a,b);
	for(int i=MAX_LOG-1;i>=0;i--){
		if(((dep[a]-dep[b])>>i)&1){
			a=lcc[i][a];
		}
	}
	if(a==b)return a;
	for(int i=MAX_LOG-1;i>=0;i--){
		if(lcc[i][a]!=lcc[i][b]){
			a=lcc[i][a];
			b=lcc[i][b];
		}
	}
	return lcc[0][a];
}
int m;
 
int up[MAX_LOG][MAX];
 
vector<pair<int,int> > ed;
 
 
inline void dfs2(int b){
		for(int go:v[b]){
			dfs2(go);
			up[0][b]=min(up[0][b],up[0][go]);
		}
}
int outt[MAX];
 
vector<int> v2[MAX];  //add first to second
vector<pair<pair<int,int>,pair<int,int> > > ev[MAX];
 
int bit[MAX];
void add(int i){
	i++;
	while(i<MAX){
		bit[i]++;
		i+=i&-i;
	}
}
int sum(int i){
	i++;
	int r=0;
	while(i){
		r+=bit[i];
		i-=i&-i;
	}
	return r;
}
int rng(int a,int b){
	int r=sum(b);
	if(a)r-=sum(a-1);
	return r;
}
int su[MAX];
 
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int a;
		scanf("%d",&a);
		a--;
		v[a].push_back(i);
	}
	dfs(0);
	init();
	cin>>m;
	for(int i=0;i<n;i++)up[0][i]=i;
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		a--;
		b--;
		int lc=lca(a,b);
		up[0][a]=min(up[0][a],lc);
		up[0][b]=min(up[0][b],lc);
		ed.push_back(make_pair(a,b));
		v2[star[a]].push_back(star[b]);
		v2[star[b]].push_back(star[a]);
	}
	dfs2(0);
	for(int i=0;i+1<MAX_LOG;i++){
		for(int j=0;j<n;j++){
			up[i+1][j]=up[i][up[i][j]];
		}
	}
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		a--;
		b--;
		int lc=lca(a,b);
		if(a>b)swap(a,b);
		if(up[MAX_LOG-1][a]>lc||up[MAX_LOG-1][b]>lc){
			outt[i]=-1;
			continue;
		}
		if(a==lc){
			int cnt=0;
			for(int i2=MAX_LOG-1;i2>=0;i2--){
				if(a<up[i2][b]){
					cnt|=(1<<i2);
					b=up[i2][b];
				}
			}
			cnt++;
			outt[i]=cnt;
			continue;
		}
		int cnt=0;
		for(int i2=MAX_LOG-1;i2>=0;i2--){
			if(lc<up[i2][a]){
				cnt+=(1<<i2);
				a=up[i2][a];
			}
			if(lc<up[i2][b]){
				cnt+=(1<<i2);
				b=up[i2][b];
			}
		}
		outt[i]=cnt+2;
		//contains both a, b located at lc
		//star[b]~en[b]-1 contains at least one element that is in the range(star[a],en[a])	
		ev[en[a]-1].push_back({{star[b],en[b]-1},{1,i}});
		if(star[b]){
			ev[star[a]-1].push_back({{star[b],en[b]-1},{-1,i}});
		}
	}
	for(int i=0;i<n;i++){
		for(int go:v2[i]){
			add(go);
		}
		for(auto it:ev[i]){
			su[it.second.second]+=it.second.first*rng(it.first.first,it.first.second);
		}
	}
	for(int i=0;i<q;i++){
		printf("%d\n",outt[i]-(int)(su[i]!=0));
	}
	return 0;
}