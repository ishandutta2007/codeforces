#include<bits/stdc++.h>
using namespace std;
typedef long double db;
const db eps=1e-9;
multiset<pair<db,db> >st;
db sx,sy,tx,ty;
int n,xx,yy,P[300004],Q[300004];
void sol(){
	scanf("%d%d%d",&n,&xx,&yy);
	sx=tx=xx,sy=ty=yy;st.clear();
	for(int i=1;i<=n;i++)scanf("%d",&P[i]);
	for(int i=1;i<=n;i++)scanf("%d",&Q[i]);
	if(xx==0&&yy==0){
		for(int i=1;i<=n;i++)puts("0");
		return;
	}
	for(int i=1;i<=n;i++){
		db p=P[i],q=Q[i];
		sx-=p,tx+=p,sy+=q,ty-=q;
		st.insert({q/p,p+p});
		while(sx<-eps){
			auto it=st.begin();st.erase(it);
			auto[r,d]=*it;
			if(sx+d>0){
				db D=sx+d;d-=D;
				st.insert({r,D});
			}
			sx+=d,sy-=d*r;
		}
		while(ty<-eps){
			auto it=--st.end();st.erase(it);
			auto[r,d]=*it;
			if(ty+r*d>0){
				db D=ty/r+d;d-=D;
				st.insert({r,D});
			}
			tx-=d,ty+=d*r;
		}
		printf("%.9Lf\n",tx);
	}
}
int main(){
	int tc;scanf("%d",&tc);
	while(tc--)sol();
}