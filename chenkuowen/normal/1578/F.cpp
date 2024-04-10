#include<bits/stdc++.h>
using namespace std;
const int N=5+1e6;
struct OP{
	vector<int> id,cnt,val;
	__int128 ans;
	OP(){ans=0; }
	void erase_id(int x){
		int p=upper_bound(id.begin(),id.end(),x)-id.begin()-1;
		assert(p>=0);
		cnt[p]--;
		ans-=val[p];
	}
	void add(int idx,int cntx,int valx){
		while(!val.empty()&&val.back()>=valx){
			cntx+=cnt.back();
			idx=id.back();
			ans-=1ll*val.back()*cnt.back();
			cnt.pop_back();
			val.pop_back();
			id.pop_back();
		}
		cnt.push_back(cntx);
		val.push_back(valx);
		id.push_back(idx);
		ans+=1ll*val.back()*cnt.back();
	}
}op;
struct DSF{
	int fa[N];
	DSF(){ for(int i=0;i<N;++i) fa[i]=i; }
	int fs(int x){
		if(fa[x]!=x) fa[x]=fs(fa[x]);
		return fa[x];
	}
	void merge(int x,int y){
		fa[fs(y)]=fs(x);
	}
}dsf;
struct Str{
	int nxt[N],n;
	char s[N];
	Str(){nxt[0]=-1,n=0; }
	int& operator[](int x){ return nxt[x]; }	
	void append(char c,int w){
		s[++n]=c;
		int j=nxt[n-1];
		for(;j>-1&&s[j+1]!=s[n];j=nxt[j]);
		nxt[n]=j+1;
		if(nxt[n]==nxt[n-1]+1) dsf.merge(nxt[n],n);
		for(int x=n;x>0;x=nxt[x]){
			x=dsf.fs(x);
			if(x==0) break;
			int j=x-1;
			while(nxt[x]!=nxt[j]+1){
				if(nxt[j]>0){
					op.erase_id(n-1-nxt[j]);
				}
				j=nxt[j];
			}
		}
		if(s[n]==s[1]) op.add(n-1,1,w);
		else op.add(n,0,w);
	}
}str;
void pi(__int128 x){
	if(x>9) pi(x/10);
	putchar(x%10+'0');
}
int main(){
	int top; scanf("%d",&top);
	__int128 ans=0;
	for(int i=1;i<=top;++i){
		char s[5]; int w; scanf("%s%d",s,&w);
		char c=(s[0]-'a'+ans)%26+'a';
		w^=(ans&((1ll<<30)-1));
		str.append(c,w);
		ans+=op.ans;
		pi(ans);
		puts("");
	}
	return 0;
}