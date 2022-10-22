#include<bits/stdc++.h>
using namespace std;
const int MAX_N=2505;
struct C{ int x,y; }a[MAX_N];
typedef long long ll;
struct Vec{
	int x,y;
	Vec(int _x=0,int _y=0){ x=_x,y=_y; }
	Vec(C a,C b){ x=b.x-a.x,y=b.y-a.y; }
	ll cp(Vec b){ return 1ll*x*b.y-1ll*y*b.x; }
};
bool cmp1(Vec a,Vec b){
	if((a.y>=0)^(b.y>=0)) return a.y>b.y;
	return a.cp(b)>0;
}
int n;
vector<Vec> s;
ll c(int n,int m){
	if(n<0||m<0||n<m) return 0;
	ll ans=1;
	for(int i=n-m+1;i<=n;++i) ans*=i;
	for(int i=1;i<=m;++i) ans/=i;
	return ans;
}
ll solve(int x){
	s.clear();
	for(int i=1;i<=n;++i)
		if(i!=x)
			s.push_back(Vec(a[x],a[i]));
	ll ans=c(n-1,4);
//	printf("/%lld/",ans);
	sort(s.begin(),s.end(),cmp1);
//	for(int i=1;i<s.size();++i) printf("[%lld]",s[i-1].cp(s[i])); 
	int top=(int)s.size();
	for(int i=0;i<top;++i) s.push_back(s[i]);
//	for(int i=0;i<s.size();++i) printf("(%d %d)",s[i].x,s[i].y); puts("");
	int p1=0;
	for(int i=0;i<top;++i){
		if(p1<i) p1=i;
		while(p1+1<=i+top&&s[i].cp(s[p1+1])>0) ++p1;
//		printf("|%d %d|",i,p1);
		ans-=c(i+top-p1-1,3);
	}
//	printf("<%lld>",ans);
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d%d",&a[i].x,&a[i].y);
	ll ans=0;
	for(int i=1;i<=n;++i)
		ans+=solve(i);
	printf("%lld\n",ans);
	return 0;
}