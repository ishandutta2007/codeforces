#include <iostream>
#include <cstdio>
using namespace std;
struct node{
	int a,b,c,ab,bc,abc;
}tree[400005];
node make_node(int a,int b,int c,int ab,int bc,int abc){
	node ans;
	ans.a=a,ans.b=b,ans.c=c,ans.ab=ab,ans.bc=bc,ans.abc=abc;
	return ans;
}
node merge(node x,node y){
	node ans;
	ans.a=x.a+y.a;
	ans.b=x.b+y.b;
	ans.c=x.c+y.c;
	ans.ab=min(x.a+y.ab,x.ab+y.b);
	ans.bc=min(x.b+y.bc,x.bc+y.c);
	ans.abc=min(x.a+y.abc,min(x.ab+y.bc,x.abc+y.c));
	return ans;
}
void pushup(int now){
	tree[now]=merge(tree[now*2],tree[now*2+1]);
	return;
}
void update(int now,int nowl,int nowr,int pos,char c){
	if (nowl==nowr){
		if (c=='a')tree[now]=make_node(1,0,0,0,0,0);
		if (c=='b')tree[now]=make_node(0,1,0,0,0,0);
		if (c=='c')tree[now]=make_node(0,0,1,0,0,0);
		return;
	}
	int mid=(nowl+nowr)/2;
	if (pos<=mid)update(now*2,nowl,mid,pos,c);
	else update(now*2+1,mid+1,nowr,pos,c);
	pushup(now);
	return;
}
int n,q,pos;
char s[100005],qwq[5];
int main(){
	cin>>n>>q;
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
		update(1,1,n,i,s[i]);
	while(q--){
		scanf("%d%s",&pos,qwq+1);
		update(1,1,n,pos,qwq[1]);
		printf("%d\n",tree[1].abc);
	}
	return 0;
}