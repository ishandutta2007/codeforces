#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m,opt,x,y;
char s[500005],c[5];
struct BIT{
	int tree[500005];
	BIT(){
		memset(tree,0,sizeof(tree));
		return;
	}
	inline int lowbit(int x){
		return x&(-x);
	}
	inline void add(int pos,int val){
		while(pos<=n)tree[pos]+=val,pos+=lowbit(pos);
		return;
	} 
	inline int ask(int l,int r){
		int ans=0;
		while(r)ans+=tree[r],r-=lowbit(r);
		l--;
		while(l)ans-=tree[l],l-=lowbit(l);
		return ans;
	}
}bit[26];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++)bit[s[i]-'a'].add(i,1);
	cin>>m;
	while(m--){
		scanf("%d",&opt);
		if (opt==1){
			scanf("%d%s",&x,c);
			bit[s[x]-'a'].add(x,-1);
			s[x]=c[0];
			bit[s[x]-'a'].add(x,1);
		}
		else{
			scanf("%d%d",&x,&y);
			int ans=0;
			for (int i=0;i<26;i++)
				if (bit[i].ask(x,y)>0)ans++;
			printf("%d\n",ans);
		}
	}
	return 0;
}//slhtxdy