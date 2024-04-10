#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define maxn 1000005
using namespace std;

int n,i,j,k,a[maxn],b[maxn],c[2],cnt,p[maxn];
int t[maxn*4][2];
void maketree(int x,int l,int r){
	if (l==r) {
		t[x][0]=t[x][1]=0,t[x][p[l]]=l;
		return;
	}
	int mid=(l+r)>>1;
	maketree(x<<1,l,mid),maketree(x<<1^1,mid+1,r);
	t[x][0]=(t[x<<1][0])?t[x<<1][0]:t[x<<1^1][0];
	t[x][1]=(t[x<<1][1])?t[x<<1][1]:t[x<<1^1][1];
}
void change(int x,int l,int r,int v){
	if (l==r) {t[x][0]=t[x][1]=0;return;}
	int mid=(l+r)>>1;
	if (v<=mid) change(x<<1,l,mid,v); else change(x<<1^1,mid+1,r,v);
	t[x][0]=(t[x<<1][0])?t[x<<1][0]:t[x<<1^1][0];
	t[x][1]=(t[x<<1][1])?t[x<<1][1]:t[x<<1^1][1];	
}
int find(int x,int l,int r,int L,int R,int v){
	if (l>R||r<L) return 0;
	if (L<=l&&r<=R) return t[x][v];
	int mid=(l+r)>>1,tmp=find(x<<1,l,mid,L,R,v);
	if (tmp) return tmp; else return find(x<<1^1,mid+1,r,L,R,v);
}

int main(){
	scanf("%d",&n);
	char ch=getchar();while (ch<'0'||ch>'1') ch=getchar();
	for(i=1;i<=n;i++) a[i]=ch-'0',ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	for(i=1;i<=n;i++) b[i]=ch-'0',ch=getchar();
	for(i=1;i<=n;i++) if (a[i]!=b[i]) p[++cnt]=a[i]>b[i];
	int res=0,ans=0;
	for(i=1;i<=cnt;i++) res+=p[i]?1:-1;
	if (res!=0) printf("-1"),exit(0);
	if (!cnt) printf("0"),exit(0);
	maketree(1,1,cnt);
	res=cnt;
	while (res){
		ans++;
		int x=find(1,1,cnt,1,cnt,0),y=find(1,1,cnt,1,cnt,1),v,now=max(x,y);
		change(1,1,cnt,x),change(1,1,cnt,y),res-=2;
		if (x>y) v=1; else v=0; 
		if (!res) break;
		x=find(1,1,cnt,now+1,cnt,v);
		while (x){
			y=find(1,1,cnt,x+1,cnt,v^1);
			if (y) {
				change(1,1,cnt,x),change(1,1,cnt,y),res-=2;
				now=y;
				if (!res) break;
				x=find(1,1,cnt,now+1,cnt,v);
			} else break;
		}
	}
	printf("%d\n",ans);
}