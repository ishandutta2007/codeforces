#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
int n,m,r,k;
const int ways[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
double ans,tot;
struct element{
	int x,y;long long val;
	inline bool operator<(const element & b)const{
		return val<b.val;
	}
};
inline long long getv(int x,int y){
	int 
		t1=max(x-r+1,1),t2=max(y-r+1,1),
		t3=min(x+r-1,n)-r+1,t4=min(y+r-1,m)-r+1;
	if(t3<t1|t4<t2)return -1;
	return 1LL*(t3-t1+1)*(t4-t2+1);
}
priority_queue<element>q;
set<pair<int,int> >s;
int main(){
	scanf("%d%d%d%d",&n,&m,&r,&k);
	if(n>m)swap(n,m);
	q.push((element){n+1>>1,m+1>>1,getv(n+1>>1,m+1>>1)});
	s.insert(make_pair(n+1>>1,m+1>>1));
	for(register int i=1;i<=k;++i){
		element t=q.top();q.pop();
		tot+=t.val;
		for(register int j=0;j<4;++j){
			int tx=t.x+ways[j][0],
				ty=t.y+ways[j][1];
			if(tx<1||ty<1||tx>n||ty>m)continue;
			if(s.find(make_pair(tx,ty))!=s.end())continue;
			q.push((element){tx,ty,getv(tx,ty)});
			s.insert(make_pair(tx,ty));
		}
	}
	printf("%.10lf\n",tot/double(n-r+1)/double(m-r+1));
	return 0;
}