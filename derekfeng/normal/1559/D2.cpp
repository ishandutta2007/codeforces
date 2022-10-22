#include<bits/stdc++.h>
using namespace std;
struct Uni{
	int f[100004];
	void init(int n){
		for(int i=1;i<=n;i++)f[i]=i;
	}
	int F(int x){
		return f[x]==x?x:f[x]=F(f[x]);
	}
	void merge(int u,int v){
		u=F(u),v=F(v);
		f[u]=v;
	}
}f1,f2;
int n,m1,m2;
vector<int>a1,a2,A,B;
int main(){
	scanf("%d%d%d",&n,&m1,&m2);f1.init(n),f2.init(n);
	while(m1--){
		int u,v;scanf("%d%d",&u,&v);
		f1.merge(u,v);
	}
	while(m2--){
		int u,v;scanf("%d%d",&u,&v);
		f2.merge(u,v); 
	}
	for(int i=2;i<=n;i++){
		if(f1.F(i)!=f1.F(1)&&f2.F(i)!=f2.F(1)){
			a1.push_back(1),a2.push_back(i);
			f1.merge(1,i),f2.merge(1,i);
		}
	}
	for(int i=1;i<=n;i++){
		if(f1.F(i)==f1.F(1)&&f2.F(i)!=f2.F(1)&&f2.F(i)==i)A.push_back(i);
		if(f2.F(i)==f2.F(1)&&f1.F(i)!=f1.F(1)&&f1.F(i)==i)B.push_back(i);
	}
	int N=min(A.size(),B.size());
	printf("%d\n",a1.size()+N);
	for(int i=0;i<a1.size();i++)printf("%d %d\n",a1[i],a2[i]);
	for(int i=0;i<N;i++)printf("%d %d\n",A[i],B[i]);
}