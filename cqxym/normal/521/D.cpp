#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct Ty1{
	int Max,Id;
}M[100001];
struct Opt{
	int Id,ty,x,y;
}p[100001];
struct Add{
	int Id;
	double add;
	bool operator<(const Add &z)const{
		return add==z.add?z.Id>Id:z.add<add;
	}
};
int a[100001];
vector<Add>G[100001];
vector<Add>Q;
bool Com(Add x,Add y){
	int A=x.Id,B=y.Id;
	if(p[A].ty==p[B].ty){
		if(x.add==y.add){
			return x.Id<y.Id;
		}
		return x.add<y.add;
	}
	return p[A].ty<p[B].ty;
}
int main(){
	int n,k,m,i,j;
	scanf("%d%d%d",&n,&k,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=k;i++){
		scanf("%d%d%d",&p[i].ty,&p[i].x,&p[i].y);
		p[i].Id=i;
		if(p[i].ty==1){
			if(p[i].y>M[p[i].x].Max){
				M[p[i].x].Max=p[i].y;
				M[p[i].x].Id=i;
			}
		}else if(p[i].ty==2){
			Add T;
			T.add=p[i].y;
			T.Id=i;
			G[p[i].x].push_back(T);
		}else if(p[i].y>1){
			Add T;
			T.add=p[i].y;
			T.Id=i;
			Q.push_back(T);
		}
	}
	for(i=1;i<=n;i++){
		if(M[i].Max>a[i]){
			Add T;
			T.add=M[i].Max-a[i];
			T.Id=M[i].Id;
			G[i].push_back(T);
		}
		sort(G[i].begin(),G[i].end());
		double sum=a[i];
		int l=G[i].size();
		for(j=0;j<l;j++){
			double t=G[i][j].add;
			G[i][j].add=t/sum+1;
			sum+=t;
			Q.push_back(G[i][j]);
		}
	}
	int l=Q.size();
	if(l>m){
		printf("%d\n",m);
	}else{
		printf("%d\n",l);
		m=l;
	}
	sort(Q.begin(),Q.end());
	sort(Q.begin(),Q.begin()+m,Com);
	for(i=0;i<m;i++){
		printf("%d ",Q[i].Id);
	}
	return 0;
}