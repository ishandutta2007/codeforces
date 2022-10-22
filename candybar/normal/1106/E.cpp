#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#include <map>
#define maxn 100005
#define maxm 205
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll infll = 0x3f3f3f3f3f3f3f3fll;
int n,m,k;
ll maxi[maxn << 2],tag[maxn << 2];
void up(int id,int l,int r){
	maxi[id] = max(maxi[id << 1],maxi[id << 1 | 1]);
	maxi[id] = max(maxi[id],tag[id]);
}
void down(int id,int l,int r){
	tag[id << 1] = max(tag[id << 1],tag[id]);
	maxi[id << 1] = max(tag[id],maxi[id << 1]);
	tag[id << 1 | 1] = max(tag[id << 1 | 1],tag[id]);
	maxi[id << 1 | 1] = max(tag[id],maxi[id << 1 | 1]);
	tag[id] = 0;
}
void update(int id,int l,int r,int ql,int qr,ll x){
	if(ql <= l && r <= qr){
		maxi[id] = max(maxi[id],x);
		tag[id] = max(tag[id],x);
	}else{
		down(id,l,r);
		int mid = (l + r) >> 1;
		if(ql <= mid) update(id << 1,l,mid,ql,qr,x);
		if(mid < qr) update(id << 1 | 1,mid + 1,r,ql,qr,x);
		up(id,l,r);
	}
}
ll query(int id,int l,int r,int pos){
	if(l == r) return maxi[id];
	down(id,l,r);
	int mid = (l + r) >> 1;
	if(pos <= mid) return query(id << 1,l,mid,pos);
	else return query(id << 1 | 1,mid + 1,r,pos);
}
ll val(int w,int d){ return (ll)w * 1000000 + d; }
int des[maxn],coin[maxn];
ll f[maxn][maxm];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++){
		int s,t,d,w;
		scanf("%d%d%d%d",&s,&t,&d,&w);
		update(1,1,n,s,t,val(w,d));
	}
	for(int i=1;i<=n;i++){
		ll val = query(1,1,n,i);
		coin[i] = val / 1000000;
		des[i] = val % 1000000;
	}
	memset(f,0x3f,sizeof(f));
	for(int i=0;i<=m;i++) f[n + 1][i] = 0;
	for(int i=n;i>=1;i--){
		for(int j=m;j>=0;j--){
			f[i][j] = min(f[i][j],f[i + 1][j + 1]);
			if(des[i] == 0) f[i][j] = min(f[i][j],f[i + 1][j]);
			else f[i][j] = min(f[i][j],f[des[i] + 1][j] + coin[i]);
		}
	}
	printf("%I64d\n",f[1][0]);
	return 0;
}