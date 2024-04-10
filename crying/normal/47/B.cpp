#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
int Num(char a){
	return a-'A'+1;
}
char a,b,cmp;
int g[5][5],size[5],ans[5],tot;
queue<int>q;
int main(){
	while(cin>>a>>cmp>>b){
		if(cmp=='<')swap(a,b);
		g[Num(a)][Num(b)]=1;
		size[Num(b)]++;
	}
	for(int i=1;i<=3;i++){
		if(!size[i])q.push(i),ans[++tot]=i;
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v=1;v<=3;v++){
			if(v==u)continue;
			if(g[u][v]){
				size[v]--;
				if(!size[v])ans[++tot]=v,q.push(v);
			}
		}
	}
	if(tot!=3){cout<<"Impossible";return 0;}
	cout<<(char)(ans[3]+'A'-1)<<(char)(ans[2]+'A'-1)<<(char)(ans[1]+'A'-1);
	return 0;
}