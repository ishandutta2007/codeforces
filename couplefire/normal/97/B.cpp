#include<cstdio>
#include<vector>
#include<algorithm>
 
#define rep(i,n) for(int i=0;i<(n);i++)
 
using namespace std;
 
struct P{
	int x,y;
	bool operator<(const P &p)const{ return x!=p.x?x<p.x:y<p.y; }
	bool operator==(const P &p)const{ return x==p.x && y==p.y; }
};
 
void solve(int l,int r,const vector<P> &ps,vector<P> &ans){
	if(r<=l) return;
 
	int mi=(l+r)/2;
	for(int i=l;i<r;i++) ans.push_back((P){ps[mi].x,ps[i].y});
 
	solve(l,mi,ps,ans);
	solve(mi+1,r,ps,ans);
}
 
int main(){
	int n; scanf("%d",&n);
	vector<P> ps(n);
	rep(i,n) scanf("%d%d",&ps[i].x,&ps[i].y);
 
	sort(ps.begin(),ps.end());
 
	vector<P> ans;
	solve(0,n,ps,ans);
 
	sort(ans.begin(),ans.end());
	n=unique(ans.begin(),ans.end())-ans.begin();
 
	printf("%d\n",n);
	rep(i,n) printf("%d %d\n",ans[i].x,ans[i].y);
 
	return 0;
}