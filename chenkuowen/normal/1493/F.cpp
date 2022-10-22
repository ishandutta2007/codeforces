#include<bits/stdc++.h>
using namespace std;
int all_queries=0;
int query(int h,int w,int x1,int y1,int x2,int y2){
	++all_queries;
	printf("? %d %d %d %d %d %d\n",h,w,x1,y1,x2,y2);
	fflush(stdout);
	int ret; scanf("%d",&ret);
	return ret;
}
void finish(int x){
	printf("! %d\n",x);
	fflush(stdout);
	exit(0);
}
int n,m;
int check_row(int n,int m,int x){
	if(n==x) return 1;
	int b=n/(2*x);
	if(query(b*x,m,1,1,b*x+1,1)&&(n==b*2*x||query(n-b*(2*x),m,1,1,b*2*x+1,1))){
		if(b==1) return 1;
		return query(b*x-x,m,1,1,b*x+x+1,1);
	}
	else return 0;
}
int check_column(int n,int m,int x){
	if(m==x) return 1;
	int b=m/(2*x);
	if(query(n,b*x,1,1,1,b*x+1)&&(m==b*2*x||query(n,m-b*2*x,1,1,1,b*2*x+1))){
		if(b==1) return 1;
		return query(n,b*x-x,1,1,1,b*x+x+1);
	}
	else return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	int nx=n,ansn=n,ans=1,mx=m,ansm=m;
	for(int i=2;i<=nx;++i){
		int cnt=0;
		while(nx%i==0){
			nx/=i;
			if(check_row(ansn,ansm,ansn/i)){
				ansn/=i;
				++cnt;
			}
		}
		ans*=(cnt+1);
	}
	for(int i=2;i<=mx;++i){
		int cnt=0;
		while(mx%i==0){
			mx/=i;
			if(check_column(ansn,ansm,ansm/i)){
				ansm/=i;
				++cnt;
			}
		}
		ans*=(cnt+1);
	}
//	printf("<%d>",all_queries);
	finish(ans);
	return 0;
}