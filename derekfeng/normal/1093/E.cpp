#include <bits/stdc++.h>
using namespace std;
struct Node{
	int l,r,pos,add,id;
	Node(int a,int b,int c,int d,int e):l(a),r(b),pos(c),add(d),id(e){}
	Node(){
	}
}s1[1000004],s2[1000004];
int n,cnt,m,qcnt;
int x,b[200004],a[200004],ans[200004],dat[200004];
void add(int id,int x){while(id<=n)dat[id]+=x,id+=(id&-id);}
int qry(int id){int ret=0;while(id)ret+=dat[id],id-=(id&-id);return ret;}
int sum(int l,int r){return qry(r)-qry(l-1);}
void d_a_c(int l,int r){
	if(l>=r)return;
	int mid=(l+r)/2,j=l,p=l;
	d_a_c(l,mid),d_a_c(mid+1,r);
	for(int i=mid+1;i<=r;i++){
		while(j<=mid&&s1[i].pos>=s1[j].pos){
			if(s1[j].id<0)add(s1[j].l,s1[j].add);
			s2[p++]=s1[j++];
		}
		if(s1[i].id>0)ans[s1[i].id]+=s1[i].add*sum(s1[i].l,s1[i].r);
		s2[p++]=s1[i];
	}
	for(int i=l;i<j;i++)if(s1[i].id<0)add(s1[i].l,-s1[i].add);
	while(j<=mid)s2[p++]=s1[j++];
	for(int i=l;i<=r;i++)s1[i]=s2[i];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&x),a[x]=i;
	for(int i=1;i<=n;i++)scanf("%d",&x),b[i]=a[x];
	for(int i=1;i<=n;i++)s1[++cnt]=Node(b[i],-1,i,1,-1);
	for(int i=1;i<=m;i++){
		int opt,l,r,L,R;
		scanf("%d",&opt);
		if(opt==1){
			++qcnt;
			scanf("%d%d%d%d",&l,&r,&L,&R);
			s1[++cnt]=Node(l,r,L-1,-1,qcnt);
			s1[++cnt]=Node(l,r,R,1,qcnt);
		}else{
			scanf("%d%d",&l,&r);
			s1[++cnt]=Node(b[l],-1,l,-1,-1);
			s1[++cnt]=Node(b[r],-1,r,-1,-1);
			swap(b[l],b[r]);
			s1[++cnt]=Node(b[l],-1,l,1,-1);
			s1[++cnt]=Node(b[r],-1,r,1,-1);
		}
	}
	d_a_c(1,cnt);
	for(int i=1;i<=qcnt;i++)printf("%d\n",ans[i]);
}