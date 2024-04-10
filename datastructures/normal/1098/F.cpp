#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define ll long long
using namespace std;
struct BIT{
	ll tree[500005];
	int maxn;
	void mem(){
		memset(tree,0,sizeof(tree));
		maxn=500000;
		return;
	}
	int lowbit(int x){
		return x&(-x);
	}
	void add(int pos,int val){
		pos++;
		while(pos<=maxn)tree[pos]+=val,pos+=lowbit(pos);
		return;
	}
	ll ask(int l,int r){
		l++,r++;
		if (l>r)return 0;
		ll ans=0;
		while(r)ans+=tree[r],r-=lowbit(r);
		l--;
		while(l)ans-=tree[l],l-=lowbit(l);
		return ans;
	}
};
struct sam_node{
	int son[26],len,link;
	sam_node(){
		memset(son,0,sizeof(son));
		len=0,link=-1;
		return;
	}
}sam[400005];
int sam_cnt,sam_last,pos[200005];
int sam_ins(char x){
	int now=++sam_cnt;
	sam[now].len=sam[sam_last].len+1;
	int p=sam_last;
	while(p!=-1&&sam[p].son[x-'a']==0){
		sam[p].son[x-'a']=now;
		p=sam[p].link;
	}
	if (p==-1){
		sam[now].link=0;
		sam_last=now;
		return now;
	}
	int q=sam[p].son[x-'a'];
	if (sam[q].len==sam[p].len+1){
		sam[now].link=q;
		sam_last=now;
		return now;
	}
	int clone=++sam_cnt;
	sam[clone]=sam[q];
	sam[clone].len=sam[p].len+1;
	sam[now].link=sam[q].link=clone;
	while(p!=-1&&sam[p].son[x-'a']==q){
		sam[p].son[x-'a']=clone;
		p=sam[p].link;
	}
	sam_last=now;
	return now;
}
int u[400005],v[400005],first[400005],nxt[400005];
int fa[400005],depth[400005],sz[400005],son[400005],top[400005],idx,dfn[400005],nfd[400005],dfo[400005];
void dfs1(int now,int f,int d){
	fa[now]=f,depth[now]=d;
	sz[now]=1;
	son[now]=-1;
	for (int i=first[now];i;i=nxt[i]){
		if (v[i]==f)continue;
		dfs1(v[i],now,d+1);
		sz[now]+=sz[v[i]];
		if (son[now]==-1||sz[v[i]]>sz[son[now]])son[now]=v[i];
	}
	return;
}
void dfs2(int now,int f,int t){
	top[now]=t;
	++idx;
	dfn[now]=idx;
	nfd[idx]=now;
	if (son[now]!=-1)dfs2(son[now],now,t);
	for (int i=first[now];i;i=nxt[i])
		if (v[i]!=f&&v[i]!=son[now])dfs2(v[i],now,v[i]);
	dfo[now]=idx;
	return;
}
ll ans[400005];
namespace work1{
	vector<int> ins[400005];
	vector<int> qi[400005],qfg[400005],ql[400005],qc[400005],qid[400005];
	BIT bit1,bit2;
	void mem(){
		for (int i=0;i<=idx;i++){
			ins[i].clear();
			qi[i].clear();
			qfg[i].clear();
			ql[i].clear();
			qc[i].clear();
			qid[i].clear();
		}
		bit1.mem(),bit2.mem();
		return;
	}
	void add_insert(int d,int j){
		ins[d].push_back(j);
		return;
	}
	void add_query(int d,int i,int fg,int l,int c,int id){
		qi[d].push_back(i);
		qfg[d].push_back(fg);
		ql[d].push_back(l);
		qc[d].push_back(c);
		qid[d].push_back(id);
		return; 
	}
	void calc(){
		for (int i=1;i<=idx;i++){
			for (int j=0;j<(int)ins[i].size();j++)bit1.add(ins[i][j],1),bit2.add(ins[i][j],ins[i][j]);
			for (int j=0;j<(int)qi[i].size();j++){
				ans[qid[i][j]]+=qfg[i][j]*(bit2.ask(0,min(qi[i][j],qc[i][j]+ql[i][j]-1))+bit1.ask(0,min(qi[i][j],qc[i][j]+ql[i][j]-1))*(-ql[i][j]+1));
				ans[qid[i][j]]+=qfg[i][j]*(bit1.ask(qc[i][j]+ql[i][j],qi[i][j])*qc[i][j]); 
			}
		}
		return;
	} 
}
namespace work2{
	vector<int> ins[400005];
	vector<int> qfg[400005],ql[400005],qid[400005];
	void mem(){
		for (int i=0;i<=idx;i++){
			ins[i].clear();
			qfg[i].clear();
			ql[i].clear();
			qid[i].clear();
		}
		return;
	}
	void add_insert(int d,int j){
		ins[d].push_back(j);
		return;
	}
	void add_query(int d,int fg,int l,int id){
		qfg[d].push_back(fg);
		ql[d].push_back(l);
		qid[d].push_back(id);
		return; 
	}
	void calc(){
		ll cnt=0,sum=0;
		for (int i=1;i<=idx;i++){
			for (int j=0;j<(int)ins[i].size();j++)cnt++,sum+=ins[i][j];
			for (int j=0;j<(int)qfg[i].size();j++)ans[qid[i][j]]+=qfg[i][j]*(sum+cnt*(-ql[i][j]+1));
		}
		return;
	}
}
namespace work3{
	vector<int> insj[400005],inslen[400005];
	vector<int> qfg[400005],ql[400005],qid[400005];
	BIT bit1,bit2,bit3;
	void mem(){
		for (int i=0;i<=idx;i++){
			insj[i].clear();
			inslen[i].clear();
			qfg[i].clear();
			ql[i].clear();
			qid[i].clear();
		}
		bit1.mem(),bit2.mem(),bit3.mem();
		return;
	}
	void add_insert(int d,int j,int len){
		insj[d].push_back(j);
		inslen[d].push_back(len);
		return;
	}
	void add_query(int d,int fg,int l,int id){
		qfg[d].push_back(fg);
		ql[d].push_back(l);
		qid[d].push_back(id);
		return; 
	}
	void calc(){
		for (int i=1;i<=idx;i++){
			for (int j=0;j<(int)insj[i].size();j++){
				bit1.add(insj[i][j]-inslen[i][j],1);
				bit2.add(insj[i][j]-inslen[i][j],insj[i][j]);
				bit3.add(insj[i][j]-inslen[i][j],inslen[i][j]);
			}
			for (int j=0;j<(int)qfg[i].size();j++){
				ans[qid[i][j]]+=qfg[i][j]*bit3.ask(ql[i][j]-1,idx);
				ans[qid[i][j]]+=qfg[i][j]*(bit2.ask(0,ql[i][j]-2)+bit1.ask(0,ql[i][j]-2)*(-ql[i][j]+1));
			}
		}
		return;
	} 
}
namespace work4{
	BIT bit1,bit2,bit3;
	void mem(){
		bit1.mem();
		bit2.mem();
		bit3.mem();
		return;
	}
	void add(int d,int j,int len){
		bit1.add(d,1);
		bit2.add(d,j);
		bit3.add(d,len);
		return;
	}
	ll ask1(int dfnl,int dfnr,int l){
		return bit2.ask(dfnl,dfnr)+bit1.ask(dfnl,dfnr)*(-l+1);
	}
	ll ask2(int dfnl,int dfnr){
		return bit3.ask(dfnl,dfnr);
	}
}
int find(int dfnl,int dfnr,int x){
	if (sam[nfd[dfnr]].len<=x)return dfnr+1;
	int l=dfnl,r=dfnr,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (sam[nfd[mid]].len>x)ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
int n,q,l[200005],r[200005];
vector<int> ql[200005],qid[200005];
char s[200005];
int main(){
	ios::sync_with_stdio(false);
	cin>>(s+1);
	n=strlen(s+1);
	reverse(s+1,s+1+n);
	cin>>q;
	for (int i=1;i<=q;i++){
		cin>>l[i]>>r[i];
		l[i]=n-l[i]+1;
		r[i]=n-r[i]+1;
		swap(l[i],r[i]);
		ql[r[i]].push_back(l[i]);
		qid[r[i]].push_back(i);
	}
	for (int i=1;i<=n;i++)pos[i]=sam_ins(s[i]);
	for (int i=1;i<=sam_cnt;i++){
		u[i]=sam[i].link,v[i]=i;
		nxt[i]=first[u[i]],first[u[i]]=i;
	}
	dfs1(0,-1,1);
	dfs2(0,-1,0);
	work1::mem();
	for (int i=1;i<=n;i++)work1::add_insert(dfn[pos[i]],i);
	for (int i=1;i<=n;i++){
		int now=pos[i];
		while(now!=-1){
			int t=top[now];
			if (fa[t]!=-1){
				int qwq=fa[t];
				for (int j=0;j<(int)ql[i].size();j++){
					if (dfn[qwq]>1)work1::add_query(dfn[qwq]-1,i,-1,ql[i][j],sam[qwq].len,qid[i][j]);
					work1::add_query(dfo[qwq],i,1,ql[i][j],sam[qwq].len,qid[i][j]); 
					if (dfn[t]>1)work1::add_query(dfn[t]-1,i,1,ql[i][j],sam[qwq].len,qid[i][j]);
					work1::add_query(dfo[t],i,-1,ql[i][j],sam[qwq].len,qid[i][j]);
				}
			}
			now=fa[t];
		}
	}
	work1::calc();
	work2::mem();
	for (int i=1;i<=n;i++){
		int now=pos[i];
		while(now!=-1){
			work2::add_insert(dfn[now],i);
			now=fa[top[now]];
		}
	}
	for (int i=1;i<=n;i++){
		int now=pos[i];
		while(now!=-1){
			if (now!=top[now]){
				now=fa[now];
				for (int j=0;j<(int)ql[i].size();j++){
					int qwq=find(dfn[top[now]],dfn[now],i-ql[i][j]+1);
					if (qwq<=dfn[now]){
						if (qwq>1)work2::add_query(qwq-1,-1,ql[i][j],qid[i][j]);
						work2::add_query(dfn[now],1,ql[i][j],qid[i][j]);
					}
				}
			}
			now=fa[top[now]];
		}
	}
	work2::calc();
	work3::mem();
	for (int i=1;i<=n;i++){
		int now=pos[i];
		while(now!=-1){
			work3::add_insert(dfn[now],i,sam[now].len);
			now=fa[top[now]];
		}
	}
	for (int i=1;i<=n;i++){
		int now=pos[i];
		while(now!=-1){
			if (now!=top[now]){
				now=fa[now];
				for (int j=0;j<(int)ql[i].size();j++){
					int qwq=find(dfn[top[now]],dfn[now],i-ql[i][j]+1);
					if (qwq>dfn[top[now]]){
						if (dfn[top[now]]>1)work3::add_query(dfn[top[now]]-1,-1,ql[i][j],qid[i][j]);
						work3::add_query(qwq-1,1,ql[i][j],qid[i][j]);
					}
				}
			}
			now=fa[top[now]];
		}
	}
	work3::calc();
	work4::mem();
	for (int i=n;i>=1;i--){
		int now;
		now=pos[i];
		while(now!=-1){
			if (now!=top[now]){
				now=fa[now];
				for (int j=0;j<(int)ql[i].size();j++){
					int qwq=find(dfn[top[now]],dfn[now],i-ql[i][j]+1);
					ans[qid[i][j]]-=work4::ask1(qwq,dfn[now],ql[i][j]);
					ans[qid[i][j]]-=work4::ask2(dfn[top[now]],qwq-1);
				}
			}
			now=fa[top[now]];
		}
		now=pos[i];
		while(now!=-1){
			work4::add(dfn[now],i,sam[now].len);
			now=fa[top[now]];
		}
	}
	for (int i=1;i<=q;i++){
		ans[i]+=(r[i]-l[i]+1);
		ans[i]+=1ll*(l[i]-1)*(l[i]-2)/2;
		cout<<ans[i]<<endl;
 	}
	return 0;
}