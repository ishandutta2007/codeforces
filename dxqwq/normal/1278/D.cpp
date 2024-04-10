#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct node 
{
	int x,y;
} a[500003];
int busket[1000003],f[1000003];
int cmp(node A,node B) 
{
	return A.x<B.x;
}
inline int find(int x) { return (x==f[x])?(x):(f[x]=find(f[x]));}
int combine(int x,int y) 
{
	int rx=find(x),ry=find(y);
	if(rx==ry) return 0;
	if(rx<ry) swap(rx,ry);
	f[rx]=ry;
	return 1;
}
set<int>S;
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	for(int i=1; i<=n; ++i) busket[a[i].y]=i,f[i]=i;
	set<int>::iterator it;
	for(int i=1; i<=n; ++i) 
	{
		S.insert(a[i].y),it=S.lower_bound(a[i].x);
		while(*it<a[i].y&&it!=S.end()) 
			if(!combine(busket[*it],i)) 
				puts("NO"),exit(0);
			else ++it;
	}
	for(int i=1; i<=n; ++i) if(find(i)!=1) {
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0;
}