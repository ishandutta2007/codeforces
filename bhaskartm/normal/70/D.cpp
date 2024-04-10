#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define y1 ____y1
typedef long long ll;
const int INF=1e9+5;
map<int,int> lower,upper;
int T,opt,x,y;
ll det(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3){
	return x1*y2-x2*y1+x2*y3-x3*y2+x3*y1-x1*y3;
}
int check(map<int,int> &A,int x,int y){
	auto it=A.lower_bound(x);
	if (it==A.end())return 0;
	if (it->fi==x)return it->se>=y;
	if (it==A.begin())return 0;
	auto itp=it--;
	return det(it->fi,it->se,x,y,itp->fi,itp->se)>=0;
}
void add(map<int,int> &A,int x,int y){
	if (check(A,x,y))return;
	A[x]=y;
	auto it=A.find(x),ita=it++,itb=it;
	while (it!=A.end()){
		itb=it++;
		if (it==A.end())break;
		if (det(ita->fi,ita->se,itb->fi,itb->se,it->fi,it->se)<0)break;
		A.erase(itb);
	}
	while (1){
		it=ita;
		if (it==A.begin())break;
		ita=it--;
		if (it==A.begin())break;
		itb=it--;
		if (det(ita->fi,ita->se,itb->fi,itb->se,it->fi,it->se)>0)break;
		A.erase(itb);
	}
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d",&opt,&x,&y);
		if (opt==1){
			add(lower,x,y);
			add(upper,x,-y);
		}
		else {
			if (check(lower,x,y)&&check(upper,x,-y))puts("YES");
			else puts("NO");
		}
	}
	return 0;
}