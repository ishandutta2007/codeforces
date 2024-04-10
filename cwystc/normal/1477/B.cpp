#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FORD(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
typedef long long LL;
typedef pair<int,int> pa;
typedef vector<int> vec;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}

char A[1000010],B[1000010];
int n,TT,k,T[1000010],tag[1000010],l[1000010],a[1000010],r[1000010];


void build(int l,int r,int rt){
	tag[rt]=-1;
	T[rt]=0;
	if (l==r){
		T[rt]=a[l];
		return;
	}
	int m=l+r>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	T[rt]=T[rt<<1]+T[rt<<1|1];
}
void TAG(int l,int r,int rt,int t){
	tag[rt]=t;
	T[rt]=t*(r-l+1);

}
void pushdown(int l,int r,int rt){

	if (tag[rt]!=-1){
		int m=l+r>>1;
		TAG(l,m,rt<<1,tag[rt]);
		TAG(m+1,r,rt<<1|1,tag[rt]);
		tag[rt]=-1;
	}
}
int que(int l,int r,int rt,int L,int R){
	if (L<=l && r<=R){
		return T[rt];

	}
	int m=l+r>>1;
	pushdown(l,r,rt);
	int t=0;
	if (L<=m) t+=que(l,m,rt<<1,L,R);
	if (R>m) t+=que(m+1,r,rt<<1|1,L,R);
	return t;

}
void upd(int l,int r,int rt,int L,int R,int t){
	if (L<=l && r<=R){
		TAG(l,r,rt,t);
		return;
	}
	int m=l+r>>1;
	pushdown(l,r,rt);
	if (L<=m) upd(l,m,rt<<1,L,R,t);
	if (R>m) upd(m+1,r,rt<<1|1,L,R,t);
	T[rt]=T[rt<<1]+T[rt<<1|1];
}
void doit(){
	cin>>n>>k;
	scanf("%s",A+1);
	scanf("%s",B+1);
	FOR(i,1,k){
		scanf("%d%d",&l[i],&r[i]);
	}
	FOR(i,1,n) a[i]=B[i]-'0';
	build(1,n,1);
	FORD(i,k,1){
		int one=que(1,n,1,l[i],r[i]);
		int zero=r[i]-l[i]+1-one;
		if (one==zero) {puts("NO");return;}
		if (one>zero){
			upd(1,n,1,l[i],r[i],1);

		}
		else upd(1,n,1,l[i],r[i],0);


	}
	FOR(i,1,n) if (que(1,n,1,i,i)!=A[i]-'0') {puts("NO");return;}
	puts("YES");



}
int main(){
	cin>>TT;
	while (TT--) doit();
    return 0;
}