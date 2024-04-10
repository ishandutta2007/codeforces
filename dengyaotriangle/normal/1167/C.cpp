#include<bits/stdc++.h>

using namespace std;


const int maxn=500005;

int fa[maxn],sz[maxn];

int gr(int n){
	if(fa[n]==n) return n;
	else fa[n]=gr(fa[n]);
	return fa[n];
}

void mrg(int a,int b){
	a=gr(a),b=gr(b);
	sz[a]+=sz[b];
	fa[b]=a;
}

bool ism(int a,int b){
	return gr(a)==gr(b);
}

int n,m;
int p[maxn];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		fa[i]=i;
		sz[i]=1;
	}
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++)cin>>p[i];
		for(int i=2;i<=k;i++) if(!ism(p[i-1],p[i])) mrg(p[i-1],p[i]);
	}
	for(int i=1;i<=n;i++){
		cout<<sz[gr(i)]<<' ';
	}
	return 0;
}