#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
const int N=100005,M=1e9+7;
vector<pii> v[N];
int n,q,l,r,rt[N],x,cnt,Last[N*2];
struct Tree{
	int lson,rson,num;
}T[N*400];
inline void insert(int x,int y,int l,int r,int L,int R,int z){
	T[x]=T[y];
	if (L>r||l>R)return;
	if (l>=L&&r<=R){
		T[x].num=(ll)T[x].num*z%M;
		return;
	}
	int mid=(l+r)/2;
	if (L<=mid){
		T[x].lson=++cnt;
		insert(cnt,T[y].lson,l,mid,L,min(R,mid),z);
	}
	if (R>mid){
		T[x].rson=++cnt;
		insert(cnt,T[y].rson,mid+1,r,max(L,mid+1),R,z);
	}
}
int find(int x,int l,int r,int y){
	if (l==r)return T[x].num;
	int mid=(l+r)/2;
	if (y<=mid)return (ll)find(T[x].lson,l,mid,y)*T[x].num%M;
	return (ll)find(T[x].rson,mid+1,r,y)*T[x].num%M;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		for (int j=2;j*j<=x;j++)
			if (x%j==0){
				int s=1;
				while (x%j==0){
					s*=j;
					x/=j;
					v[i].push_back(mp(s,j));
				}
			}
		if (x!=1)v[i].push_back(mp(x,x));
	}
	T[0].num=1;
	for (int i=1;i<=n;i++){
		rt[i]=rt[i-1];
		for (pii j:v[i]){
			int t=++cnt;
			insert(cnt,rt[i],1,n,Last[j.fi]+1,i,j.se);
			rt[i]=t;
			Last[j.fi]=i;
		}
	}
	int ans=0;
	scanf("%d",&q);
	while (q--){
		scanf("%d%d",&l,&r);
		l=(ans+l)%n+1,r=(ans+r)%n+1;
		if (l>r)swap(l,r);
		printf("%d\n",ans=find(rt[r],1,n,l));
	}
}