#include<bits/stdc++.h>
using namespace std;
const int N=5+1e5,INF=1e9;
struct Mat{
	int a[3][3];
	Mat(){}
	int* operator[](int x){ return a[x]; }
	Mat operator*(Mat b){
		Mat c;
		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j){
				c[i][j]=INF;
				for(int k=0;k<3;++k)
					c[i][j]=min(c[i][j],a[i][k]+b[k][j]);
			}
		return c;
	}
};
struct SEG{
	Mat t[N<<2];
	void build(int p,int l,int r){
		t[p]=Mat();
		if(l==r){
			return;
		}
		int m=l+r>>1;
		build(p+p,l,m);
		build(p+p+1,m+1,r);
	}
	void change(int p,int l,int r,int x,char ch){
		if(x<l||r<x) return;
		if(l==r){
			for(int i=0;i<3;++i)
				for(int j=0;j<3;++j)
					t[p][i][j]=INF;
			int s=ch-'a';
			for(int i=0;i<3;++i){
				if(i!=s) t[p][i][i]=0;
				else{
					t[p][i][i]=1;
					if(i+1<3) t[p][i][i+1]=0;
				}
			}
			return;
		}
		int m=l+r>>1;
		change(p+p,l,m,x,ch);
		change(p+p+1,m+1,r,x,ch);
		t[p]=t[p+p]*t[p+p+1];
	}
	Mat query(){ return t[1]; }
}seg;
char s[N];
int cnt[3];
int main(){
	int n,q; scanf("%d%d",&n,&q);
	Mat base;
	for(int i=0;i<3;++i) 
		for(int j=0;j<3;++j)
			base[i][j]=INF;
	base[0][0]=0;
	scanf("%s",s+1);
	seg.build(1,1,n);
	for(int i=1;i<=n;++i) seg.change(1,1,n,i,s[i]);
	while(q--){
		int pos; char ch[5];
		scanf("%d%s",&pos,ch);
		seg.change(1,1,n,pos,ch[0]);
		Mat f=base*seg.query();
		printf("%d\n",min({f[0][0],f[0][1],f[0][2]}));
	}
	return 0;
}