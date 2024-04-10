#include<bits/stdc++.h>
using namespace std;


#define reg register
typedef long long ll;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)


//#pragma GCC optimize(2)



const int N=1e6+10,P=998244353;



int n;
char s[N];

struct Node{
	int dp[2][2];
	void init(){ memset(dp,0,sizeof dp); } 
	Node operator | (const Node __) const{
		Node res;res.init();
		rep(a,0,1) rep(b,0,1) rep(c,0,1) rep(d,0,1) if(dp[a][b] && __.dp[c][d]) res.dp[a|c][b|d]=1;
		return res;
	}
	Node operator & (const Node __) const{
		Node res;res.init(); 
		rep(a,0,1) rep(b,0,1) rep(c,0,1) rep(d,0,1) if(dp[a][b] && __.dp[c][d]) res.dp[a&c][b&d]=1;
		return res;
	}
	Node operator ^ (const Node __) const{
		Node res;res.init(); 
		rep(a,0,1) rep(b,0,1) rep(c,0,1) rep(d,0,1) if(dp[a][b] && __.dp[c][d]) res.dp[a^c][b^d]=1;
		return res;
	}
} valstk[N];

int top1,optstk[N],top2;




int Solve(){
	top1=top2=0;
	rep(i,1,n) {
		if(s[i]=='?') {
			Node t;t.init();t.dp[0][1]=t.dp[1][0]=1;
			valstk[++top1]=t;
		}
		else if(isdigit(s[i])) {
			Node t;t.init(),t.dp[s[i]-'0'][s[i]-'0']=1;
			valstk[++top1]=t;
		}
		else if(s[i]=='(') optstk[++top2]=s[i];
		else if(s[i]==')') {
			while(top2 && optstk[top2]!='(') {
				if(optstk[top2]=='^') valstk[top1-1]=valstk[top1-1]^valstk[top1];
				if(optstk[top2]=='|') valstk[top1-1]=valstk[top1-1]|valstk[top1];
				if(optstk[top2]=='&') valstk[top1-1]=valstk[top1-1]&valstk[top1];
				top1--,top2--;
			}
			top2--;
		} else if(s[i]=='^') {
			while(top2 && optstk[top2]!='(') {
				if(optstk[top2]=='^') valstk[top1-1]=valstk[top1-1]^valstk[top1];
				if(optstk[top2]=='|') valstk[top1-1]=valstk[top1-1]|valstk[top1];
				if(optstk[top2]=='&') valstk[top1-1]=valstk[top1-1]&valstk[top1];
				top1--,top2--;
			}
			optstk[++top2]=s[i];
		} else if(s[i]=='&') {
			while(top2 && optstk[top2]!='(' && optstk[top2]!='^') {
				if(optstk[top2]=='^') valstk[top1-1]=valstk[top1-1]^valstk[top1];
				if(optstk[top2]=='|') valstk[top1-1]=valstk[top1-1]|valstk[top1];
				if(optstk[top2]=='&') valstk[top1-1]=valstk[top1-1]&valstk[top1];
				top1--,top2--;
			}
			optstk[++top2]=s[i];
		} else if(s[i]=='|') {
			while(top2 && optstk[top2]!='(' && optstk[top2]!='^' && optstk[top2]!='&') {
				if(optstk[top2]=='^') valstk[top1-1]=valstk[top1-1]^valstk[top1];
				if(optstk[top2]=='|') valstk[top1-1]=valstk[top1-1]|valstk[top1];
				if(optstk[top2]=='&') valstk[top1-1]=valstk[top1-1]&valstk[top1];
				top1--,top2--;
			}
			optstk[++top2]=s[i];
		}
	}
	while(top2) {
		if(optstk[top2]=='^') valstk[top1-1]=valstk[top1-1]^valstk[top1];
		if(optstk[top2]=='|') valstk[top1-1]=valstk[top1-1]|valstk[top1];
		if(optstk[top2]=='&') valstk[top1-1]=valstk[top1-1]&valstk[top1];
		top1--,top2--;
	}
	return valstk[1].dp[0][1]|valstk[1].dp[1][0];
}

int main(){
	scanf("%d%s",&n,s+1);
	n=strlen(s+1);
	int res=Solve();
	puts(res?"YES":"NO");
}