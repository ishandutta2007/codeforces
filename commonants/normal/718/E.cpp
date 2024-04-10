#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const int MX=100005,MXL=8,M=1<<8,inf=0x3f3f3f3f;
char s[MX];int n;
int q[MX],qc,A[MXL][MXL],S[MX],d[MXL][MX],f[MXL][M][MXL][M],c[MXL][M];
LL T[16];

int main(){
	int i,j,k,l,x;
	ios::sync_with_stdio(false);
	
	cin>>n>>(s+1);for(i=1;i<=n;i++)s[i]-='a';
	for(i=0;i<8;i++){
		for(qc=0,A[i][i]=1,j=1;j<=n;j++)if(s[j]==i)
			q[++qc]=j,d[i][j]=1;
		for(j=1;j<=qc;j++){
			if((x=q[j],!A[i][s[x]])){
				A[i][s[x]]=d[i][x];
				for(k=1;k<=n;k++)if(s[k]==s[x]&&!d[i][k])
					q[++qc]=k,d[i][k]=d[i][x]+1;
			}
			if(x>1&&!d[i][x-1])q[++qc]=x-1,d[i][x-1]=d[i][x]+1;
			if(x<n&&!d[i][x+1])q[++qc]=x+1,d[i][x+1]=d[i][x]+1;
		}
	}
	for(i=1;i<=n;i++){
		for(j=0;j<8;j++)S[i]|=(d[j][i]-A[j][s[i]])<<j;
		++c[s[i]][S[i]];
	}
	for(i=0;i<8;i++)
		for(j=0;j<M;j++)if(c[i][j]){
			for(k=0;k<8;k++)
				for(l=0;l<M;l++)if(c[k][l]){
					f[i][j][k][l]=inf;
					for(x=0;x<8;x++)if(A[x][i]&&A[x][k]){
						f[i][j][k][l]=min(f[i][j][k][l],(A[x][i]+((j>>x)&1))+(A[x][k]+((l>>x)&1))-1);
					}
					T[f[i][j][k][l]]+=(LL)c[i][j]*c[k][l];
				}
		}
	T[1]-=n;
	for(i=1;i<16;i++)T[i]>>=1;
	for(i=1;i<=n;i++)
		for(j=1;j<min(16,n-i+1);j++)if(j<f[s[i]][S[i]][s[i+j]][S[i+j]]){
			--T[f[s[i]][S[i]][s[i+j]][S[i+j]]],++T[j];
		}
	for(i=16;i--;)if(T[i])break;
	cout<<i<<' '<<T[i]<<endl;
	return 0;
}