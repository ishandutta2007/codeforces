#include<stdio.h>
#include<algorithm>
#define R register int
#define C const int
#define I inline
#define N 100001
I void Min(int&x,C y){
	if(x>y){
		x=y;
	}
}
int sl[N],sr[N],ans[N],root[400000],ct;
struct Segment{
	int Lf,Rt,Id;
	I friend bool operator<(Segment A,Segment B){
		return A.Rt-A.Lf>B.Rt-B.Lf;
	}
}s[N];
struct SegmentNode{
	int Ls,Rs,MinT;
}t[40000000];
I void GetNode(int&x){
	ct++;
	x=ct;
	t[x].MinT=N;
}
I void InitHost(int p,int lf,int rt){
	GetNode(root[p]);
	if(lf!=rt){
		InitHost(p<<1,lf,lf+rt>>1);
		InitHost(p<<1|1,lf+rt+2>>1,rt);
	}
}
I void MobInsert(int p,int lf,int rt,C x,C d){
	Min(t[p].MinT,d);
	if(lf!=rt){
		int mid=lf+rt>>1;
		if(x>mid){
			if(t[p].Rs==0){
				GetNode(t[p].Rs);
			}
			MobInsert(t[p].Rs,mid+1,rt,x,d);
		}else{
			if(t[p].Ls==0){
				GetNode(t[p].Ls);
			}
			MobInsert(t[p].Ls,lf,mid,x,d);
		}
	}
}
I void HostInsert(int p,int lf,int rt,C l,C r,C d,int&n){
	MobInsert(root[p],1,n,r,d);
	if(lf!=rt){
		int mid=lf+rt>>1;
		if(l>mid){
			HostInsert(p<<1|1,mid+1,rt,l,r,d,n);
		}else{
			HostInsert(p<<1,lf,mid,l,r,d,n);
		}
	}
}
I int MobFind(int p,int lf,int rt,C l,C r){
	if(l<=lf&&rt<=r){
		return t[p].MinT;
	}
	int mid=lf+rt>>1,res=N;
	if(l<=mid&&t[p].Ls!=0){
		res=MobFind(t[p].Ls,lf,mid,l,r);
	}
	if(r>mid&&t[p].Rs!=0){
		Min(res,MobFind(t[p].Rs,mid+1,rt,l,r));
	}
	return res;
}
I int HostFind(int p,int lf,int rt,C l,C r,int&n){
	if(l<=lf&&rt<=r){
		return MobFind(root[p],1,n,l,r);
	}
	int mid=lf+rt>>1,res=N;
	if(l<=mid){
		res=HostFind(p<<1,lf,mid,l,r,n);
	}
	if(r>mid){
		Min(res,HostFind(p<<1|1,mid+1,rt,l,r,n));
	}
	return res;
}
I void Solve(int l,int r,C d,int&n){
	int x=HostFind(1,1,n,l,r,n);
	if(x!=N){
		ans[d]+=sr[x]-sl[x]+1;
		if(sl[x]!=l){
			Solve(l,sl[x]-1,d,n);
		}
		if(sr[x]!=r){
			Solve(sr[x]+1,r,d,n);
		}
	}
}
int main(){
	int n,m,lt=0;
	scanf("%d%d",&n,&m);
	InitHost(1,1,n);
	for(R i=0;i!=m;i++){
		scanf("%d%d",sl+i,sr+i);
		s[i].Lf=sl[i];
		s[i].Rt=sr[i];
		s[i].Id=i;
	}
	std::sort(s,s+m);
	for(R i=n;i!=0;i--){
		while(lt!=m&&s[lt].Rt-s[lt].Lf+2>i){
			HostInsert(1,1,n,s[lt].Lf,s[lt].Rt,s[lt].Id,n);
			lt++;
		}
		Solve(1,n,i,n);
	}
	for(R i=1;i<=n;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}