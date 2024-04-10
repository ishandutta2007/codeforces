#include<stdio.h>
#include<string.h>
#include<vector>
#include<set>
using namespace std;
#define R register int
#define L long long
#define I inline
#define N 200001
char s[100002];
struct SAM{
	int Par[N],Len[N],Child[N][26],Pos[N],Tot,Last;
	I void Init(){
		Len[1]=Tot=Last=1;
	}
	I void Append(int x,int c){
		Tot++;
		int p=Last,cur=Tot;
		Pos[x]=Tot;
		Last=Tot;
		Len[Tot]=Len[p]+1;
		while(p!=0&&Child[p][c]==0){
			Child[p][c]=cur;
			p=Par[p];
		}
		if(p==0){
			Par[cur]=1;
		}else{
			int q=Child[p][c];
			if(Len[p]+1==Len[q]){
				Par[cur]=q;
			}else{
				Tot++;
				int nq=Tot;
				Len[nq]=Len[p]+1;
				for(R i=0;i!=26;i++){
					Child[nq][i]=Child[q][i];
				}
				Par[nq]=Par[q];
				Par[q]=Par[cur]=nq;
				while(Child[p][c]==q&&p!=0){
					Child[p][c]=nq;
					p=Par[p];
				}
			}
		}
	}
}Pre,Suf;
int h[N],sz[N],f[N],dep[N],p[N],val[N],Top[N],dfn[N];
vector<int>G[N];
I void PreDFS(int x,int&ct){
	ct++;
	dfn[x]=ct;
	p[ct]=x;
	sz[x]=1;
	for(int T:G[x]){
		dep[T]=dep[x]+1;
		PreDFS(T,ct);
		sz[x]+=sz[T];
		if(sz[T]>sz[h[x]]){
			h[x]=T;
		}
	}
}
I void ReDFS(int x,int t){
	Top[x]=t;
	if(h[x]!=0){
		ReDFS(h[x],t);
		for(int T:G[x]){
			if(T!=h[x]){
				ReDFS(T,T);
			}
		}
	}
}
I int LCA(int x,int y){
	while(Top[x]!=Top[y]){
		if(dep[Top[x]]>dep[Top[y]]){
			x=f[Top[x]];
		}else{
			y=f[Top[y]];
		}
	}
	return dep[x]<dep[y]?x:y;
}
I int Calc(int x,int y){
	return Suf.Len[LCA(x,y)];
}
set<int>S[N];
L sum[N];
I void Merge(set<int>&A,set<int>&B,L&sa,L&sb){
	if(A.size()<B.size()){
		A.swap(B);
		sa=sb;
	}
	for(int T:B){
		auto T0=A.insert(T).first;
		sa+=Suf.Len[p[*T0]];
		auto Tr=next(T0);
		if(T0!=A.begin()){
			auto Tl=prev(T0);
			if(Tr!=A.end()){
				sa+=Calc(p[*Tl],p[*Tr]);
			}
			sa-=Calc(p[*Tl],p[*T0]);
		}
		if(Tr!=A.end()){
			sa-=Calc(p[*T0],p[*Tr]);
		}
	}
	set<int>().swap(B); 
}
I void DFS(int x,L&ans){
	if(val[x]!=0){
		S[x].insert(dfn[val[x]]);
		sum[x]+=Suf.Len[val[x]];
	}
	for(int T:G[x]){
		DFS(T,ans);
		Merge(S[x],S[T],sum[x],sum[T]);
	}
	ans+=sum[x]*(Pre.Len[x]-Pre.Len[Pre.Par[x]]);
}
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1),m;
	Pre.Init();
	Suf.Init();
	for(R i=1;i<=n;i++){
		Pre.Append(i,s[i]-'a');
	}
	for(R i=n;i!=0;i--){
		Suf.Append(i,s[i]-'a');
	}
	L ans=1;
	m=Suf.Tot;
	for(int i=2;i<=m;i++){
		f[i]=Suf.Par[i];
		G[f[i]].push_back(i);
		ans+=Suf.Len[i]-Suf.Len[Suf.Par[i]];
	}
	m=0;
	PreDFS(1,m);
	ReDFS(1,1);
	for(R i=1;i<=n;i++){
		val[i==1?1:Pre.Pos[i-1]]=i==n?1:Suf.Pos[i+1];
	}
	m=Pre.Tot;
	for(R i=1;i<=m;i++){
		vector<int>().swap(G[i]);
	}
	for(int i=2;i<=m;i++){
		G[Pre.Par[i]].push_back(i);
	}
	DFS(1,ans);
	printf("%lld",ans);
	return 0;
}