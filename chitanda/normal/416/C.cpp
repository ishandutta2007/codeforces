#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long

struct node{
	int p,c;
}a[1010];

int r[1010],w[1010],p[1010],m,mon,k,n,xx[1010],yy[1010];

struct nod{
	int x;
};
bool operator < (const nod &i,const nod j){
	return a[i.x].p<a[j.x].p;
}

priority_queue<nod>q;

bool cmpw(int a,int b){
	return r[a]<r[b];
}

bool cmpp(int i,int j){
	return a[i].c<a[j].c;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i].c,&a[i].p),p[i]=i;
	sort(p+1,p+n+1,cmpp);
	scanf("%d",&k);
	for(int i=1;i<=k;i++) scanf("%d",&r[i]),w[i]=i;
	sort(w+1,w+k+1,cmpw);
	int j=0;
	for(int i=1;i<=k;i++){
		while(a[p[j+1]].c<=r[w[i]] && j<n) j++,q.push((nod){p[j]});
		if (q.size()){
			nod t=q.top(); q.pop();
			xx[++m]=t.x; yy[m]=w[i];
			mon+=a[xx[m]].p;
		}
	}
	printf("%d %d\n",m,mon);
	for(int i=1;i<=m;i++)
		printf("%d %d\n",xx[i],yy[i]);
	return 0;
}