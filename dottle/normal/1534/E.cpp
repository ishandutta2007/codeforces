#include<bits/stdc++.h>
const int N=100050;
using namespace std;

int n,k,mx,r,nw,ans;
struct node{
	int k,id;
	bool operator<(node b)const{return k<b.k;};
};priority_queue<node> q;queue<node> b;

int main(){
	scanf("%d%d",&n,&k),mx=1,nw=n;
	if(n%2!=0&&k%2==0)printf("-1"),exit(0);
	while(nw%k||mx>nw/k){
		if(!r)r=n,mx+=2;
		r--,nw+=2;
	}
	for(int i=1;i<=n-r;i++)q.push((node){mx,i});
	for(int i=n-r+1;i<=n;i++)q.push((node){mx-2,i});
	while(!q.empty()){
		printf("? ");
		for(int i=1;i<=k;i++){
			node nw=q.top();q.pop();
			printf("%d ",nw.id);
			nw.k--;
			if(nw.k)b.push(nw);
		}
		printf("\n"),fflush(stdout);
		scanf("%d",&r),ans^=r;
		while(!b.empty())q.push(b.front()),b.pop();
	}
	printf("! %d\n",ans),fflush(stdout);
}