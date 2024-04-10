#include<bits/stdc++.h>
const int N=100050; 
using namespace std;

struct node{
	int h,id;
	bool operator<(node b)const{return h>b.h;}
}e[N];
int t,n,m,bel[N],x;
priority_queue<node> q;

int main(){
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d%d%d",&n,&m,&x);
		for(int i=1;i<=n;i++)
			scanf("%d",&e[i].h),e[i].id=i;
		sort(e+1,e+1+n);
		while(!q.empty())q.pop();
		for(int i=1;i<=m;i++)q.push((node){0,i});
		for(int i=1;i<=n;i++){
			node nw=q.top();q.pop();
			q.push((node){nw.h+e[i].h,nw.id}),bel[e[i].id]=nw.id;
		}
		printf("YES\n");
		for(int i=1;i<=n;i++)
			printf("%d ",bel[i]);
		putchar('\n');
	}
}