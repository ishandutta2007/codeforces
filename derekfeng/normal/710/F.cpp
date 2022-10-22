#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int B=250,H=41,M=1e9+7;
int n,op,pw[300004],h[300004],N;
char s[300004];
int len[300004],hs[300004],v[300004];
vector<int>BIG;
unordered_set<int>st[255];
void init(){
	for(int i=1;i<=N;i++)h[i]=((ll)h[i-1]*H+s[i])%M;
}
int qry(int l,int r){
	return (h[r]+M-(ll)h[l-1]*pw[r-l+1]%M)%M;
}
int main(){
	pw[0]=1;for(int i=1;i<300004;i++)pw[i]=(ll)pw[i-1]*H%M;
	scanf("%d",&n);
	fflush(stdout);
	for(int i=1;i<=n;i++){
		scanf("%d%s",&op,s+1),N=strlen(s+1);
		fflush(stdout);
		init();
		if(op==3){
			int ans=0;
			for(auto x:BIG)for(int i=len[x];i<=N;i++)if(qry(i-len[x]+1,i)==hs[x])ans+=v[x];
			for(int i=1;i<=N;i++)for(int j=1;j<B&&i>=j;j++)ans+=st[j].count(qry(i-j+1,i));
			printf("%d\n",ans);
			fflush(stdout);
			continue;
		}
		hs[i]=h[N],v[i]=(op==1?1:-1),len[i]=N;
		if(N<B){
			if(op==1)st[N].insert(hs[i]);
			else st[N].erase(hs[i]);
		}else BIG.push_back(i);
	}
}