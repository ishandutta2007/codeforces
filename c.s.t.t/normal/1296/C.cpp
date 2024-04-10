#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define x first
#define y second
#define mp make_pair
map<pii,int>m;
pii p;
int T,n,dir[200100],dx[4]={-1,1,0,0},dy[4]={0,0,1,-1},l,r;
char s[200100];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s+1),m.clear(),l=0,r=0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			if(s[i]=='L')dir[i]=0;
			if(s[i]=='R')dir[i]=1;
			if(s[i]=='U')dir[i]=2;
			if(s[i]=='D')dir[i]=3;
		}
		m[p=mp(0,0)]=0;
		for(int i=1;i<=n;i++){
			p.x+=dx[dir[i]],p.y+=dy[dir[i]];
			if(m.find(p)!=m.end()){
				if(i-m[p]<r-l)r=i,l=m[p];
			}
			m[p]=i;
		}
		if(r==0x3f3f3f3f)puts("-1");
		else printf("%d %d\n",l+1,r);
	}
	return 0;
}