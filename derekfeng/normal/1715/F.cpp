#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef pair<db,db> pdd;
typedef pair<int,int> pii;
#define fi first
#define se second
const db eps=1e-9;
int n,m;db sa,sb,X,Y,ld,rd,e;
vector<pair<db,pii> >vec;
db ask(vector<pdd>X){
	printf("? %d\n",X.size());
	for(auto [a,b]:X)printf("%.9lf %.9lf\n",a,b);
	fflush(stdout);db ret;scanf("%lf",&ret);
	fflush(stdout);return ret;
}
int main(){
	scanf("%d%d",&n,&m);
	vector<pdd>A,B;
	for(int i=0;i<m;i++)A.push_back({n,i}),A.push_back({0,i});
	A.push_back({n,m}),A.push_back({n+1,m}),A.push_back({n+1,0});
	for(int i=0;i<n;i++)B.push_back({i,m}),B.push_back({i,0});
	B.push_back({n,m}),B.push_back({n,m+1}),B.push_back({0,m+1});
	sa=ask(A),sb=ask(B);
	ld=0,rd=n-1,e=1.0/(db)n;
	for(int tc=0;tc<60;tc++){
		db md=(ld+rd)*0.5;
		db s=(md+md+1)*e*0.5;
		if(s<sa)ld=md;else rd=md;
	}
	X=rd;
	ld=0,rd=m-1,e=1.0/(db)m;
	for(int tc=0;tc<60;tc++){
		db md=(ld+rd)*0.5;
		db s=(md+md+1)*e*0.5;
		if(s<sb)ld=md;else rd=md;
	}
	Y=rd;
	printf("! %.8lf %.8lf",X,Y);
}