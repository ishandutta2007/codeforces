#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,n) for(int i=(0);i<(n);++i)
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

const int N=3000005;
char s[N],l[N],r[N];
int p[30],used[30],T,n,K;
int stk[N],top;

int cmp(char a[],char b[],int s){
	rep(i,s,n)
		if(a[i]<b[i])return -1;
		else if(a[i]>b[i])return 1;
	return 0;
}

bool dfs(int k,int L,int R){
	if(k>n||!L&&!R)return 1;
	if(p[s[k]]){
		if(L&&p[s[k]]<l[k])return 0;
		if(R&&p[s[k]]>r[k])return 0;
		if((!L||p[s[k]]>l[k])
		 &&(!R||p[s[k]]<r[k]))return 1;
		return dfs(k+1,L&&(p[s[k]]==l[k]),R&&(p[s[k]]==r[k]));
	}
	
	rep(i,l[k]+1,r[k]-1)
		if(!used[i]){
			used[p[s[k]]=i]=1;		stk[++top]=s[k];
			return 1;
		}
	rep(i,1,r[k]-1)
		if(!L&&!used[i]){
			used[p[s[k]]=i]=1;		stk[++top]=s[k];
			return 1;	
		}
	rep(i,l[k]+1,K)
		if(!R&&!used[i]){
			used[p[s[k]]=i]=1;		stk[++top]=s[k];
			return 1;
		}
	
	if(used[l[k]]&&used[r[k]])return 0;
	
	if(!R){
		if(used[l[k]])return 0;
		used[p[s[k]]=l[k]]=1;		stk[++top]=s[k];
		return dfs(k+1,L,R);
	}
	if(!L){
		if(used[r[k]])return 0;
		used[p[s[k]]=r[k]]=1;		stk[++top]=s[k];
		return dfs(k+1,L,R);
	}

	if(l[k]==r[k]){
		used[p[s[k]]=l[k]]=1;		stk[++top]=s[k];
		return dfs(k+1,L,R);
	}
	
	//L && R
	if(used[l[k]]){
		used[p[s[k]]=r[k]]=1;			stk[++top]=s[k];
		return dfs(k+1,0,1);
	}
	if(used[r[k]]){
		used[p[s[k]]=l[k]]=1;			stk[++top]=s[k];
		return dfs(k+1,1,0);
	}
	
	int flag=top;	
	used[p[s[k]]=l[k]]=1;			stk[++top]=s[k];
	if(dfs(k+1,1,0))return 1;	
	while(top>flag){
		used[p[stk[top]]]=0;
		p[stk[top]]=0;
		top--;
	}
	used[p[s[k]]=r[k]]=1;			stk[++top]=s[k];
	return dfs(k+1,0,1);
}

void MAIN(){
	scanf("%d",&K);
	scanf("%s",s+1);
	scanf("%s",l+1);
	scanf("%s",r+1);
	n=strlen(s+1);
	rep(i,1,n){
		s[i]=s[i]-'a'+1;
		l[i]=l[i]-'a'+1;
		r[i]=r[i]-'a'+1;
	}
	memset(p,0,sizeof p);
	memset(used,0,sizeof used);
	top=0;
	if(!dfs(1,1,1))puts("NO");
	else{
		puts("YES");
		rep(i,1,K)if(!p[i])
			rep(j,1,K)if(!p[i]&&!used[j])
				p[i]=j,used[j]=1;
		rep(i,1,K)putchar(p[i]+'a'-1);
		puts("");
	}
}

int main(){
	scanf("%d",&T);
	while(T--)MAIN();
	return 0;
}