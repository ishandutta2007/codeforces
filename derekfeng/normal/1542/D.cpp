#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353;
void add(int &A,int B){
	A+=B;
	if(A>=M)A-=M;
}
int f[503],g[503];
char buf[10];
int n;
int op[503],a[503],ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%s",buf);
		if(*buf=='-')op[i]=0;
		else op[i]=1,cin>>a[i];
	}
	for(int i=1;i<=n;i++)if(op[i]){
		memset(f,0,sizeof(f));
		f[0]=1;
		for(int j=1;j<i;j++){
			memcpy(g,f,sizeof(g));
			for(int k=0;k<=j;k++){
				if(op[j]==0)add(g[max(0,k-1)],f[k]);
				else{
					if(a[i]>=a[j])add(g[k+1],f[k]);
					else add(g[k],f[k]);
				}
			}
			memcpy(f,g,sizeof(f));
		}
		for(int k=i;k;k--)f[k]=f[k-1];
		f[0]=0;
		for(int j=i+1;j<=n;j++){
			memcpy(g,f,sizeof(g));
			for(int k=1;k<=j;k++){
				if(op[j]==0){
					if(k>1)add(g[k-1],f[k]);
				}else{
					if(a[i]>a[j])add(g[k+1],f[k]);
					else add(g[k],f[k]);
				}
			}
			memcpy(f,g,sizeof(f));
		}
		int coef=0;
		for(int i=1;i<=n;i++)add(coef,f[i]);
		add(ans,(ll)coef*a[i]%M);
	}
	cout<<ans;
}