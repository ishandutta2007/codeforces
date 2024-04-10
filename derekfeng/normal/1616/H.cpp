#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353;
int n,X,p2[150004];
int tot=1,sz[5000000],s[2][5000000];
void ins(int i,int d,int x){
	sz[i]++;
	if(d<0)return;
	int t=((x>>d)&1);
	if(!s[t][i])s[t][i]=++tot;
	ins(s[t][i],d-1,x);
}
int calc1(int i1,int i2,int d){
	if(!i1||!i2||d<0)return p2[sz[i1]+sz[i2]];
	if((X>>d)&1)return (ll)calc1(s[0][i1],s[1][i2],d-1)*calc1(s[1][i1],s[0][i2],d-1)%M;
	return ((ll)(p2[sz[s[0][i1]]]-1)*(p2[sz[s[1][i1]]]-1)+(ll)(p2[sz[s[0][i2]]]-1)*(p2[sz[s[1][i2]]]-1)+calc1(s[0][i1],s[0][i2],d-1)+calc1(s[1][i1],s[1][i2],d-1)+M-1)%M;
}
int calc(int i,int d){
	if(!i)return 1;
	if(d<0)return p2[sz[i]];
	if((X>>d)&1)return calc1(s[0][i],s[1][i],d-1);
	return ((calc(s[0][i],d-1)+calc(s[1][i],d-1))%M+M-1)%M;
}
int main(){
	p2[0]=1;for(int i=1;i<150004;i++)p2[i]=p2[i-1]*2%M;
	scanf("%d%d",&n,&X);
	while(n--){
		int x;scanf("%d",&x);
		ins(1,30,x);
	}
	printf("%d",(calc(1,30)+M-1)%M);
}