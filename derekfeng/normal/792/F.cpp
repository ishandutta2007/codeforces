#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<db,db> pii;
typedef set<pii>::iterator IT;
#define fi first
#define se second
const int M=1e6;
set<pii>st;
int q,lst,op,x,y;
ll m;
bool check(IT p){
	if(p==st.begin()||p==--st.end())return 0;
	pii A=*prev(p),B=*p,C=*next(p);
	if((C.se-B.se)*(C.fi-A.fi)>=(C.se-A.se)*(C.fi-B.fi))return 0;
	st.erase(p);
	return 1;
}
void hull_add(pii x){
	if(st.find(x)!=st.end())return;
	IT it=st.insert(x).fi;
	if(check(it))return;
	while(it!=st.begin()&&check(prev(it)));
	while(it!=--st.end()&&check(next(it)));
}
int main(){
	scanf("%d%lld",&q,&m);
	hull_add({0,0});
	for(int i=1;i<=q;i++){
		scanf("%d%d%d",&op,&x,&y);
		x=(x+lst)%M+1,y=(y+lst)%M+1;
		if(op==1){
			hull_add({x,y});
			continue;
		}
		db X=(db)y/(db)x,Y=(db)m/(db)x;
		auto it=st.lower_bound({X,1e13});
		--it;
		if((*it).fi==X){
			if((*it).se>Y)puts("NO");
			else puts("YES"),lst=i;
			continue;
		}
		if(next(it)==st.end()){
			puts("NO");
			continue;
		}
		pii a=*it,b=*next(it);
		db d=(b.se-a.se)/(b.fi-a.fi);
		if(a.se+(X-a.fi)*d>Y)puts("NO");
		else puts("YES"),lst=i;
	}
}