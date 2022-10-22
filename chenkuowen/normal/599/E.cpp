#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Key{ int a,b,c; };
vector<Key> qe;
ll f[25][1<<13|5];
int lca[25][25];
unordered_map<int,int> b[1<<13|5];
vector<int> e[25];
bool gbit(int sta,int i){ return sta&(1<<i-1); }
int ubit(int i){ return 1<<i-1; }
bool check(int x,int i){ return x==0||x==i; }
int cnt(int x){
	int ret=0;
	while(x) x-=x&-x,++ret;
	return ret;
}
bool check2(int i,int j,int sta){
	for(auto t:e[i])
		if(!gbit(sta,t)&&t!=j)
			return false;
	return true;
}
int main(){
	int n,m,q; scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;++i){
		int x,y; scanf("%d%d",&x,&y);
		e[x].push_back(y); 
		e[y].push_back(x);
	}
	for(int i=1;i<=q;++i){
		int a,b,c; scanf("%d%d%d",&a,&b,&c);
		if(a==b&&c!=a){
			puts("0");
			exit(0);
		}
		if(check(lca[a][b],c)) lca[a][b]=c;
		else lca[a][b]=-1;
		lca[b][a]=lca[a][b];
	}
/*	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)
			printf("{%d}",lca[i][j]);
		puts("");
	}*/
	for(register int sta=0;sta<1<<n;++sta){
		bool flag=1;
		for(register int sta1=sta;flag;sta1=(sta1-1)&sta){
			if(sta1==0) flag=0;
			for(register int i=1;i<=n;++i)
				if(gbit(sta-sta1,i))
					for(register int j=1;j<=n;++j)
						if(gbit(sta1,j)){
							for(auto t:e[i])
								if(gbit(sta1,t)) b[sta][sta1]=-1;
							for(auto t:e[j])
								if(gbit(sta-sta1,t)) b[sta][sta1]=-1;
							if(lca[i][j]!=0){
								if(check(b[sta][sta1],lca[i][j])) 
									b[sta][sta1]=lca[i][j];
								else 
									b[sta][sta1]=-1;
							}
						}
//			printf("|%d %d %d|",sta,sta1,b[sta][sta1]);
		}

	}
	for(int i=1;i<=n;++i) f[i][1<<i-1]=1;
	for(int sta=0;sta<1<<n;++sta){
		if(sta==(sta&-sta)) continue;
		for(int i=1;i<=n;++i){
			if(!gbit(sta,i)) continue;
			int sta2=sta-ubit(i),sta3=sta2-(sta2&-sta2);
			bool flag=1;
			for(int j=1;j<=n;++j)
				if(gbit(sta,j)&&!check(lca[i][j],i))
					goto __flag1;
			for(int sta4=sta3;flag;sta4=(sta4-1)&sta3){
//				if(i==1&&sta==7) printf("<%d %d>",sta4,sta4+(sta2&-sta2));
				if(sta4==0) flag=0;
				int sta1=sta4+(sta2&-sta2);
				if(!check(b[sta2][sta1],i)) continue;
				for(int j=1;j<=n;++j){
					if(!gbit(sta1,j)) continue;
					for(auto t:e[i])
						if(gbit(sta1,t)&&t!=j)
							goto __flag2;
					f[i][sta]+=f[j][sta1]*f[i][sta-sta1];
					__flag2:;
				}
			}
			__flag1:;
	//		printf("[%d %d %lld]",i,sta,f[i][sta]);
		}
	}
	int ans=0;
	printf("%lld\n",f[1][(1<<n)-1]);
	return 0;
}