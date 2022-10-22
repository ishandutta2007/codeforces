#include<bits/stdc++.h>
using namespace std;
int n,p[200004];
bool vis[200004];
vector<pair<int,int> >ret;
void change(int x,int y){
	swap(p[x],p[y]);
	p[x]=-p[x],p[y]=-p[y];
	ret.push_back(make_pair(x,y));
}
void changecir(int x,int y){
	change(x,y);
	int cur=x;
	while(p[-p[cur]]>0)change(cur,-p[cur]);
	cur=-p[cur];
	while(p[-p[cur]]>0)change(cur,-p[cur]);
	change(cur,-p[cur]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	int P=0;
	for(int i=1;i<=n;i++)if(!vis[i]){
		if(p[i]==i)continue;
		int cur=i;
		do{
			vis[cur]=1;
			cur=p[cur];
		}while(cur!=i);
		if(P==0)P=i;
		else changecir(P,i),P=0;
	}
	if(P>0){
		bool ok=0;
		for(int i=1;i<=n;i++)if(p[i]==i){
			changecir(P,i);
			ok=1;
			break;
		}
		if(!ok){
			int p1=p[P],p2=p[p[P]];
			change(P,p1);
			changecir(p1,p2);
		}
	}
	printf("%d\n",ret.size());
	for(auto x:ret)printf("%d %d\n",x.first,x.second);
}