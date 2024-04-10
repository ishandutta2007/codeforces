#include<bits/stdc++.h>
const int N=1e5+3,D=1<<17,A=1e9+7;
struct point{
	int x,y;
	inline bool operator<(point b)const{return x==b.x?y<b.y:x<b.x;}
}a[N],b[N];
struct segment{
	int x,y,l;
	inline bool operator<(segment b)const{return x==b.x?y<b.y:x<b.x;}
};
int n,m,c,d;
std::set<point>st0;std::set<segment>st1;
inline bool Cmp(const point&a,const point&b){return a.y-a.x<b.y-b.x;}
struct segment_tree{
	int mnxp[D+D],mnyp[D+D];
	inline int Mnx(int i,int j){return a[i].x<a[j].x?i:j;}
	inline int Mny(int i,int j){return a[i].y<a[j].y?i:j;}
	inline void Up(int k){
		mnxp[k]=Mnx(mnxp[k<<1],mnxp[k<<1|1]);
		mnyp[k]=Mny(mnyp[k<<1],mnyp[k<<1|1]);
	}
	inline void Init(){
		for(int k=1;k<D+D;k++)mnxp[k]=mnyp[k]=n+2;
		for(int i=1;i<=n;i++)mnxp[i+D]=mnyp[i+D]=i;
		for(int k=D-1;k;k--)Up(k);
	}
	inline void Update(int k){for(k+=D,k>>=1;k;k>>=1)Up(k);}
	inline int Minxp(int l,int r){
		int res=l;
		for(l+=D-1,r+=D+1;l^r^1;l>>=1,r>>=1){
		  if(~l&1)res=Mnx(res,mnxp[l^1]);
		  if( r&1)res=Mnx(res,mnxp[r^1]);
		}return res;
	}
	inline int Minyp(int l,int r){
		int res=l;
		for(l+=D-1,r+=D+1;l^r^1;l>>=1,r>>=1){
		  if(~l&1)res=Mny(res,mnyp[l^1]);
		  if( r&1)res=Mny(res,mnyp[r^1]);
		}return res;
	}
}t;
int main(){
	point z;segment w;
	scanf("%d%d",&n,&m);
	st0.insert((point){0,0});
	for(int i=1;i<=n;i++){
	  scanf("%d%d",&a[i].x,&a[i].y);
	  st0.insert(a[i]);
	}
	std::sort(a+1,a+1+n,Cmp);
	a[0]=(point){A,0};
	a[n+1]=(point){0,A};
	a[n+2]=(point){A,A};
	for(int i=0;i<=n+2;i++)b[i]=a[i];
	t.Init();
	c=d=0;
	for(int i,j,l=1,r=1,add;;){
	  for(;l<=n&&b[l].y-b[l].x<d-c;++l);
	  for(;l>=1&&b[l-1].y-b[l-1].x>=d-c;--l);
	  for(;r>=1&&b[r].y-b[r].x>d-c;--r);
	  for(;r<=n&&b[r+1].y-b[r+1].x<=d-c;++r);
	  for(i=r>=1?t.Minxp(1,r):n+2;a[i].x<=c;i=r>=1?t.Minxp(1,r):n+2)a[i]=(point){A,A},t.Update(i);
	  for(j=l<=n?t.Minyp(l,n):n+2;a[j].y<=d;j=l<=n?t.Minyp(l,n):n+2)a[j]=(point){A,A},t.Update(j);
	  if(a[i].x<A&&(a[j].y>=A||a[i].x-c<=a[j].y-d)){
		add=a[i].x-c-1;
		st1.insert((segment){c+=add,d+=add,add});
		if(a[i].x-c==a[i].y-d)++d;
		++c;
		a[i]=(point){A,A},t.Update(i);
		continue;
	  }
	  if(a[j].y<A&&(a[i].x>=A||a[j].y-d<=a[i].x-c)){
		add=a[j].y-d-1;
		st1.insert((segment){c+=add,d+=add,add});
		if(a[j].x-c==a[j].y-d)++c;
		++d;
		a[j]=(point){A,A},t.Update(j);
		continue;
	  }
	  if(a[i].x>=A&&a[j].y>=A){
		add=A-1-std::max(c,d);
		st1.insert((segment){c+add,d+add,add});
		break;
	  }
	}
	st1.insert((segment){-1,-1,0});
	st1.insert((segment){A,A,0});
	for(;m--;){
	  scanf("%d%d",&z.x,&z.y);
	  if(st0.count(z)){puts("LOSE");continue;}
	  w=*st1.lower_bound((segment){z.x,z.y,0});
	  puts(z.y-z.x==w.y-w.x&&w.y-w.l<z.y?"LOSE":"WIN");
	}return 0;
}