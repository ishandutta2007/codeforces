#include<bits/stdc++.h>
const int N=1050005;
using namespace std;

int fa[N],p[N],cnt,n,a[N],v[N],q;

map<int,int> r[N];

int gf(int k){
	return k==fa[k]?k:fa[k]=gf(fa[k]);
}

void init(){
	for(int i=1;i<N;i++)fa[i]=i;
	for(int i=2;i<N;i++){
		if(!v[i])v[i]=i,p[++cnt]=i;
		for(int j=1;j<=cnt&&p[j]*i<N;j++){
			v[i*p[j]]=p[j];
			if(i%p[j]==0)break;
		}
	}
}

void mrg(int a,int b){
	int x=gf(a),y=gf(b);
	if(x!=y)fa[x]=y;
}

void ist(int p){
	if(v[p]==p)return;
	int pr=v[p];p/=v[p];
	while(p!=1)mrg(v[p],pr),pr=v[p],p/=v[p];
}

int solve(int x,int y){
	int fx=gf(v[a[x]]),fy=gf(v[a[y]]);
	if(fx==fy)return 0;
	if(r[fx][fy]||r[fy][fx])return 1;
	return 2;
}

int main(){
	scanf("%d%d",&n,&q);
	init();
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),ist(a[i]);
	for(int i=1;i<=n;i++){
		int x=a[i]+1,q=a[i];
		vector<int> w;
		while(x!=1)w.push_back(v[x]),x/=v[x];
		while(q!=1)w.push_back(v[q]),q/=v[q];
		sort(w.begin(),w.end()),unique(w.begin(),w.end());
		int s=1;
		for(int i=1;i<w.size();i++)
			if(w[i]<=w[i-1])break;
			else s=i+1;
		for(int i=0;i<s;i++)	
			for(int j=i+1;j<s;j++)
				r[gf(w[i])][gf(w[j])]=1;
	}
	for(int i=1,x,y;i<=q;i++){
		scanf("%d%d",&x,&y);
		printf("%d\n",solve(x,y));
	}
}