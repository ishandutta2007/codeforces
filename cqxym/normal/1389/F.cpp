#include<stdio.h>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
#define R register int
#define N 200001
int l[N],r[N],t[N];
struct Segment{
	int pos,id;
	bool tag;
	inline friend bool operator<(Segment x,Segment y){
		if(x.pos!=y.pos){
			return x.pos<y.pos;
		}
		return x.tag<y.tag;
	}
};
int main(){
	int n;
	scanf("%d",&n);
	vector<Segment>V;
	Segment Tem;
	for(R i=0;i!=n;i++){
		scanf("%d%d%d",l+i,r+i,t+i);
		t[i]&=1;
		Tem.tag=false;
		Tem.pos=l[i];
		Tem.id=i;
		V.push_back(Tem);
		Tem.pos=r[i];
		Tem.tag=true;
		V.push_back(Tem);
	}
	sort(V.begin(),V.end());
	set<pair<int,int> >Q[2];
	for(vector<Segment>::iterator T=V.begin();T!=V.end();T++){
		int p=T->id;
		if(T->tag==true){
			int x=t[p],y;
			y=x^1;
			if(Q[x].count(make_pair(r[p],p))!=0){
				if(Q[y].empty()==false){
					n--;
					Q[y].erase(Q[y].begin());
				}
				Q[x].erase(make_pair(r[p],p));
			}
		}else{
			Q[t[p]].insert(make_pair(r[p],p));
		}
	}
	printf("%d",n);
	return 0;
}