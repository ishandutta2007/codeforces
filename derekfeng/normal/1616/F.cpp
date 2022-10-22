#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
int n,m;
struct info{
	bitset<260>c[3];
	info(){c[0].set(),c[1].reset(),c[2].reset();}
	vector<int>got(){
		vector<int>v;
		for(int i=0;i<=m;i++){
			if(c[0][i])v.push_back(0);
			if(c[1][i])v.push_back(1);
			if(c[2][i])v.push_back(2);
		}
		return v;
	}
};
info add(info a,info b){
	info ans;ans.c[0].reset();
	for(int i=0;i<3;i++)for(int j=0;j<3;j++)
		ans.c[(i+j)%3]|=(a.c[i]&b.c[j]);
	return ans;
}
vector<info>E;
int u[260],v[260],ans[260];
map<pii,int>mp;
void sol(){
	E.clear(),mp.clear();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int w;scanf("%d%d%d",&u[i],&v[i],&w),w--;
		if(u[i]>v[i])swap(u[i],v[i]);
		mp[make_pair(u[i],v[i])]=i;
		if(w<0)continue;
		info e;e.c[0][i]=0,e.c[1][i]=1;
		if(w==1)e.c[0][0]=0,e.c[1][0]=1;
		if(w==2)e.c[0][0]=0,e.c[2][0]=1;
		E.push_back(e);
	}
	for(int i=1;i<=m;i++)
		for(int j=i+1;j<=m;j++){
			int U=-1,V=-1;
			if(u[i]==u[j])U=v[i],V=v[j];
			if(u[i]==v[j])U=v[i],V=u[j];
			if(v[i]==u[j])U=u[i],V=v[j];
			if(v[i]==v[j])U=u[i],V=u[j];
			if(U<0)continue;
			if(U>V)swap(U,V);
			if(mp.find(make_pair(U,V))!=mp.end()){
				int p=mp[make_pair(U,V)];
				if(p>j){
					info e;
					e.c[0][i]=0,e.c[1][i]=1;
					e.c[0][j]=0,e.c[1][j]=1;
					e.c[0][p]=0,e.c[1][p]=1;
					E.push_back(e);
				}
			}
		}
	int it=0;
	for(int i=1;i<=m;i++){
		if(it==E.size())break;
		if(E[it].c[0][i]){
			for(int j=it+1;j<E.size();j++)if(!E[j].c[0][i]){
				swap(E[it],E[j]);
				break;
			}
			if(E[it].c[0][i])continue;
		}
		info A1=E[it],A2=add(E[it],E[it]);
		if(A1.c[2][i])swap(A1,A2),E[it]=A1;
		for(int j=it+1;j<E.size();j++){
			bool typ1=E[j].c[1][i],typ2=E[j].c[2][i];
			if(typ1)E[j]=add(E[j],A2);
			if(typ2)E[j]=add(E[j],A1);
		}
		it++;
	}
	memset(ans,-1,sizeof(ans));
	for(int i=E.size()-1;~i;i--){
		vector<int>V=E[i].got();
		bool Empty=1;
		for(int j=1;j<=m;j++)Empty&=(V[j]==0);
		if(Empty&&V[0]>0){puts("-1");return;}
		int pos=-1;
		for(int j=1;j<=m;j++)if(V[j]!=0){pos=j;break;}
		int tmp=V[0];
		for(int j=m;j>pos;j--)if(V[j]!=0){
			if(ans[j]<0)ans[j]=0;
			tmp=(tmp+6-V[j]*ans[j])%3;
		}
		if(V[pos]==2)tmp=tmp*2%3;
		ans[pos]=tmp;
	}
	for(int i=1;i<=m;i++)if(ans[i]<0)ans[i]=0;
	for(int i=1;i<=m;i++)printf("%d ",ans[i]+1);puts("");
}
int main(){
	int T;scanf("%d",&T);
	while(T--)sol();
}