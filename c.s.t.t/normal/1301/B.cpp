#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
const int inf=1e9;
int T,n,num[100100],l,r;
pii p;
bool che(int ip){
	p=mp(0,inf);
	for(int i=1;i<=n;i++){
		if(num[i]==-1)continue;
		bool bd=false;
		if(i>1&&num[i-1]==-1)bd=true;
		if(i<n&&num[i+1]==-1)bd=true;
		if(!bd)continue;
		pii t=mp(max(0,num[i]-ip),min(inf,num[i]+ip));
		p.x=max(p.x,t.x);
		p.y=min(p.y,t.y);
		if(p.x>p.y)return false;
	}
	return true;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),l=0,r=inf;
		for(int i=1;i<=n;i++){
			scanf("%d",&num[i]);
			if(i>1&&num[i-1]!=-1&&num[i]!=-1)l=max(l,abs(num[i]-num[i-1]));
		}
		while(l<r){
//			printf("%d %d\n",l,r);
			int mid=(l+r)>>1;
			if(che(mid))r=mid;
			else l=mid+1;
		}
		che(r);
		printf("%d %d\n",r,p.x);
	}
	return 0;
}