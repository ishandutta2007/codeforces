#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=a;i<=b;i++)
#define per(i,a,b) for(register int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
const int N = 400400;
int n,l1,l2;
struct dot{
	int x,y;
	dot(int X=0,int Y=0){x=X;y=Y;}
}a[N],b[N],c[N],T;
bool operator < (const dot &a, const dot &b){return a.x<b.x||a.x==b.x&&a.y<b.y;}
dot operator - (const dot &a, const dot &b){return dot(a.x-b.x,a.y-b.y);}
ll getlen(const dot &a){return 1LL*a.x*a.x+1LL*a.y*a.y;}
ll cross(const dot &a, const dot &b){return 1LL*a.x*b.y-1LL*a.y*b.x;}
bool cmp(const dot &a, const dot &b){
	ll t=cross(a-T,b-T);if(t!=0)return t>0;return getlen(a)<getlen(b);
}
inline void graham(dot *s, int &n){
	if(n<=1)return;
	int p=1;rep(i,2,n)if(s[i].x<s[p].x||s[i].x==s[p].x&&s[i].y<s[p].y)p=i;
	swap(s[1],s[p]);T=s[1];sort(s+1,s+n+1,cmp);
	static dot sta[N];int top=0;sta[++top]=s[1];sta[++top]=s[2];
	rep(i,3,n){
		while(top>1&&cross(s[i]-sta[top-1],sta[top]-sta[top-1])>=0)top--;
		sta[++top]=s[i];
	}
	n=top;rep(i,1,n)s[i]=sta[i];
}
int main(){
	scanf("%d",&n);rep(i,1,n)scanf("%d%d",&c[i].x,&c[i].y);
	rep(i,1,n)if(!((c[i].x|c[i].y)&1))b[++l2]=c[i];
	b[++l2]=dot(0,0);graham(b,l2);
//	rep(i,1,l2)printf("<%d,%d>\n",b[i].x,b[i].y);
	/*if(l2==3){if(l1>1)puts("Ani");else puts("...");return 0;}
	n=0;rep(i,1,l1)c[++n]=a[i];c[++n]=dot(0,0);
	rep(i,1,l2-2)c[++n]=getinter(b[i],b[i+2],b[i+1],i+3<=l2?b[i+3]:b[1]);
	graham(c,n);rep(i,1,n)if((c[i].x|c[i].y)&1{puts("Ani");return 0;}*/
	set<dot>Set;int len;
	Set.clear();rep(i,1,l2)if(i>1&&i%2==0)Set.insert(b[i]);//WA
	len=0;rep(i,0,n)if(!Set.count(c[i]))a[++len]=c[i];
	graham(a,len);rep(i,1,len)if((a[i].x|a[i].y)&1){puts("Ani");return 0;}
	Set.clear();rep(i,1,l2)if(i>1&&i%2==1)Set.insert(b[i]);
	len=0;rep(i,0,n)if(!Set.count(c[i]))a[++len]=c[i];
	graham(a,len);rep(i,1,len)if((a[i].x|a[i].y)&1){puts("Ani");return 0;}
	puts("Borna");
	return 0;
}