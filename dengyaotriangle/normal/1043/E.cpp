#include<bits/stdc++.h>
using namespace std;

const int maxn=300005;

struct dat{
	long long x,y;
	int i;
};

dat p[maxn];
int n,m;
long long pfx[maxn],sfy[maxn];
long long ans[maxn];
int main(){
	ios::sync_with_stdio(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i].x>>p[i].y;
		p[i].i=i; 
	}
	while(m--){
		int a,b;
		cin>>a>>b;
		ans[a]-=min(p[a].x+p[b].y,p[a].y+p[b].x);
		ans[b]-=min(p[a].x+p[b].y,p[a].y+p[b].x);
	}
	sort(p+1,p+1+n,[](dat a,dat b){
		return a.x-a.y<b.x-b.y; //a.x+b.y<b.x+a.y->l=x,r=y
	});
	for(int i=1;i<=n;i++)pfx[i]=pfx[i-1]+p[i].x;
	for(int i=n;i>=1;i--)sfy[i]=sfy[i+1]+p[i].y;
	for(int i=1;i<=n;i++){
		long long g=p[i].x*(long long)(n-i)+p[i].y*(long long)(i-1);
		long long f=pfx[i-1]+sfy[i+1];
		ans[p[i].i]+=g+f; 
	} 
	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
    return 0;
}