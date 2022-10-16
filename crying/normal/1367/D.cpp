#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define mapit map<int,int>::iterator
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=60;
int q,m,b[MAXN],len,t[30];
char s[MAXN],ans[MAXN];
struct Node{
	int idx,b;
	bool operator<(const Node& n2)const{return b<n2.b;}
}node[MAXN];
int main(){
	scanf("%d",&q);
	while(q--){
		memset(t,0,sizeof t);
		scanf("%s",s+1);len=strlen(s+1);
		rep(i,1,len)t[s[i]-'a']++;
		scanf("%d",&m);
		rep(i,1,m)node[i].idx=i,scanf("%d",&node[i].b);
		int now=1;
		per(j,25,0){
			if(now>m)break;
			sort(node+now,node+1+m);
			int cnt=0;
			rep(i,now,m){if(!node[i].b)cnt++;}
			if(cnt>t[j])continue;
			int pre=now;
			rep(i,now,m){
				if(!node[i].b){
					ans[node[i].idx]='a'+j;
					now++;
				}else break;
			} 
			rep(i,pre,now-1){
				rep(j,now,m){
					node[j].b-=abs(node[i].idx-node[j].idx);
				}
			}
		}
		rep(i,1,m)printf("%c",ans[i]);
		printf("\n");
	}
	return 0;
}