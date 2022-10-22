/*
 * @Author: BilyHurington
 * @Date: 2020-08-22 17:19:39
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-08-22 20:56:51
 */
#include<bits/stdc++.h>
using namespace std;
int n,m,mod;char s[110][110];
long long fast_pow(long long x,long long k){
    long long ans=1;
    while(k){
        if(k&1) ans=ans*x%mod;
        x=x*x%mod;k>>=1;
    }
    return ans;
}
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int del(int x,int y){return x>=y?x-y:x+mod-y;}
void Add(int &x,int y){x+=y;if(x>=mod) x-=mod;}
void Del(int &x,int y){x-=y;if(x<0) x+=mod;}
struct Matrix_Theorem{
    int N,mat[410][410];
    void Add(int i,int j){
		// printf("Add %d %d\n",i,j);
        mat[i][i]++;mat[j][j]++;
		mat[i][j]--;mat[j][i]--;
    }
    void Eliminate(int i,int j){
        if(i==j) return;
        if(!mat[j][i]) return;
        long long tmp=mat[j][i]*fast_pow(mat[i][i],mod-2)%mod;
        for(int k=1;k<=N;k++) Del(mat[j][k],1ll*mat[i][k]*tmp%mod);
    }
    int Solve(){
        int ans=1;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++) mat[i][j]=(mat[i][j]%mod+mod)%mod;
        }
		// for(int i=1;i<=N;i++){
		// 	for(int j=1;j<=N;j++){
		// 		printf("%d ",mat[i][j]);
		// 	}
		// 	printf("\n");
		// }
		N--;
        for(int i=1;i<=N;i++){
            int ok_j=0;
            for(int j=i;j<=N;j++) if(mat[j][i]) ok_j=j;
            if(!ok_j) return 0;
            if(ok_j!=i){
                ans=mod-ans;
                for(int j=1;j<=N;j++) swap(mat[i][j],mat[ok_j][j]);
			}
		// for(int i=1;i<=N;i++){
		// 	for(int j=1;j<=N;j++){
		// 		printf("%d ",mat[i][j]);
		// 	}
		// 	printf("\n");
		// }
            for(int j=i+1;j<=N;j++) Eliminate(i,j);
		// for(int i=1;i<=N;i++){
		// 	for(int j=1;j<=N;j++){
		// 		printf("%d ",mat[i][j]);
		// 	}
		// 	printf("\n");
		// }
        }
        for(int i=1;i<=N;i++) ans=1ll*ans*mat[i][i]%mod;
        return ans;
    }
}M[2];
int Fa[20010];
int find(int x){return Fa[x]==x?x:Fa[x]=find(Fa[x]);}
map<int,int> mp[2];
int ID(int p,int q){return (p-1)*(m+1)+q;}
int I[20010];
int id(int p,int q){return I[find(ID(p,q))];}
int main(){
    scanf("%d %d %d",&n,&m,&mod);
	for(int i=1;i<=n+1;i++) for(int j=1;j<=m+1;j++) Fa[ID(i,j)]=ID(i,j);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf(" %c",&s[i][j]);
			if(s[i][j]=='\\'){
				Fa[find(ID(i,j))]=find(ID(i+1,j+1));
				// printf("%d %d\n",ID(i,j),ID(i+1,j+1));
			}
			if(s[i][j]=='/'){
				Fa[find(ID(i+1,j))]=find(ID(i,j+1));
				// printf("%d %d\n",ID(i+1,j),ID(i,j+1));
			}
		}
	}
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=m+1;j++){
			int x=ID(i,j),t=(i+j)&1;
			if(Fa[x]==x) I[x]=++M[t].N;
		}
	}
	// for(int i=1;i<=n+1;i++){
	// 	for(int j=1;j<=m+1;j++){
	// 		printf("%d ",id(i,j));
	// 	}
	// 	printf("\n");
	// }
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]!='*') continue;
			int t=(i+j)&1;
			M[t].Add(id(i,j),id(i+1,j+1));
			M[t^1].Add(id(i+1,j),id(i,j+1));
		}
	}
	printf("%d",add(M[0].Solve(),M[1].Solve()));
    return 0;
}