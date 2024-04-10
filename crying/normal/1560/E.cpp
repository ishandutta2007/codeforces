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
const int MAXN=5e5+10;
int T,n,t[30],t2[30],cnt,rk[30],flag,tot,occ[30];
char s[MAXN],ret[MAXN],ord[30];
set<int>S;
vector<int>pos[30];
int check(){
	rep(i,1,cnt){
		if(t2[ord[i]-'a'] != occ[ord[i]-'a'])return 0;
	}
	return 1;
}
int valid(){
	S.clear();
	rep(i,0,25)pos[i].clear();
	rep(i,1,tot){
		pos[ret[i]-'a'].pb(i);
		S.is(i);
	}
	int start=1,rd=cnt;
	while(S.size()){
		ll sz=S.size();
	//	printf("start:%d sz:%d\n",start,sz);
		if(start+sz-1 > n)return -1;
		sit it=S.begin();
		while(it!=S.end()){
			int val=*it;
			if(ret[val] != s[start])return -1;
			it++; 
			start++;
		}
		sz=pos[ord[rd]-'a'].size();
		rep(j,0,sz-1){
		//	printf(" %c %d\n",ord[rd],pos[ord[rd]-'a'][j]);
			S.erase(pos[ord[rd]-'a'][j]);
		}
		rd--;
	}
	if(start!=n+1)return -1;
	return 1;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);n=strlen(s+1);
		memset(t,0,sizeof t);
		memset(t2,0,sizeof t2);
		memset(rk,0,sizeof rk);
		memset(occ,0,sizeof occ);
		flag=1;cnt=tot=0;
		per(i,n,1){
			if(!t[s[i]-'a']){
				ord[++cnt]=s[i];
				rk[s[i]-'a']=cnt;
			}
			t[s[i]-'a']++;
		}
		rep(i,1,cnt){
			int num=t[ord[i]-'a'];
			if(num % (cnt-i+1)!=0){
				flag=0;
				break;
			} 
			occ[ord[i]-'a']=num/(cnt-i+1);
		}
		if(flag==0){printf("-1\n");continue;}
		flag=0;
		rep(i,1,n){
			t2[s[i]-'a']++;
			if(t2[s[i]-'a'] > occ[s[i]-'a'])break;
			if(check()){
				rep(j,1,i){
					ret[++tot]=s[j];
				}
				flag=1;
				break;
			}
		}
		if(!flag){printf("-1\n");continue;}
		if(valid()==-1){printf("-1\n");continue;}
		rep(i,1,tot)printf("%c",ret[i]);printf(" ");
		per(i,cnt,1)printf("%c",ord[i]);printf("\n");
	}

	return 0;
}