#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353;
int dcnt[5]={2,3,5,9,17};
int K,A,H,n;
int pA[20];
int ans;
bool w[20];
int h[20],p[20];
vector<int>tmp;
map<int,vector<int> >v1[20],v2[20];
void built(int id,int l,int r,int d){
	if(l==r){
		h[id]=l;
		return;
	}
	if(d==K-1){
		h[id]=l+w[id];
		p[l+(w[id]^1)]=dcnt[d];
		return;
	}
	int mid=(l+r)>>1;
	built(id*2+1,l,mid,d+1),built(id*2+2,mid+1,r,d+1);
	int wn[2]={h[id*2+1],h[id*2+2]};
	h[id]=wn[w[id]];
	p[wn[w[id]^1]]=dcnt[d];
}
int main(){
	scanf("%d%d%d",&K,&A,&H);n=(1<<K)>>1;
	pA[0]=1;for(int i=1;i<20;i++)pA[i]=(ll)pA[i-1]*A%M;
	for(int i=0;i<(1<<(n-1));i++){
		for(int j=0;j<n-1;j++)w[j]=i&(1<<j);
		built(0,1,n,1);
		p[h[0]]=dcnt[0];
		ans=0;
		for(int j=1;j<=n;j++)(ans+=(ll)j*pA[p[j]]%M)%=M;
		tmp.clear();
		for(int j=1;j<=n;j++)tmp.push_back(p[j]);
		v1[h[0]][ans]=tmp;
		ans=0;
		for(int j=1;j<=n;j++)(ans+=(ll)(j+n)*pA[p[j]]%M)%=M;
		v2[h[0]][ans]=tmp;
	}
	for(int i=1;i<=n;i++)for(map<int,vector<int> >::iterator it=v1[i].begin();it!=v1[i].end();it++){
		int w=i,hh=it->first;
		tmp=it->second;
		tmp[w-1]=1;
		(hh+=M-(ll)w*pA[2]%M)%=M;
		(hh+=(ll)w*A%M)%=M;
		int hhh=(M+H-hh)%M;
		for(int j=1;j<=n;j++)if(v2[j].find(hhh)!=v2[j].end()){
			for(auto x:tmp)printf("%d ",x);
			tmp=v2[j][hhh];
			for(auto x:tmp)printf("%d ",x);
			return 0;
		}
	}
	for(int i=1;i<=n;i++)for(map<int,vector<int> >::iterator it=v2[i].begin();it!=v2[i].end();it++){
		int w=i,hh=it->first;
		(hh+=M-(ll)(w+n)*pA[2]%M)%=M;
		(hh+=(ll)(w+n)*A%M)%=M;
		int hhh=(M+H-hh)%M;
		for(int j=1;j<=n;j++)if(v1[j].find(hhh)!=v1[j].end()){
			tmp=v1[j][hhh];
			for(auto x:tmp)printf("%d ",x);
			tmp=it->second;
			tmp[w-1]=1;
			for(auto x:tmp)printf("%d ",x);
			return 0;
		}
	}
	puts("-1");
}