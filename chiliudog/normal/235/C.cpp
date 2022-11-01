#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
typedef long long int64;
#define mk(a,b) make_pair(a,b);
#define w1 first
#define w2 second
typedef pair<int,int> pin;
const int maxn=2000005;
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}
int sz,parent[maxn],last,root,len[maxn],cnt[maxn],trans[maxn][26];
inline void add(int c,int l){
	int p=++sz;cnt[p]=1;len[sz]=l;for(;last&&!trans[last][c];last=parent[last])trans[last][c]=p;
	if(!last){parent[p]=root;last=p;return;}
	int q=trans[last][c];if(len[q]==len[last]+1){parent[p]=q;last=p;return;}
	int nq=++sz;len[nq]=len[last]+1;memcpy(trans[nq],trans[q],sizeof(trans[nq]));parent[nq]=parent[q];parent[p]=parent[q]=nq;
	for(;last&&trans[last][c]==q;last=parent[last])trans[last][c]=nq;last=p;
}
char s[maxn];
int sum[maxn],rank[maxn],fff[maxn];
int main(){
	scanf("%s",s+1);int n=strlen(s+1);root=last=++sz;
	rep(i,1,n)add(s[i]-'a',i);
	rep(i,1,sz)sum[len[i]]++;
	rep(i,1,n)sum[i]+=sum[i-1];
	per(i,sz,1)rank[sum[len[i]]--]=i;
	per(i,sz,1)cnt[parent[rank[i]]]+=cnt[rank[i]];
	int q;read(q);
	while(q--){
		scanf("%s",s+1);int m=strlen(s+1);
		rep(i,m+1,m<<1)s[i]=s[i-m];
		int p=root,ans=0,cl=0;
		rep(i,1,m<<1){
			int c=s[i]-'a';
			for(;p&&!trans[p][c];p=parent[p]);
			if(!p)p=root,cl=0;
			else{cl=min(cl,len[p])+1;p=trans[p][c];}
			if(cl>=m){
				while(parent[p]&&len[parent[p]]>=m)p=parent[p];
				if(fff[p]!=q+1)ans+=cnt[p],fff[p]=q+1;
			}
		}
		printf("%d\n",ans);
	}
    return 0;
}