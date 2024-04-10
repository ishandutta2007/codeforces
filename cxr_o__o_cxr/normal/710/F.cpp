#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=4e6+4;
int n,ch[N][26],tag[N],val[N],fail[N],tot=0;
char c[N];
struct AC{
	int rt[N],num=0,siz[24];
	inline void build(int x){
		static int p;
		p=rt[x]=++tot;
		for(int i=1,_;i<=n;i++){
			_=c[i]-'a';
			if(!ch[p][_])ch[p][_]=++tot;
			p=ch[p][_];
		}
		tag[p]++;
	}
	int merge(int x,int y){
		if(!x||!y)return x|y;
		tag[x]+=tag[y];
		for(int i=0;i<26;i++)
			ch[x][i]=merge(ch[x][i],ch[y][i]);
		return x;
	}
	inline void getfail(int st){
		static queue<int>q;
		while(!q.empty())q.pop(); 
		fail[st]=st;
		for(int i=0;i<26;i++)
			if(ch[st][i]){
				q.push(ch[st][i]);
				fail[ch[st][i]]=st;
				val[ch[st][i]]=tag[ch[st][i]];
			}
		while(!q.empty()){
			int x=q.front();q.pop();
			for(int i=0,v,p;i<26;i++){
				v=ch[x][i];
				if(!v)continue;
				q.push(v);
				p=fail[x];
				while(p!=st&&!ch[p][i])p=fail[p];
				if(ch[p][i])fail[v]=ch[p][i];
				else fail[v]=st;
				val[v]=tag[v]+val[fail[v]];
			}
		}
	}
	inline void insert(){
		build(++num);siz[num]=1;
		while(num>1&&siz[num]==siz[num-1]){
			siz[--num]<<=1;
			rt[num]=merge(rt[num],rt[num+1]);
		}
		getfail(rt[num]);
	}
	inline int query(){
		int ret=0;
		for(int t=1,_,p,x;t<=num;t++){
			p=rt[t];
			for(int i=1;i<=n;i++){
				_=c[i]-'a';
				if(ch[p][_])p=ch[p][_];
				else{
					x=fail[p];
					while(x!=rt[t]&&!ch[x][_])x=fail[x];
					if(ch[x][_])p=ch[x][_];
					else p=rt[t];
				}
				ret+=val[p];
			}
		}
		return ret;
	}
}ac[2];
int main(){
	int Q=read(),op;
	while(Q--){
		op=read();scanf("%s",c+1);
		n=strlen(c+1);
		if(op==3)cout<<ac[0].query()-ac[1].query()<<"\n";
		else ac[op-1].insert();
		fflush(stdout);
	}
	return (0-0);
}