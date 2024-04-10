#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#define maxn 100005
#define ll long long 
using namespace std;

int n,i,j,k;
struct arr{int a,c;} a[maxn];
int cmp(arr a,arr b){return a.a<b.a;}
struct fun{ll v; int i;fun(ll _v=0,int _i=0){v=_v,i=_i;}};
int operator<(fun a,fun b){return a.v>b.v;}
priority_queue<fun> q1,q2,q3;
ll f[maxn];

int main(){
	scanf("%d",&n); ll sum=0;
	for(i=1;i<=n;i++) scanf("%d%d",&a[i].a,&a[i].c),sum+=a[i].c;
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;i++){
		if (i>1){
			f[i]=1e18;
			while (!q3.empty()){
				k=q3.top().i;
				if (a[i].a>=a[k].c+a[k].a){
					q1.push(fun(f[k]-a[k].a-a[k].c,k));
					q3.pop();
				} else break;
			}
			if (!q1.empty())
				f[i]=min(f[i],q1.top().v+a[i].a);
			while (!q2.empty()){
				k=q2.top().i;
				if (a[i].a-a[k].a>=a[k].c)
					q2.pop();
				else break;
			}
			if (!q2.empty())
				f[i]=min(f[i],q2.top().v);
		}
		q2.push(fun(f[i],i));
		q3.push(fun(a[i].a+a[i].c,i));
	}
	printf("%lld\n",f[n]+sum);
}