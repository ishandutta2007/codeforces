#include<bits/stdc++.h>
using namespace std;
const int N=4e5+50;
const double eps=1e-9;
int n,p1,k1,p2,k2;double ans=1e9;
struct node{int x,y,id,op;}a[N];
bool cmp1(node a,node b){return a.x^b.x?a.x<b.x:a.y<b.y;};
struct cmp{
	bool operator()(node a,node b){return a.y^b.y?a.y<b.y:a.x<b.x;}
};
multiset<node,cmp>s;
multiset<node,cmp>::iterator it;
double dis(node a,node b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;i++){
		scanf("%d%d",&x,&y);
		a[i]=node{x,y,i,0};
		a[i+n]=node{-x,y,i,1};
		a[i+n*2]=node{x,-y,i,2};
		a[i+n*3]=node{-x,-y,i,3};
	}
	sort(a+1,a+n*4+1,cmp1);
	for(int i=1,l=1;i<=n*4;i++){
		while(l<i&&a[i].x-a[l].x>ans-eps)s.erase(s.find(a[l++]));
		for(it=s.lower_bound(node{a[i].x,a[i].y-ans});it!=s.end();it++){
			if(it->y-a[i].y>ans-eps)break;
			if(it->id==a[i].id)continue;
			double dd=dis(a[i],*it);
			if(dd+eps<ans)ans=dd,p1=it->id,p2=a[i].id,k1=it->op^3,k2=a[i].op;
		}
		s.insert(a[i]);
	}
	printf("%d %d %d %d\n",p1,k1+1,p2,k2+1);
	return 0;
}