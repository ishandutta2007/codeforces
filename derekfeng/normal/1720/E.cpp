#include<bits/stdc++.h>
using namespace std;
int n,K,v[505][505],cnt,ans;
bool ok[250005];
int a[250005],b[250005],c[250005],d[250005];
int A[505],B[505],C[505],D[505];
vector<int>vec[505];
int tot,hd[505],nx[250005],vl[250005];
void ins(int p,int x){
	int i=++tot;
	nx[i]=hd[p],hd[p]=i,vl[i]=x;
}
int main(){
	scanf("%d%d",&n,&K),ans=K;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
		scanf("%d",&v[i][j]),ok[v[i][j]]=1;
	for(int i=1;i<=n*n;i++)cnt+=ok[i],a[i]=c[i]=n+1;
	if(cnt<=K){printf("%d",K-cnt);return 0;}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		int x=v[i][j];
		a[x]=min(a[x],i),c[x]=min(c[x],j);
		b[x]=max(b[x],i),d[x]=max(d[x],j);
	}
	for(int i=1;i<=n*n;i++)if(ok[i])
		vec[d[i]].push_back(i);
	for(int i=1;i<=n;i++){
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		memset(hd,0,sizeof(hd));
		tot=0;
		for(int j=1;j<=n;j++){
			for(auto x:vec[j])if(a[x]>=i){
				int p=j-c[x],q=b[x]-i;
				if(p>=q)A[c[x]]++;	
				else{
					B[q]++;
					if(c[x]+q<=n)ins(c[x]+q,x);
				}
			}
			for(int p=hd[j];p;p=nx[p])B[b[vl[p]]-i]--,A[c[vl[p]]]++;
			D[0]=B[0];
			for(int p=1;p<=n;p++)D[p]=D[p-1]+B[p];
			for(int p=n;p;p--)C[p]=C[p+1]+A[p];
			for(int p=0;p<j&&p+i<=n;p++){
				int num=C[j-p]+D[p],t=cnt-num;
				if(t<=K&&K-t<=1)return puts("1"),0;
			}
		}
	}
	puts("2");
}