#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 100005
using namespace std;

int n,i,j,k,a[maxn],cnt;
int ans,ansp[maxn],p[maxn];
int t[maxn*4][2];
void maketree(int x,int l,int r){
	if (l==r) {t[x][a[l]]++;return;}
	int mid=(l+r)>>1;
	maketree(x<<1,l,mid),maketree(x<<1^1,mid+1,r);
	t[x][0]=t[x<<1][0]+t[x<<1^1][0];
	t[x][1]=t[x<<1][1]+t[x<<1^1][1];
}

void add(int x,int l,int r,int p){
	t[x][a[p]]--;
	if (l==r) return;
	int mid=(l+r)>>1;
	if (p<=mid) add(x<<1,l,mid,p);
	else add(x<<1^1,mid+1,r,p);
}

int findl(int x,int l,int r,int L,int R,int v){
	if (l>R||r<L||!t[x][v]) return 0;
	if (l==r) return l;
	int mid=(l+r)>>1;
	int s=findl(x<<1,l,mid,L,R,v);
	if (s) return s; else return findl(x<<1^1,mid+1,r,L,R,v);
}

int findr(int x,int l,int r,int L,int R,int v){
	if (l>R||r<L||!t[x][v]) return 0;
	if (l==r) return l;
	int mid=(l+r)>>1;
	int s=findr(x<<1^1,mid+1,r,L,R,v);
	if (s) return s; else return findr(x<<1,l,mid,L,R,v);
}

int get(int x,int l,int r,int L,int R){
	if (l>R||r<L) return 0;
	if (L<=l&&r<=R) return t[x][0]+t[x][1];
	int mid=(l+r)>>1;
	return get(x<<1,l,mid,L,R)+get(x<<1^1,mid+1,r,L,R);
}

void doit(int v){
	memset(p,0,sizeof(p));
	int sum=0; i=0,maketree(1,1,n);
	for(k=1;k<=n;k++){
		int id=findl(1,1,n,i+1,n,v^1);
		if (!id) {
			sum++;
			id=findl(1,1,n,1,n,v^1);
			add(1,1,n,id),p[k]=id;
			i=id,v^=1;
		} else {
			if (id==8)
				printf("");
			if (findl(1,1,n,id+1,n,v)==0){
				id=findr(1,1,n,id,n,v^1);
				int L=findl(1,1,n,1,id-1,v^1);
				int R=findr(1,1,n,1,id-1,v);
				if (L&&R&&L<R&&get(1,1,n,1,L-1)==0&&get(1,1,n,R+1,id-1)==0) {
					sum++,id=L;
					add(1,1,n,id),p[k]=id;
					i=id,v^=1; continue;
				} 
			}
			add(1,1,n,id),p[k]=id,i=id,v^=1;
		}
	}
	if (sum<ans) memcpy(ansp,p,sizeof(p)),ans=sum;
}

int main(){
	for(char ch=getchar();ch=='L'||ch=='R';ch=getchar())
		a[++n]=ch=='R',cnt+=a[n];
	ans=n+1;
	if (cnt>=n-cnt) doit(0);
	if (cnt<=n-cnt) doit(1);
	printf("%d\n",ans);
	for(i=1;i<=n;i++) printf("%d ",ansp[i]);
}