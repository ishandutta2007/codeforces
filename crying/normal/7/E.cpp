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
const int MAXN=110;
il int Rev(char ch){
	if(ch>='a'&&ch<='z')return ch-'a';
	else return ch-'A'+26;
}
struct Trie{
	// 
	int ch[MAXN*MAXN][52],pos[MAXN*MAXN],vis[MAXN*MAXN],tot;
	void Insert(const string& s,int idx){
		int u=0;
		for(int i=0,len=s.length();i<len;i++){
			if(!ch[u][Rev(s[i])])ch[u][Rev(s[i])]=++tot;
			u=ch[u][Rev(s[i])];
		} 
		pos[u]=idx;
	}
	int Find(const string& s){
		int u=0;
		for(int i=0,len=s.length();i<len;i++){
			if(!ch[u][Rev(s[i])])return -1;
			u=ch[u][Rev(s[i])];
		} 
		return pos[u];
	}
	void Reset(int u,int v){
		vis[u]=v;
	}
	int Get(int u){
		return vis[u];
	}
}trie;
struct Expr{
	string name; //
	string exp; // 
}expr[MAXN];
int n,f[MAXN][MAXN];
string tmp,e;
char ch;
int dp(const string& s,int L,int R){
	//s[L...R] 
	//
	if(f[L][R])return f[L][R];
	int flag=1,flag2=1,cnt=0,sum=0,pos=0;
	string tmp;tmp.clear();
	rep(j,L,R){tmp.append(1,s[j]);if(!isdigit(s[j]) && !islower(s[j]) && !isupper(s[j]))flag=0;}
	rep(j,L,R){if(!islower(s[j]) && !isupper(s[j]))flag2=0;}
	if(flag2 && trie.Find(tmp)!=-1){return f[L][R]=trie.Get(trie.Find(tmp));} //  
	if(flag){return f[L][R]=1;} ///
	// 
	rep(j,L+1,R-1){
		if(s[j]=='('){
			sum++;
		}
		else if(s[j]==')'){
			sum--;
		}
		if(sum<0)break;
	}
	if(sum==0 && s[L]=='(' & s[R]==')'){
		if(dp(s,L+1,R-1)!=4)return f[L][R]=1;
		return f[L][R]=4;
	}
	//
	sum=0;
	rep(j,L,R){
		if(s[j]=='(')sum++;
		else if(s[j]==')')sum--;
		else if(s[j]=='+' || s[j]=='-' || s[j]=='*' || s[j]=='/'){
			if(!sum){
				if(!pos)pos=j;
				else if(s[j]=='+' || s[j]=='-')pos=j;
				else if(s[pos]=='*' || s[pos]=='/')pos=j;
			}
		}
	}
	int lv=dp(s,L,pos-1),rv=dp(s,pos+1,R);
	if(s[pos]=='+'){
		if(lv<=3 && rv<=3)return f[L][R]=3;
		else return f[L][R]=4;
	}else if(s[pos]=='-'){
		if(lv<=3 && rv<=2)return f[L][R]=3;
		else return f[L][R]=4;
	}else if(s[pos]=='*'){
		if(lv<=2 && rv<=2)return f[L][R]=2;
		else return f[L][R]=4;
	}else if(s[pos]=='/'){
		if(lv<=2 && rv<=1)return f[L][R]=2;
		else return f[L][R]=4;
	}
}
int main(){
	cin>>n;
	rep(i,1,n){
		int cnt=0;
		while(ch=getchar()){
			if((ch=='#') || (ch>='a' && ch<='z'))cnt++;
			if(cnt>=7)break;
		}
		cin>>tmp;expr[i].name=tmp;trie.Insert(tmp,i);
		while((ch=getchar()) && ch!='\n')
			if(ch!=' ')expr[i].exp.append(1,ch);
	}
	while((ch=getchar()) && ch!='\n')if(ch!=' ')e.append(1,ch);
	rep(i,1,n){
		memset(f,0,sizeof f);
		trie.Reset(trie.Find(expr[i].name),dp(expr[i].exp,0,expr[i].exp.length()-1));
	}
	memset(f,0,sizeof f);
	printf("%s\n",(dp(e,0,e.length()-1)!=4)?"OK":"Suspicious");
	return 0;
}