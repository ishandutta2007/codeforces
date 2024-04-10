#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=1e5+10;
int n,q,a[MAXN],len,t,l,r,x;
int L[MAXN],R[MAXN],pos[MAXN],cnt;
int b[MAXN];
ll tag[MAXN],tag2[MAXN];

void upd(int l,int r,int x){
	int lidx=pos[l],ridx=pos[r];
	if(lidx==ridx){
		rep(j,l,r){
			a[j]=max(a[j]-x,1);
		}
		rep(j,l,R[ridx]){
			if(pos[a[j]]!=pos[j])b[j]=a[j];
			else b[j]=b[a[j]];
		}
		return;
	}
	rep(j,l,R[lidx])a[j]=max(a[j]-x,1);
	rep(j,L[ridx],r)a[j]=max(a[j]-x,1);
	rep(j,l,R[lidx])if(pos[a[j]]!=pos[j])b[j]=a[j];else b[j]=b[a[j]];
	rep(j,L[ridx],R[ridx])if(pos[a[j]]!=pos[j])b[j]=a[j];else b[j]=b[a[j]];
	rep(k,lidx+1,ridx-1){
		if(tag[k]<=len){
			tag[k]+=x;
			rep(j,L[k],R[k])a[j]=max(a[j]-x,1);
			rep(j,L[k],R[k])if(pos[a[j]]!=pos[j])b[j]=a[j];else b[j]=b[a[j]];
		}else tag2[k]+=x;
	} 
}
int solve(int u,int v){
	while(1){
		if(pos[u]!=pos[v]){
			if(pos[u]<pos[v])swap(u,v);
			ll bu=max(1LL,b[u]-tag2[pos[u]]);
			u=bu; 
		}else{
			ll bu=max(1LL,b[u]-tag2[pos[u]]),
			bv=max(1LL,b[v]-tag2[pos[v]]); 
			if(bu!=bv){
				u=bu;v=bv;
			}else break;
		}
	}
	while(u!=v){
		if(u<v)swap(u,v);
		u=max(1LL,a[u]-tag2[pos[u]]);
	}
	return u;
}
int main(){
	scanf("%d%d",&n,&q);
	len=sqrt(n)+1;
	rep(i,2,n){
		scanf("%d",&a[i]);
	}
	cnt=1;L[1]=R[1]=pos[1]=1;
	rep(i,2,n){
		if(R[cnt]-L[cnt]+1==len){
			cnt++;
			L[cnt]=i;
		}
		R[cnt]=i;
		pos[i]=cnt;
	}
	b[1]=1;
	rep(i,2,n){
		if(pos[a[i]]!=pos[i])b[i]=a[i];
		else b[i]=b[a[i]];
	}
	rep(i,1,q){
		scanf("%d",&t);
		if(t==1){
			scanf("%d%d%d",&l,&r,&x);
			upd(l,r,x);
		}else{
			scanf("%d%d",&l,&r);
			printf("%d\n",solve(l,r));
		}
	}

	return 0;
}