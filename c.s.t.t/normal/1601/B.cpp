#include<bits/stdc++.h>
using namespace std;
int n,a[300100],b[300100];
#define lson (x<<1)
#define rson (x<<1|1)
#define mid ((l+r)>>1)
vector<pair<bool,int> >v[2000100];
void build(int x,int l,int r){
	if(l==r){v[((n+1)<<1)+x].emplace_back(false,n+1+l);return;}
	build(lson,l,mid),build(rson,mid+1,r);
	v[((n+1)<<1)+x].emplace_back(false,((n+1)<<1)+lson);
	v[((n+1)<<1)+x].emplace_back(false,((n+1)<<1)+rson);
}
void ae(int x,int l,int r,int L,int R,int y){
	if(l>R||r<L)return;
	if(L<=l&&r<=R){v[y].emplace_back(true,((n+1)<<1)+x);return;}
	ae(lson,l,mid,L,R,y),ae(rson,mid+1,r,L,R,y);
}
deque<int>q;
int dep[2000100],fr[2000100];
vector<int>u;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=0;i<=n;i++)v[n+1+i].emplace_back(false,i+b[i]);
	build(1,0,n);
	for(int i=1;i<=n;i++)ae(1,0,n,i-a[i],i,i);
	memset(dep,-1,sizeof(dep)),fr[n]=-1,dep[n]=0,q.push_back(n);
	while(!q.empty()){
		int x=q.front();q.pop_front();
//		printf("%d:%d\n",x,dep[x]);
		for(auto i:v[x]){
			if(dep[i.second]!=-1&&dep[i.second]<=dep[x]+i.first)continue;
			dep[i.second]=dep[x]+i.first,fr[i.second]=x;
			if(!i.first)q.push_front(i.second);
			else q.push_back(i.second);
		}
	}
	if(dep[0]==-1){puts("-1");return 0;}
	printf("%d\n",dep[0]);
	for(int i=0;i!=-1;i=fr[i])if(i>n&&i<((n+1)<<1))u.push_back(i-n-1);
	while(!u.empty())printf("%d ",u.back()),u.pop_back();puts("");
	return 0;
}