#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 3030, mo1 = 1e9+7, mo2 = 1e9+9, b1 = 2339, b2 = 10007;
const ll MO1 = 1LL*mo1*mo1, MO2 = 1LL*mo2*mo2;
int n,l[N],r[N],mi1[N],mi2[N];
char s[3030][3030],t[3030][3030];
Pii S[3030][3030],T[3030][3030];
void gethash(Pii *v, char *s, int n){
	rep(i,1,n){
		v[i]=Pii((1LL*v[i-1].fi*b1+s[i])%mo1,(1LL*v[i-1].se*b2+s[i])%mo2);
	}
}
pair<Pii,Pii> getval(int i, int l, int r){
	Pii x=Pii((S[i][r].fi-1LL*S[i][l-1].fi*mi1[r-l+1]+MO1)%mo1,(S[i][r].se-1LL*S[i][l-1].se*mi2[r-l+1]+MO2)%mo2);//WA
	Pii y=Pii((T[i][r].fi-1LL*T[i][l-1].fi*mi1[r-l+1]+MO1)%mo1,(T[i][r].se-1LL*T[i][l-1].se*mi2[r-l+1]+MO2)%mo2);
	return pair<Pii,Pii>(x,y);
}
Pii getV(int i, int l, int r){
	return Pii((S[i][r].fi-1LL*S[i][l-1].fi*mi1[r-l+1]+MO1)%mo1,(S[i][r].se-1LL*S[i][l-1].se*mi2[r-l+1]+MO2)%mo2);
}
int main() {
	read(n);rep(i,1,n)scanf("%s",s[i]+1);
	rep(i,1,n)scanf("%s",t[i]+1);
	rep(i,1,n)gethash(S[i],s[i],strlen(s[i]+1)),gethash(T[i],t[i],strlen(t[i]+1));
	mi1[0]=1;rep(i,1,3000)mi1[i]=1LL*mi1[i-1]*b1%mo1;
	mi2[0]=1;rep(i,1,3000)mi2[i]=1LL*mi2[i-1]*b2%mo2;
	int fi=0,l1=0,l2=0;
	rep(i,1,n){
		int len=strlen(s[i]+1);l[i]=n+1;r[i]=0;
		rep(j,1,len)if(s[i][j]!=t[i][j])r[i]=j;
		per(j,len,1)if(s[i][j]!=t[i][j])l[i]=j;
		if(l[i]>r[i])continue;
		if(!fi)fi=i,l1=l[i]-1,l2=len-r[i];
		else{
			while(l1&&(l[i]-l1<1||getval(i,l[i]-l1,r[i])!=getval(fi,l[fi]-l1,r[fi])))l1--;
			while(l2&&(r[i]+l2>len||getval(i,l[i],r[i]+l2)!=getval(fi,l[fi],r[fi]+l2)))l2--;
		}
	}
	int L=l[fi]-l1,R=r[fi]+l2;//printf("<%d %d %d>\n",fi,L,R);
	rep(i,1,n)if(i!=fi){
		int len=strlen(s[i]+1);Pii Q=getV(fi,L,R);//WA
		rep(j,1,len-(R-L))if(getV(i,j,j+R-L)==Q){
			rep(k,0,R-L)s[i][j+k]=t[fi][L+k];
			break;
		}
		rep(j,1,len)if(s[i][j]!=t[i][j]){puts("NO");return 0;}
	}
	puts("YES");
	rep(i,L,R)printf("%c",s[fi][i]);puts("");
	rep(i,L,R)printf("%c",t[fi][i]);puts("");
	return 0;
}