#include<bits/stdc++.h>
using namespace std;
const int N=5+1e5,INF=(int)1e9;
struct Matrix{
	int a[2][2];
	int* operator[](int x){ return a[x]; }
	Matrix(int a00=0,int a01=INF,int a10=INF,int a11=0){
		a[0][0]=a00,a[0][1]=a01;
		a[1][0]=a10,a[1][1]=a11;
	}
	Matrix operator*(Matrix b){
		Matrix c;
		c[0][0]=min({a[0][0]+b[0][0],a[0][1]+b[1][0],INF});
		c[0][1]=min({a[0][0]+b[0][1],a[0][1]+b[1][1],INF});
		c[1][0]=min({a[1][0]+b[0][0],a[1][1]+b[1][0],INF});
		c[1][1]=min({a[1][0]+b[0][1],a[1][1]+b[1][1],INF});
		return c;
	}
	void print(){
		for(int i=0;i<2;++i){
			for(int j=0;j<2;++j)
				printf("[%d]",a[i][j]);
			puts("");
		}
	}
};
struct SEG{	
	struct Node{
		Matrix key[4];
		int cnt[4];
		bool tag1,tag2;
	}t[N<<2];
	void up(int x){
		for(int i=0;i<4;++i){
			t[x].key[i]=t[x+x].key[i]*t[x+x+1].key[i];
			t[x].cnt[i]=t[x+x].cnt[i]+t[x+x+1].cnt[i];
		}
	}
	void put_tag(int x,bool tag1,bool tag2){
		if(tag1){
			swap(t[x].key[0],t[x].key[1]);
			swap(t[x].key[2],t[x].key[3]);
			swap(t[x].cnt[0],t[x].cnt[1]);
			t[x].tag1^=1;
		}
		if(tag2){
			swap(t[x].key[0],t[x].key[2]);
			swap(t[x].key[1],t[x].key[3]);
			swap(t[x].cnt[2],t[x].cnt[3]);
			t[x].tag2^=1;
		}
	}
	void down(int x){
		put_tag(x+x,t[x].tag1,t[x].tag2);
		put_tag(x+x+1,t[x].tag1,t[x].tag2);
		t[x].tag1=t[x].tag2=0;
	}
	void build(int a[],int b[],int n,int p,int l,int r){
		t[p].tag1=t[p].tag2=0;
		if(l==r){
			memset(t[p].cnt,0,sizeof(t[p].cnt));
			t[p].cnt[a[l]]=t[p].cnt[b[l]+2]=1;
			for(int i=0;i<2;++i)
				for(int j=0;j<2;++j){
					int cnt0=int((a[l]^i)==0)+int((b[l]^j)==0);
					int cnt1=int((a[l]^i)==1)+int((b[l]^j)==1);
					t[p].key[j<<1|i]=Matrix(cnt1,n+cnt0,n+cnt1,cnt0);
				}
			return;
		}
		int m=l+r>>1;
		build(a,b,n,p+p,l,m);
		build(a,b,n,p+p+1,m+1,r);
		up(p);
	}
	void change(int p,int l,int r,int x,int y,bool tag1,bool tag2){
		if(y<l||r<x) return;
		if(x<=l&&r<=y) return put_tag(p,tag1,tag2);
		int m=l+r>>1; down(p);
		change(p+p,l,m,x,y,tag1,tag2);
		change(p+p+1,m+1,r,x,y,tag1,tag2);
		up(p);
	}
	Matrix query_body(){ return t[1].key[0]; }
	Matrix query_head(){ return Matrix(t[1].cnt[1],t[1].cnt[0],INF,INF); }
	Matrix query_tail(){ return Matrix(t[1].cnt[3],INF,INF,t[1].cnt[2]); }
}seg[2];
int a[4][N],n,m,q;
char s[N];
int get_ans(){
	Matrix f1=seg[1].query_head()*seg[0].query_body()*seg[1].query_tail();
//	seg[0].query_body().print();
//	f1.print();
	Matrix f2=seg[0].query_head()*seg[1].query_body()*seg[0].query_tail();
//	f2.print();
	return min({f1[0][0],f1[0][1],f2[0][0],f2[0][1]});
}	
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<4;++i){
		scanf("%s",s+1); int len=strlen(s+1);
		for(int j=1;j<=len;++j)
			a[i][j]=(s[j]=='B');
	}
	seg[0].build(a[0],a[1],m,1,1,n);
	seg[1].build(a[2],a[3],n,1,1,m);
	printf("%d\n",get_ans());
	while(q--){
		scanf("%s",s);
		int l,r; scanf("%d%d",&l,&r);
		if(s[0]=='L') seg[0].change(1,1,n,l,r,1,0);
		if(s[0]=='R') seg[0].change(1,1,n,l,r,0,1);
		if(s[0]=='U') seg[1].change(1,1,m,l,r,1,0);
		if(s[0]=='D') seg[1].change(1,1,m,l,r,0,1);
		printf("%d\n",get_ans());
	}
	return 0;
}