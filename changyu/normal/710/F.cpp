#include<bits/stdc++.h>
typedef long long ll;
const int N=3e5+3,K=20;
int m,n,pos[N],len[N],fl[N],rt[K],son[N][26],fail[N],b[N],cnt,q[N],le,ri;char s[N],t[N];
inline void Clear(int&rt){
	for(int k=rt;k<=cnt;k++){
		b[k]=fail[k]=0;
		for(int c=0;c<26;c++)son[k][c]=0;
	}
	cnt=rt-1,rt=0;
}
inline void Build(int l,int r,int&rt){
	int k,w;
	rt=++cnt;
	for(int j=l;j<=r;j++){
		k=rt;
		for(int i=pos[j];i<pos[j]+len[j];i++){
			if(!son[k][s[i]-'a'])son[k][s[i]-'a']=++cnt;
			k=son[k][s[i]-'a'];
		}
		b[k]+=fl[j];
	}
	le=0,ri=-1;
	for(int c=0;c<26;c++)
		if(son[rt][c])
			fail[son[rt][c]]=rt,q[++ri]=son[rt][c];
	for(;le<=ri;){
		k=q[le++];
		b[k]+=b[fail[k]];
		for(int c=0;c<26;c++)if(son[k][c]){
			for(w=fail[k];w!=rt&&!son[w][c];w=fail[w]);
			fail[son[k][c]]=son[w][c]?son[w][c]:rt;
			q[++ri]=son[k][c];
		}
	}
}
inline void Add(int x){
	++n;
	pos[n]=pos[n-1]+len[n-1];
	len[n]=strlen(t);
	fl[n]=x;
	for(int i=0;t[i];i++)s[pos[n]+i]=t[i];

	int lg_lb=0;
	for(int i=0;rt[i];i++){
		Clear(rt[i]);
		++lg_lb;
	}
	Build(n-(n&-n)+1,n,rt[lg_lb]);
}
inline ll Query(){
	int k;ll res=0;
	for(int j=0;j<K;j++)
		if(rt[j]){
			k=rt[j];
			for(int i=0;t[i];i++){
				for(;k!=rt[j]&&!son[k][t[i]-'a'];k=fail[k]);
				if(son[k][t[i]-'a'])k=son[k][t[i]-'a'];
				res+=b[k];
			}
		}
	return res;
}
int main(){
	int o;
	scanf("%d",&m);
	for(int j=1;j<=m;j++){
		scanf("%d%s",&o,t);
		switch(o){
		case 1:
			Add(1);
			break;
		case 2:
			Add(-1);
			break;
		case 3:
			printf("%lld\n",Query());
			fflush(stdout);
			break;
		}
	}return 0;
}