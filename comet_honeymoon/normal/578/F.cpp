#include<bits/stdc++.h>
using namespace std;

int N,M,P;

struct Mat{
    int n;
    int a[415][415];
    void Gauss(int p,int &flg){
        if(p==n) return;
        if(!a[p][p])
            for(int i=p+1;i<=n;i++)
            if(a[i][p]){
                swap(a[i],a[p]);flg++;break;
            }
        if(!a[p][p]) return;
        for(int i=p+1;i<=n;i++)
            while(a[i][p]){
                int tmp=a[p][p]/a[i][p];
                for(int j=p;j<=n;j++)
                    a[p][j]=(a[p][j]-1LL*a[i][j]*tmp%P+P)%P;
                swap(a[p],a[i]);flg++;
            }
        Gauss(p+1,flg);
    }
    int Det(){
        int flg=0,ANS=1;
        Gauss(1,flg);
        for(int i=1;i<=n;i++) ANS=1LL*ANS*a[i][i]%P;
        return (flg&1)?(-ANS+P)%P:(ANS+P)%P;
    }
}ans[2];

char c[205][205];
int fa[40005];
int id(int i,int j){return i*(M+1)+j;} 
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void add_E(int x,int y){fa[find(x)]=find(y);}

int clr[40005],idx[2];

int main(){
	scanf("%d%d%d",&N,&M,&P);
	for(int i=0;i<(N+1)*(M+1);i++) fa[i]=i;
	for(int i=1;i<=N;i++){
		scanf("%s",c[i]+1);
		for(int j=1;j<=M;j++)
			if(c[i][j]=='\\') add_E(id(i-1,j-1),id(i,j));
			else if(c[i][j]=='/') add_E(id(i-1,j),id(i,j-1));
	}
	for(int i=0;i<=N;i++)
	for(int j=0;j<=M;j++)
		if(!clr[find(id(i,j))]) clr[find(id(i,j))]=++idx[(i+j)&1];
	
	ans[0].n=idx[0]-1;ans[1].n=idx[1]-1;
	for(int i=1;i<=N;i++)
	for(int j=1;j<=M;j++)if(c[i][j]=='*'){
		int idu=clr[find(id(i-1,j-1))],idv=clr[find(id(i,j))],typ=(i+j)&1;
		ans[typ].a[idu][idv]--,ans[typ].a[idv][idu]--,ans[typ].a[idu][idu]++,ans[typ].a[idv][idv]++;
		idu=clr[find(id(i-1,j))],idv=clr[find(id(i,j-1))],typ=(i+j+1)&1;
		ans[typ].a[idu][idv]--,ans[typ].a[idv][idu]--,ans[typ].a[idu][idu]++,ans[typ].a[idv][idv]++;
	}
	printf("%d\n",(ans[0].Det()+ans[1].Det())%P);
}