#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

const int N=2005;
struct pt{
	int x,y;
}p[N];
int vis[N],n,u,v;
char s[N];

void push(int x){
	printf("%d ",x);
	vis[x]=1;
}

ll cross(pt p,pt a,pt b){
	return (ll)(a.x-p.x)*(b.y-p.y)-(ll)(a.y-p.y)*(b.x-p.x);
}

int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&p[i].x,&p[i].y);
	scanf("%s",s+1);

	u=1;
	rep(i,1,n)
		if(p[i].x<p[u].x)u=i;
	push(u);
	
	rep(i,1,n-2){
		v=0;
		rep(j,1,n)
			if(!vis[j]){
				if(!v)v=j;
				else if(s[i]=='L'&&cross(p[u],p[v],p[j])<0)v=j;
				else if(s[i]=='R'&&cross(p[u],p[v],p[j])>0)v=j;
			}
		push(u=v);
	}

	rep(i,1,n)
		if(!vis[i])u=i;
	push(u);
	puts("");

	return 0;
}