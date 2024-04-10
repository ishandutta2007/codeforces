#include<cstdio>
const int N=10000;
int t,d[N+1],q[N+1],l,r;
int main(){
	scanf("%d%d",q,&t);
	d[q[0]]=1;
	for(int u;l<=r;){
	  u=q[l++];
	  if(u&&!d[u-1])d[q[++r]=u-1]=d[u]+1;
	  if(u+u<=N&&!d[u+u])d[q[++r]=u+u]=d[u]+1;
	}printf("%d",d[t]-1);
	return 0;
}