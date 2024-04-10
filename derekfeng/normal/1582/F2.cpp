#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
vector<int>pos[5005];
int n;
int f[8200],nf[8200];
pii a[8200];
pii b[8200];
const int B=1023;
int f0[1024],f1[1024];
void sortf(){
	memset(f0,0,sizeof(f0)),memset(f1,0,sizeof(f1));
	for(int i=0;i<8200;++i)a[i]={f[i],i};
	for(int i=0;i<8200;++i)++f0[a[i].fi&B],++f1[a[i].fi>>10&B];
	for(int i=1;i<=B;++i)f0[i]+=f0[i-1],f1[i]+=f1[i-1];
	for(int i=8199;~i;--i)b[--f0[a[i].fi&B]]=a[i];
	for(int i=8199;~i;--i)a[--f1[b[i].fi>>10&B]]=b[i];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		pos[x].push_back(i);
	}
	for(int i=1;i<8200;i++)f[i]=n+1;
	for(int i=0;i<=5000;i++)if(!pos[i].empty()){
		sortf();
		memcpy(nf,f,sizeof(f));
		int cur=0;
		for(int j=0;j<8200;j++){
			int A=a[j].fi,I=a[j].se;
			while(cur<pos[i].size()&&pos[i][cur]<A)cur++;
			if(cur<pos[i].size())nf[I^i]=min(nf[I^i],pos[i][cur]);
		}
		memcpy(f,nf,sizeof(f));
	}
	int cnt=0;
	for(int i=0;i<8200;i++)if(f[i]<=n)cnt++;
	printf("%d\n",cnt);
	for(int i=0;i<8200;i++)if(f[i]<=n)printf("%d ",i);
}