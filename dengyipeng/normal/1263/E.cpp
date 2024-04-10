#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 1000005
#define maxm 4000005
using namespace std;

int n,i,j,k,a[maxn],now,sum;
char ch;

int tag[maxm],mx[maxm],mi[maxm];

void downtag(int x,int l,int r){
	mx[x]+=tag[x],mi[x]+=tag[x];
	if (l!=r) tag[x<<1]+=tag[x],tag[x<<1^1]+=tag[x];
	tag[x]=0;
}

void change(int x,int l,int r,int ll,int rr,int d){
	if (tag[x]) downtag(x,l,r);
	if (l>rr||r<ll) return;
	if (ll<=l&&r<=rr) {
		tag[x]+=d,downtag(x,l,r);
		return;
	}
	int mid=(l+r)>>1;
	change(x<<1,l,mid,ll,rr,d);
	change(x<<1^1,mid+1,r,ll,rr,d);
	mx[x]=max(mx[x<<1],mx[x<<1^1]);
	mi[x]=min(mi[x<<1],mi[x<<1^1]);
}

int main(){
	scanf("%d",&n);
	for(ch=getchar();ch!='('&&ch!=')'&&ch!='L'&&ch!='R'&&(ch<'a'||ch>'z');ch=getchar());
	now=1;
	for(i=1;i<=n;i++){
		if (ch=='L') now=max(now-1,1); else 
		if (ch=='R') now++; else
		if (ch>='a'&&ch<='z') {
			if (a[now]) {
				change(1,1,n,now,n,-a[now]),sum-=a[now];
				a[now]=0;
			}
		} else 
		if (ch=='(') {
			if (1-a[now]){
				change(1,1,n,now,n,1-a[now]),sum+=1-a[now];
				a[now]=1;
			}
		} else 
		if (ch==')') {
			if (-1-a[now]){
				change(1,1,n,now,n,-1-a[now]),sum+=-1-a[now];
				a[now]=-1;
			}
		}
		if (sum==0&&mi[1]>=0) 
			printf("%d ",mx[1]);
		else printf("-1 ");
		ch=getchar();
	}
}