//#include "1.cpp"
#include<bits/stdc++.h>
using namespace std;
namespace MAIN{
int now,n,m;
int query(int x,int d){
	int last=now;
	printf("? %d %d\n",x,d);
	fflush(stdout);
	scanf("%d",&now);
	return now; //=::query(x,d);
}
int dquery(int x,int d){
	int last=now;	
	query(x,d);
	return now-last;
}
int add(int x,int d){
	return (x+d+n*m)%(n*m);
}
void finish(vector<int> p){
	printf("!");
	for(int i=1;i<p.size();++i)
		printf(" %d",add(p[i],-p[0]));
	fflush(stdout);
	exit(0);
//	::finish(p);
}
/*
int add(int x,int k){
	return (x+k+n*m)%(n*m);	
}
*/
void solve(int _n,int _m){
	n=_n,m=_m;
	query(0,1);
	int x=0;
	for(int i=0;i<n;++i){
		if(dquery(i,1)==1){
			x=i;
			while(1){
				if(dquery(i,1)<=0){
					query(i,-1);
					break;
				}
			}
			break;
		}
	}
//	printf("(%d)\n",x);
//	print_position();
	vector<int> p(n);
	fill(p.begin(),p.end(),-1);
	p[x]=0;
	bool type=1;
	for(int i=0;i<(n-1)*m-1;++i){
		bool flag=1;
		vector<int> f;
		while(1){
			flag=0;
			int delta=dquery(x,1);
			if(delta==-1) type=0;
			else if(delta==1) type=1;
//			printf("<%d %d>",delta,type);
			if(delta==-1||(delta==0&&type==1)){
				query(x,-1);
//				print_position();
				f.clear();
				for(int j=0;j<n;++j)
					if(p[j]==-1){
						int d2=dquery(j,-1);
						if(d2==-1){
							int d3=dquery(x,-1);
							if(d3!=-1){
//								printf("|%d|",j);
								f.push_back(j);
								flag=1;
								query(j,1);
							}
							query(x,1);
						}
//						query(j,1);
					}
				for(auto y:f){
					p[y]=p[x];
//					printf("|%d|",y);
					for(int k=0;k<m+1;++k){
						query(y,-1);
						p[y]=add(p[y],-1);
					}
				}
				query(x,1);
			}else break;
			query(x,-1);
//			print_position();
/*		for(auto y:f){
			p[y]=p[x];
			for(int k=0;k<m;++k){
				query(y,-1);
				p[y]=add(p[y],-1);
			}
		}
		
*/		
		}
		p[x]=add(p[x],1);
//		print_position();
	}
	for(int i=0;i<n;++i)
		if(p[i]==-1){
//			printf("<%d %d>",i,p[x]);
			p[i]=p[x];
		}
	finish(p);
}
}
void solve(int n,int m){
	MAIN::solve(n,m);
}
int main(){
	int n,m; scanf("%d%d",&n,&m);
	solve(n,m);
	return 0;
}