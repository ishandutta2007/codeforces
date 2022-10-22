#include<bits/stdc++.h>
using namespace std;
#define N 500000
#define QU 500000
#define inf 0x3f3f3f3f
#define X first
#define Y second
int a[N+1],ans[QU+1],prv[N+1],laspos[N+1];
struct query{int l,r,id;}qry[QU+1];
#define ql(x) qry[x].l
#define qr(x) qry[x].r
#define qid(x) qry[x].id
bool operator<(query x,query y){return x.r<y.r;}
struct node{int l,r;pair<int,int> mn;}nd[N<<2];
#define l(x) nd[x].l
#define r(x) nd[x].r
#define mn(x) nd[x].mn
void bld(int l,int r,int p=1){
	l(p)=mn(p).Y=l;r(p)=r;
	if(l==r)return;
	int mid=l+r>>1;
	bld(l,mid,p<<1);bld(mid+1,r,p<<1|1);
}
void chg(int x,int v,int p=1){
	if(l(p)==r(p)){mn(p).X=v;return;}
	int mid=l(p)+r(p)>>1;
	chg(x,v,p<<1|(x>mid));
	mn(p)=min(mn(p<<1),mn(p<<1|1));
}
pair<int,int> ask(int l,int r,int p=1){
//	cout<<l<<" "<<r<<" "<<l(p)<<" "<<r(p)<<"\n";
	if(l<=l(p)&&r>=r(p))return mn(p);
	int mid=l(p)+r(p)>>1;
	pair<int,int> res;res.X=inf;
	if(l<=mid)res=ask(l,r,p<<1);
	if(r>mid)res=min(res,ask(l,r,p<<1|1));
	return res;
}
int main(){
	int n,qu,i;scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	scanf("%d",&qu);
	for(i=1;i<=qu;i++)scanf("%d%d",&qry[i].l,&qry[i].r),qry[i].id=i;
	sort(qry+1,qry+qu+1);
	bld(1,n);
	for(i=1;i<=qu;i++){
		for(int j=qr(i-1)+1;j<=qr(i);j++){
			if(laspos[a[j]])
				chg(j,laspos[a[j]]),chg(laspos[a[j]],inf);
			laspos[a[j]]=j;
		}
		pair<int,int> mn=ask(ql(i),qr(i));
//		cout<<qid(i)<<":"<<mn.X<<" "<<mn.Y<<" "<<"\n";
		if(mn.X>=ql(i))ans[qid(i)]=0;
		else ans[qid(i)]=a[mn.Y];
	}
	for(i=1;i<=qu;i++)printf("%d\n",ans[i]);
	return 0;
}
/*1
6
1 1 2 3 2 4
2
2 6
1 2
*/