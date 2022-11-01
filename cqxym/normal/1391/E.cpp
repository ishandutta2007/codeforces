#include<stdio.h>
#include<vector>
using namespace std;
#define R register int
#define I inline
#define N 500001
#define M 2000005
int Last[N],Next[M],End[M],s[N],dep[N],ct,Lim;
bool success;
I void Link(int&x,int&y){
	End[ct]=y;
	Next[ct]=Last[x];
	Last[x]=ct;
	ct++;
}
I void DFS(int x,int Fe){
	if(success==true){
		return;
	}
	s[ct]=x;
	ct++;
	dep[x]=dep[End[Fe^1]]+1;
	if(dep[x]>=Lim){
		success=true;
		printf("PATH\n%d\n",Lim);
		for(R i=0;i!=Lim;i++){
			printf("%d ",s[i]);
		}
		puts("");
		return;
	}
	for(R i=Last[x];i!=0;i=Next[i]){
		if((i^Fe)!=1){
			int v=End[i];
			if(dep[v]==0){
				DFS(v,i);
			}
		}
	}
	ct--;
}
I void Solve(){
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	for(R i=1;i<=n;i++){
		Last[i]=dep[i]=0;
	}
	ct=2;
	Lim=n+1>>1;
	for(R i=0;i!=m;i++){
		scanf("%d%d",&x,&y);
		Link(x,y);
		Link(y,x);
	}
	success=false;
	ct=0;
	DFS(1,1);
	if(success==false){
		for(R i=1;i!=Lim;i++){
			s[i]=0;
		}
		vector<pair<int,int> >V;
		for(R i=1;i<=n;i++){
			if(s[dep[i]]==0){
				s[dep[i]]=i;
			}else{
				V.push_back(make_pair(s[dep[i]],i));
				s[dep[i]]=0;
			}
		}
		printf("PAIRING\n%d\n",V.size());
		for(vector<pair<int,int> >::iterator T=V.begin();T!=V.end();T++){
			printf("%d %d\n",T->first,T->second);
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(R i=0;i!=n;i++){
		Solve();
	}
	return 0;
}