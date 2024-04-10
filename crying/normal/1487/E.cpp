#include<bits/stdc++.h> 
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--) 
typedef long long ll;
using namespace std;
const int MAXN=2e5+10,INF=5e8;
int n1,n2,n3,n4;
int m1,m2,m3,u,v,ans=INF;
map<pair<int,int>,int>f1,f2,f3;
struct Node{
	int a,idx;
	bool operator<(const Node& n2)const{
		return a<n2.a;
	}
}a[MAXN],b[MAXN],c[MAXN],d[MAXN];
int main(){
	cin>>n1>>n2>>n3>>n4;
	rep(i,1,n1)cin>>a[i].a,a[i].idx=i;
	rep(i,1,n2)cin>>b[i].a,b[i].idx=i;
	rep(i,1,n3)cin>>c[i].a,c[i].idx=i;
	rep(i,1,n4)cin>>d[i].a,d[i].idx=i;
	cin>>m1;
	rep(i,1,m1){
		cin>>u>>v;
		f1[make_pair(v,u)]=1;
	}
	sort(a+1,a+1+n1);
	rep(i,1,n2){
		int j=1;
		while(f1[make_pair(i,a[j].idx)] && j<=n1){
			j++;
		}
		if(j>n1)b[i].a=INF;
		else b[i].a+=a[j].a;
	}
	cin>>m2;
	rep(i,1,m2){
		cin>>u>>v;
		f2[make_pair(v,u)]=1;
	}
	sort(b+1,b+1+n2);
	rep(i,1,n3){
		int j=1;
		while(f2[make_pair(i,b[j].idx)] && j<=n2){
			j++;
		}
		if(j>n2)c[i].a=INF;
		else c[i].a+=b[j].a;
	}
	cin>>m3;
	rep(i,1,m3){
		cin>>u>>v;
		f3[make_pair(v,u)]=1;
	}
	sort(c+1,c+1+n3);
	rep(i,1,n4){
		int j=1;
		while(f3[make_pair(i,c[j].idx)] && j<=n3){
			j++;
		}
		if(j>n3)d[i].a=INF;
		else d[i].a+=c[j].a;
		ans=min(ans,d[i].a);
	}
	if(ans>=INF)printf("-1");
	else cout<<ans;
	return 0;
}