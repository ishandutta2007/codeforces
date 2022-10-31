//taken from http://codeforces.com/contest/406/submission/6201986
//since this is public code, it is allowed by CF rules

#include<cstdio>
#include<vector>
using namespace std;
struct tup{
	int a;
	int b;
	int c;
	tup(){}
	tup(int _a,int _b,int _c):a(_a),b(_b),c(_c){}
};
vector<int> g[200010];
vector<tup> ans;
bool visit[200010]={0};
int od[200010]={0},cnt=0;
bool done(int now,int from){
	int i;
	vector<int> tmp;
	visit[now]=true;
	od[now]=++cnt;
	for(i=0;i<g[now].size();i++){
		int next=g[now][i];
		if(visit[next]){
			if(next!=from&&od[next]<od[now]) tmp.push_back(next);
		}
		else{
			if(!done(next,now)) tmp.push_back(next);
		}
		
	}
	for(i=1;i<tmp.size();i+=2){
		ans.push_back(tup(tmp[i-1],now,tmp[i]));
	}
	//printf("%d:%d\n",now,tmp.size());
	if(from){
		if(tmp.size()%2==0) return false;
		ans.push_back(tup(tmp.back(),now,from));
		return true;
	}
	else{
		if(tmp.size()%2) return false;
		return true;
	}
}
int main(){
	int i,n,m,x,y;
	bool flag=true;
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(i=1;i<=n;i++){
		if(!visit[i]){
			if(!done(i,0)){
				flag=false;
				// break;
			}
		}
	}
	printf("%d\n",(int)ans.size());
		for(i=0;i<ans.size();i++){
			printf("%d %d %d\n",ans[i].a,ans[i].b,ans[i].c);
		}
	
	return 0;
}