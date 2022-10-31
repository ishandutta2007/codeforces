#include<bits/stdc++.h>
#define re register
#define vector basic_string
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,k,a[300002],ch[9000002][2],pos[9000002],tot;
inline void ins(re int x,re int y){
	re int nw=1;
	for(re int i=29;~i;--i){
		re int o=(x>>i)&1;
		if(!ch[nw][o])ch[nw][o]=++tot;
		nw=ch[nw][o];
	}
	pos[nw]=y;
}
inline int Get(re int x){
	re int s=0,nw=1;
	for(re int i=29;~i;--i){
		re int o=(x>>i)&1;
		if(ch[nw][o^1])nw=ch[nw][o^1],s^=1<<i;
		else nw=ch[nw][o];
	}
	if(s>=k)return pos[nw];
	return 0;
}
inline void solve(vector<int>&A,vector<int>&B){
	if(A.size()<=1){
		B=A;
		return;
	}
	vector<int>tmp,res;
	vector<int>W[32];
	for(re int i=0;i<A.size();++i){
		re int x=a[A[i]];
		for(re int j=29;~j;--j)
			if(x&(1<<j)){
				a[A[i]]^=1<<j;
				W[j].push_back(A[i]);
				break;
			}
		if(x==0){
			res.push_back(A[i]);
		}
	}
	for(re int i=29;~i;--i){
		if((1<<i)>k)tmp.clear(),solve(W[i],tmp),B+=tmp;
		else {
			for(re int j=0;j<W[i].size();++j)a[W[i][j]]^=1<<i;res+=W[i];
		}
	}
	for(re int i=1;i<=tot;++i)ch[i][0]=ch[i][1]=0;
	tot=1;
	for(re int i=0;i<res.size();++i){
		re int xx=Get(a[res[i]]);
		if(xx){
			B.push_back(xx),B.push_back(res[i]);
			return;
		}
		ins(a[res[i]],res[i]);
	}
	if(res.size())B.push_back(res[0]);
	return;
}
int main(){
	n=read(),k=read();
	if(k==0){
		printf("%d\n",n);
		for(re int i=1;i<=n;++i)printf("%d ",i);
		return 0;
	}
vector<int>A,ans;
	for(re int i=1;i<=n;++i)a[i]=read(),A.push_back(i);
	solve(A,ans);
	if(ans.size()<2)puts("-1");
	else{
		printf("%d\n",ans.size());
		for(re int i=0;i<ans.size();++i)printf("%d ",ans[i]);
	}
}