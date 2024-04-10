#include<bits/stdc++.h>
using namespace std;
const int N=5+2e5;
struct F{ int a,b,id; }a[N];
bool check(F x,F y,F z){
	return 1ll*y.a*z.b*(x.b-y.b)*(z.a-x.a)>1ll*z.a*y.b*(x.b-z.b)*(y.a-x.a);
}
bool check_pos(F x,F y,int pos){
	return 1ll*x.b*y.b*(y.a-x.a)*pos<1ll*x.a*y.a*(x.b-y.b);
}
struct HP{
	vector<F> q;
	void append(F x){
		while(q.size()>1&&check(q[q.size()-2],q[q.size()-1],x)) q.pop_back();
		q.push_back(x);
//		for(auto d:q) printf("|%d|",d.id); puts("");
	}
	int find(int x){
		int left=0,right=(int)q.size()-1;
		while(left<right){
			int mid=left+right>>1;
			if(check_pos(q[mid],q[mid+1],x)) right=mid;
			else left=mid+1;
		}
		return right;
	}
}hp;
bool vis[N];
bool cmp(F x,F y){
	if(x.a!=y.a) return x.a<y.a; 
	else return x.b>y.b;
}
int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d%d",&a[i].a,&a[i].b),a[i].id=i;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;++i){
		if(i>1&&a[i].a==a[i-1].a) continue;
//		printf("<%d>",i);
		hp.append(a[i]);
	}
	int j=hp.find(0);
	for(;j<hp.q.size();++j)
		vis[hp.q[j].id]=1;
	for(int i=1;i<=n;++i)
		if(i>1&&a[i].a==a[i-1].a&&a[i].b==a[i-1].b)
			vis[a[i].id]=vis[a[i-1].id];
	for(int i=1;i<=n;++i)
		if(vis[i]) printf("%d ",i);
	return 0;
}