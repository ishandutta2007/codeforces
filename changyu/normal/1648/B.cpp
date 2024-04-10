#include<bits/stdc++.h>
const int N=1e6+3;
int n,m,a[N],b[N],f[N],g[N],c;
std::vector<int>d[N];
inline bool Exist(int l,int r){return b[r]-b[l-1];}
int main(){
	for(int i=1;i*i<N;i++)for(int j=i*i;j<N;j+=i)d[j].push_back(i);
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d%d",&n,&m);
	std::fill(b,b+1+m,0);
	std::fill(f,f+1+m,0);
	std::fill(g,g+1+m,0);
	c=0;
	for(int i=1;i<=n;i++)scanf("%d",a+i),++b[a[i]];
	for(int i=1;i<=m;i++){
		b[i]+=b[i-1];
		for(int j:d[i]){
			c-=f[j];
			f[j]=Exist(j,j)&&!Exist(i/j,i/j);
			c+=f[j];
			c-=g[j];
			g[j]=!Exist(j,j)&&Exist(i/(j+1)+1,i/j);
			c+=g[j];
			if(j>1){
				c-=g[j-1];
				g[j-1]=!Exist(j-1,j-1)&&Exist(i/j+1,i/(j-1));
				c+=g[j-1];
			}
		}
		if(b[i]>b[i-1]&&c){puts("No");goto Brk;}
	}
	puts("Yes");
	Brk:;
	}return 0;
}