#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=2e5+10;
int n,m,val[MAXN],opt,a,b;
int len,num[MAXN];
pi nxt[MAXN]; // 
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		scanf("%d",&val[i]);
	}
	len=sqrt(n)+1;
	rep(i,1,n){num[i]=(i+len-1)/len;}
	rep(i,1,n){
		int pos=i,cnt=0;
		while(num[pos]==num[i]){
			cnt++;
			pos=pos+val[pos];
		}
		nxt[i]=mp(pos,cnt);
	}
	rep(i,1,m){
		scanf("%d%d",&opt,&a);
		if(!opt){
			scanf("%d",&b);
			//nxt[a]
			val[a]=b;
			int pos=a,cnt=0;
			while(num[pos]==num[a]){
				cnt++;
				pos=pos+val[pos];
			} 
			nxt[a]=mp(pos,cnt);
			// 
			per(j,a-1,1){
				if(num[j]!=num[a])break;
				int pos=j+val[j];
				if(num[pos]==num[j]){
					nxt[j]=mp(nxt[pos].fr,nxt[pos].se+1);
				}
			}
		}else{
			int pos=a,cnt=0; 
			while(nxt[pos].fr<=n){
				cnt+=nxt[pos].se;
				pos=nxt[pos].fr;
			}
			// 
			int pre;
			while(pos<=n){
				cnt++;
				pre=pos;
				pos=pos+val[pos];
			} 
			printf("%d %d\n",pre,cnt);
		}
	}
	return 0;
}