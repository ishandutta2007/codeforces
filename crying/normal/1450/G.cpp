#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
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
const int MAXN=5010,MAXM=(1<<20)+10,INF=1e9;
int r(char ch){
	return (ch-'a')-(ch>='t')-(ch>='r')-(ch>='y')-(ch>='g')-(ch>='u')-(ch>='b');
}
char r(int rd){
	for(char i='a';i<='z';i++){
		if(i=='t' || i=='r' || i=='y' || i=='g' || i=='u' || i=='b')continue;
		if(r(i)==rd)return i;
	}	
}
int n,a,b;
char s[MAXN];
int pos[30][MAXN],f[MAXM];
vector<char>ans;
struct Seg{
	int l,r,k;
	bool operator<(const Seg& s2)const{
		return l<s2.l;
	}
}seg[30];
int check(int l,int r,int k){
	if(!k)return 0;
	int rg=r-l+1,ct=k;
	return a*rg<=b*ct;
}
int main(){
	scanf("%d%d%d%s",&n,&a,&b,s+1);
	rep(i,1,n){
		pos[r(s[i])][++pos[r(s[i])][0]]=i;
	}
	int cnt=0,ret=0;
	rep(i,0,19){
		if(pos[i][0])cnt++,ret|=(1<<i),seg[i]=(Seg){pos[i][1],pos[i][pos[i][0]],i};
		else seg[i]=(Seg){INF,INF,i};
		if(check(pos[i][1],pos[i][pos[i][0]],pos[i][0]))f[(1<<i)]=1;
	}
	sort(seg,seg+20);
	if(cnt==1){
		printf("1 %c",s[1]);
		return 0;
	}
	rep(i,1,(1<<20)-1){
		int l=INF,r=-INF,cnt=0;
		rep(j,0,19){
			if(i>>j&1){
				if(!pos[j][0])continue;
				l=min(l,pos[j][1]);
				r=max(r,pos[j][pos[j][0]]);
				cnt+=pos[j][0];
			}
		}
		if(check(l,r,cnt)){
			rep(j,0,19){
				if(i>>j&1){
					f[i]|=f[i^(1<<j)];
				}
			}
		}
		int mask=0;
		rep(j,0,19){
			if(i>>(seg[j].k)&1){
				mask|=(1<<(seg[j].k));
				f[i]|=(f[mask] && f[i^mask]);
			}
		}
	}
	rep(i,0,19){
		if(pos[i][0]==0)continue;
		if(f[ret^(1<<i)]){
			ans.pb(r(i));
		}
	}
	printf("%d ",(int)ans.size());
	for(auto c:ans)printf("%c ",c);
	return 0;
}