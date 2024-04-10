#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
#define R register int
#define L long long
#define V vector<Segment>::iterator
#define I inline
#define N 1000002
class Fenwick{
	int c[N];
	public:
		I void Add(int x,const int d){
			for(R i=x;i<N;i+=i&-i){
				c[i]+=d;
			}
		}
		I int GetSum(int x){
			int res=0;
			for(R i=x;i!=0;i-=i&-i){
				res+=c[i];
			}
			return res;
		}
}T1,T2;
struct Segment{
	int pos,rt;
};
I Segment Pair(int x,int y){
	Segment Tem;
	Tem.pos=x;
	Tem.rt=y;
	return Tem;
}
vector<Segment>A,B,C,D;
I bool Compare1(Segment x,Segment y){
	return x.rt<y.rt;
}
I bool Compare2(Segment x,Segment y){
	return x.pos<y.pos;
}
int main(){
	int n,m,l,r,x;
	scanf("%d%d",&n,&m);
	L ans=1;
	for(R i=0;i!=n;i++){
		scanf("%d%d%d",&x,&l,&r);
		x++;
		l++;
		r++;
		if(l==1){
			if(r==1000001){
				ans++;
			}
			A.push_back(Pair(x,r));
		}else{
			B.push_back(Pair(x,l));
		}
	}
	for(R i=0;i!=m;i++){
		scanf("%d%d%d",&x,&l,&r);
		x++;
		l++;
		r++;
		if(l==1){
			if(r==1000001){
				ans++;
			}
			C.push_back(Pair(x,r));
		}else{
			D.push_back(Pair(x,l));
		}
	}
	sort(A.begin(),A.end(),Compare1);
	sort(B.begin(),B.end(),Compare1);
	sort(C.begin(),C.end(),Compare2);
	sort(D.begin(),D.end(),Compare2);
	V p1=C.begin(),p2=D.begin();
	for(V T=A.begin();T!=A.end();T++){
		while(p1!=C.end()&&p1->pos<=T->rt){
			T1.Add(p1->rt,1);
			p1++;
		}
		while(p2!=D.end()&&p2->pos<=T->rt){
			T2.Add(p2->rt,1);
			p2++;
		}
		ans+=p1-C.begin()+T2.GetSum(T->pos)-T1.GetSum(T->pos-1); 
	}
	p1=C.begin();
	p2=D.begin();
	for(V T=B.begin();T!=B.end();T++){
		while(p1!=C.end()&&p1->pos<T->rt){
			T1.Add(p1->rt,-1);
			p1++;
		}
		while(p2!=D.end()&&p2->pos<T->rt){
			T2.Add(p2->rt,-1);
			p2++;
		}
		ans+=C.end()-p1+T2.GetSum(T->pos)-T1.GetSum(T->pos-1);
	}
	printf("%lld",ans);
	return 0;
}