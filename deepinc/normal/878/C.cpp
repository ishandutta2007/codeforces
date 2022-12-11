#include<bits/stdc++.h>
using namespace std;
int n,k;
struct P{
	int mx[11],mn[11],sz;
	friend bool operator<(P x,P y){for(int i=1;i<=k;++i)if(x.mx[i]>y.mn[i])return 0;return 1;}
	void operator+=(P x){for(int i=1;i<=k;++i)mn[i]=min(mn[i],x.mn[i]),mx[i]=max(mx[i],x.mx[i]);sz+=x.sz;}
}x,y;set<P>s;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=k;++j)scanf("%d",&x.mn[j]),x.mx[j]=x.mn[j]; x.sz=1;
		while(!s.empty()&&s.find(x)!=s.end())y=*s.find(x),s.erase(s.find(x)),x+=y;
		s.insert(x); printf("%d\n",(*(--s.end())).sz);
	}
}