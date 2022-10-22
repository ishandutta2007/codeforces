#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=50005;
const ll inf=0x3f3f3f3f3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
struct node{
	ll x,y,z;
	int id;
	bool operator <(const node &b)const
	{
		if(x==b.x&&y==b.y) return z<b.z;
		if(x==b.x) return y<b.y;
		return x<b.x;
	}
}a[N];
bool vis[N];
int main(){
	ios::sync_with_stdio(0);
    int i,j;
    cin>>n;
    for(i=1;i<=n;i++){
    	cin>>a[i].x>>a[i].y>>a[i].z;
    	a[i].id=i;
	}
    sort(a+1,a+n+1);
    a[n+1].x=a[n+1].y=a[n+1].z=a[0].x=a[0].y=a[0].z=-inf;
	for(i=1;i<=n;i++){
		if(vis[i]) continue;
		if(a[i].x!=a[i+1].x) continue;
		if(a[i].y!=a[i+1].y) continue;
		cout<<a[i].id<<" "<<a[i+1].id<<endl;
		vis[i]=vis[i+1]=1;
	}
	int last=0;
	for(i=1;i<=n;i++){
		if(vis[i]) continue;
		if(a[i].x!=a[last].x){
			last=i;
			continue;
		}
		cout<<a[i].id<<" "<<a[last].id<<endl;
		vis[i]=vis[last]=1;
		last=0;
	}
	last=0;
	for(i=1;i<=n;i++){
		if(vis[i]) continue;
		if(last){
			cout<<a[last].id<<" "<<a[i].id<<endl;
			last=0;
		}
		else last=i;
	}
    return 0;
}