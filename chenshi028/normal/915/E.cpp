#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
#define write(a) printf("%d",a)
const int o=1.8e7;
struct segmenttree{int ls,rs,s;}nod[o];
int n,q,cnt,il,ir,opt,res[1000];
inline void pushdown(int id,int l,int r){
	if(nod[id].s==r-l+1){if(nod[id].ls) nod[nod[id].ls].s=(l+r>>1)-l+1;if(nod[id].rs) nod[nod[id].rs].s=r-(l+r>>1);}
	if(!nod[id].s){if(!nod[id].ls) nod[id].ls=++cnt;if(!nod[id].rs) nod[id].rs=++cnt;nod[nod[id].ls].s=nod[nod[id].rs].s=0;}
}
void modify(int id,int L,int R,int l,int r,int c){
	res[c]=0;
	if(L==l&&R==r){if(opt^1) res[c]=r-l+1-nod[id].s;else res[c]=-nod[id].s;nod[id].s+=res[c];return;}
	pushdown(id,L,R);
	if(r<=(L+R>>1)){if(!nod[id].ls) nod[nod[id].ls=++cnt].s=(L+R>>1)-L+1;modify(nod[id].ls,L,(L+R>>1),l,r,c+1);res[c]+=res[c+1];}
	else if(l>(L+R>>1)){if(!nod[id].rs) nod[nod[id].rs=++cnt].s=R-(L+R>>1);modify(nod[id].rs,(L+R>>1)+1,R,l,r,c+1);res[c]+=res[c+1];}
	else{
		if(!nod[id].ls) nod[nod[id].ls=++cnt].s=(L+R>>1)-L+1;modify(nod[id].ls,L,(L+R>>1),l,(L+R>>1),c+1);res[c]+=res[c+1];
		if(!nod[id].rs) nod[nod[id].rs=++cnt].s=R-(L+R>>1);modify(nod[id].rs,(L+R>>1)+1,R,(L+R>>1)+1,r,c+1);res[c]+=res[c+1];
	}
	nod[id].s+=res[c];
}
int main(){
	for(int i=cnt=1;i<o;++i) nod[i].ls=nod[i].rs=nod[i].s=0;
	read(n);read(q);nod[1].s=n;
	while(q--) read(il),read(ir),read(opt),modify(1,1,n,il,ir,1),write(nod[1].s),putchar('\n');
	return 0;
}