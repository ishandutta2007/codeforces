#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
#define R register int
#define I inline
#define V vector<int>::iterator
#define N 200001
#define M 400000
#define P 17984
int a[N],Last[N],Next[M],End[M],prime[N],ct;
char mark[N];
I void Link(int&x,int&y){
	ct++;
	End[ct]=y;
	Next[ct]=Last[x];
	Last[x]=ct;
}
vector<int>G[P];
I void DFS(int x,int dep,int&maxdep,int&ansid,const char A,const char B){
	if(dep>maxdep){
		maxdep=dep;
		ansid=x;
	}
	mark[x]=A;
	for(R i=Last[x];i!=0;i=Next[i]){
		if(mark[End[i]]==B){
			DFS(End[i],dep+1,maxdep,ansid,A,B);
		}
	}
}
int main(){
	for(R i=2;i!=N;i++){
		if(mark[i]!='N'){
			prime[ct]=i;
			ct++;
			for(R j=i;j<N;j+=i){
				mark[j]='N';
			}
		}
	}
	mark[1]='N';
	int n,x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		for(R j=0;prime[j]*prime[j]<=a[i];j++){
			if(a[i]%prime[j]==0){
				G[j].push_back(i);
				do{
					a[i]/=prime[j];
				}while(a[i]%prime[j]==0);
			}
		}
		int*t=lower_bound(prime,prime+P,a[i]);
		if(*t==a[i]){
			G[t-prime].push_back(i);
		}
	}
	ct=0;
	for(R i=1;i!=n;i++){
		scanf("%d%d",&x,&y);
		Link(x,y);
		Link(y,x);
	}
	int ans=0;
	for(R i=0;i!=P;i++){
		for(V T=G[i].begin();T!=G[i].end();T++){
			mark[*T]='Y';
		}
		for(V T=G[i].begin();T!=G[i].end();T++){
			if(mark[*T]=='Y'){
				int ansid,maxdep=0;
				DFS(*T,1,maxdep,ansid,'O','Y');
				DFS(ansid,1,maxdep,ansid,'N','O');
				if(maxdep>ans){
					ans=maxdep;
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}