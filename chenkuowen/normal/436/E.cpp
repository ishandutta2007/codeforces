#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5+3e5;
int a[N],b[N],c[N];
multiset<pair<int,int> > q[3][3];
void erase(int x){
	if(c[x]==0){
		q[0][1].erase(make_pair(a[x],x));
		q[0][2].erase(make_pair(b[x],x));
	}else if(c[x]==1){
		q[1][0].erase(make_pair(-a[x],x));
		q[1][2].erase(make_pair(b[x]-a[x],x));
	}else if(c[x]==2){
		q[2][1].erase(make_pair(-b[x]+a[x],x));
	}
}
void insert(int x){
	if(c[x]==0){
		q[0][1].insert(make_pair(a[x],x));
		q[0][2].insert(make_pair(b[x],x));
	}else if(c[x]==1){
		q[1][0].insert(make_pair(-a[x],x));
		q[1][2].insert(make_pair(b[x]-a[x],x));
	}else if(c[x]==2){
		q[2][1].insert(make_pair(-b[x]+a[x],x));
	}
}
long long ans=0;
void aug(){
	int k1=q[0][1].empty()?2e9:q[0][1].begin()->first;
	int k2=q[1][2].empty()?2e9:q[1][2].begin()->first;
	int k3=q[0][2].empty()||q[1][0].empty()?2e9:(q[0][2].begin()->first+q[1][0].begin()->first);
	int k4=q[0][2].empty()||q[2][1].empty()?2e9:(q[0][2].begin()->first+q[2][1].begin()->first);
//	printf("<%d %d %d>",k1,k2,k3);
	if(k1<k2&&k1<k3&&k1<k4){
		int x=q[0][1].begin()->second;
		erase(x);
		c[x]=1;
		insert(x);
		ans+=k1;
	}else if(k2<k3&&k2<k4){
		int x=q[1][2].begin()->second;
		erase(x);
		c[x]=2;
		insert(x);
		ans+=k2;
	}else if(k3<k4){
		int x=q[0][2].begin()->second,y=q[1][0].begin()->second;
		erase(x); 
		c[x]=2;
		insert(x);
		erase(y);
		c[y]=0;
		insert(y);
		ans+=k3;
	}else{
		int x=q[0][2].begin()->second,y=q[2][1].begin()->second;
		erase(x);
		c[x]=2;
		insert(x);
		erase(y);
		c[y]=1;
		insert(y);
		ans+=k4;
	}
}
int main(){
	int n,w; scanf("%d%d",&n,&w);
	for(int x=1;x<=n;++x){
		scanf("%d%d",&a[x],&b[x]);
		c[x]=0; insert(x);
	}
	for(int i=1;i<=w;++i){
		aug();
/*		printf("[%lld]",ans);
		for(int i=1;i<=n;++i) putchar(c[i]+'0');
		puts("");
*/	}
	printf("%lld\n",ans);
	for(int i=1;i<=n;++i) putchar(c[i]+'0');
	return 0;
}