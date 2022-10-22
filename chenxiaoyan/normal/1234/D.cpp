/*




D P 




 l l
*/
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	x=0;char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
}
inline int ppc(int x){return __builtin_popcount(x);}
const int N=100000,LET=26;
int n,qu;
char a[N+5];
struct segtree{
	struct node{int l,r,hav;}nd[N<<2];
	#define l(p) nd[p].l
	#define r(p) nd[p].r
	#define hav(p) nd[p].hav
	void sprup(int p){hav(p)=hav(p<<1)|hav(p<<1|1);}
	void bld(int l=1,int r=n,int p=1){
		l(p)=l;r(p)=r;
		if(l==r){hav(p)=1<<a[l]-'a';return;}
		int mid=l+r>>1;
		bld(l,mid,p<<1);bld(mid+1,r,p<<1|1);
		sprup(p);
	}
	void init(){bld();}
	void chg(int x,char v,int p=1){
		if(l(p)==r(p)){hav(p)=1<<v-'a';return;}
		int mid=l(p)+r(p)>>1;
		chg(x,v,p<<1|(x>mid));
		sprup(p);
	}
	int cnt(int l,int r,int p=1){
		if(l<=l(p)&&r>=r(p))return hav(p);
		int mid=l(p)+r(p)>>1,res=0;
		if(l<=mid)res|=cnt(l,r,p<<1);
		if(r>mid)res|=cnt(l,r,p<<1|1);
		return res;
	}
}segt;
int main(){
//	freopen("C:\\Users\\chenx\\OneDrive\\\\data.in","r",stdin);freopen("C:\\Users\\chenx\\OneDrive\\\\ycx.out","w",stdout);
	cin>>a+1>>qu;
	n=strlen(a+1);
	segt.init();
	while(qu--){
		int tp,x;
		read(tp);read(x);
		if(tp==1){
			char y;
			scanf(" %c",&y);
			segt.chg(x,y);
		}
		else{
			int y;
			read(y);
			cout<<ppc(segt.cnt(x,y))<<"\n";
		}
	}
	return 0;
}