#include<bits/stdc++.h>
using namespace std;
vector<int> p({7,2,3,5,1});
int query_or(int i,int j){
	printf("or %d %d\n",i,j);
	fflush(stdout);
	int x; scanf("%d",&x);
	return x;
}
int query_and(int i,int j){
	printf("and %d %d\n",i,j);
	fflush(stdout);
	int x; scanf("%d",&x);
	return x;
}
void finish(int x){
	printf("finish %d\n",x);
	fflush(stdout);
	exit(0);
}
vector<int> query(int i,int j){
	vector<int> ret(31);
	int x=query_or(i,j),y=query_and(i,j);
	for(int i=0;i<ret.size();++i)
		ret[i]=int((x>>i)&1)+int((y>>i)&1);
	return ret;
}
const int N=5+1e5;
int f[N];
vector<int> h[N];
int main(){
	memset(f,0,sizeof(f));
	int n,k; scanf("%d%d",&n,&k);	
	vector<int> a=query(1,2),b=query(2,3),c=query(1,3);
	h[1]=h[2]=h[3]=vector<int>(31);
	for(int i=0;i<a.size();++i){
		int s=(a[i]+b[i]+c[i])/2;
		h[1][i]=s-b[i];
		h[2][i]=s-c[i];
		h[3][i]=s-a[i];
	}
	for(int i=4;i<=n;++i){
		h[i]=query(1,i);
		for(int j=0;j<31;++j)
			h[i][j]-=h[1][j];
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<31;++j)
			f[i]|=h[i][j]<<j;
	}
	sort(f+1,f+n+1);
	finish(f[k]);
	return 0;
}