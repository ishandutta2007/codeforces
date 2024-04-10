#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef double ld;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const ld eps=1e-12;
const int N=1000005,inf=1e5;
struct pt{
	int x,y;
	pt(int _x=0,int _y=0){
		x=_x,y=_y;
	}
	friend pt operator - (pt a,pt b){
		return pt(a.x-b.x,a.y-b.y);
	}
	friend ld moew(pt a){
		return sqrt(1.0*a.x*a.x+1.0*a.y*a.y);
	}
	friend ll operator * (pt a,pt b){
		return (ll)a.x*b.y-(ll)a.y*b.x;
	}
	friend bool operator < (pt a,pt b){
		return a.x==b.x?a.y<b.y:a.x<b.x;
	}
	friend bool operator == (pt a,pt b){
		return !(a<b)&&!(b<a);
	}
}p[N],s[N];
int m,n,c,x,y,v;

void build(){
	sort(p+1,p+n+1);
	rep(i,1,n){
		while(c>=2&&(p[i]-s[c-1])*(s[c]-s[c-1])>=0)c--;
		s[++c]=p[i];
	}
	int bt=c;
	per(i,n-1,2){
		while(c>=bt+1&&(p[i]-s[c-1])*(s[c]-s[c-1])>=0)c--;
		s[++c]=p[i];
	}
	s[c+1]=s[1],s[c+2]=s[1];
}

ld calc(pt a,pt b,pt c){
	ld A=moew(a-c),B=moew(b-a),C=moew(b-c);
	if(A<eps||B<eps||C<eps)return 0;
	ld CosA=(B*B+C*C-A*A)/2/B/C;
	ld SinA=sqrt(1-CosA*CosA);
	return SinA<eps?0:A/SinA;
}

int main(){
	read(m);
	rep(i,1,m){
		read(x),read(y),read(v);
		if(x-v>=0)p[++n]=pt(x-v,y);
		else{
			int vv=v-x;
			p[++n]=pt(0,max(0,y-vv));
			p[++n]=pt(0,min(inf,y+vv));
		}
		if(x+v<=inf)p[++n]=pt(x+v,y);
		else{
			int vv=v-inf+x;
			p[++n]=pt(inf,max(0,y-vv));
			p[++n]=pt(inf,min(inf,y+vv));
		}
		if(y-v>=0)p[++n]=pt(x,y-v);
		else{
			int vv=v-y;
			p[++n]=pt(max(0,x-vv),0);
			p[++n]=pt(min(inf,x+vv),0);
		}
		if(y+v<=inf)p[++n]=pt(x,y+v);
		else{
			int vv=v-inf+y;
			p[++n]=pt(max(0,x-vv),inf);
			p[++n]=pt(min(inf,x+vv),inf);
		}
	}
	build();
	ld ans=0; pt A,B,C;
	rep(i,1,c){
		ld tmp=calc(s[i],s[i+1],s[i+2]);
		if(tmp>ans){
			ans=tmp;
			A=s[i],B=s[i+1],C=s[i+2];
		}
	}
	printf("%d %d\n%d %d\n%d %d\n",A.x,A.y,B.x,B.y,C.x,C.y);
	return 0;
}