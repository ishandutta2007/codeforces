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

const int N=605;
const ld eps=1e-6;
namespace{
	struct pt{
		ld x,y;
		pt(ld _x=0,ld _y=0):x(_x),y(_y){}		
	} p[N],v[N];
	pt operator + (pt a,pt b){
		return pt(a.x+b.x,a.y+b.y);
	}
	pt operator - (pt a,pt b){
		return pt(a.x-b.x,a.y-b.y);
	}
	ld operator * (pt a,pt b){
		return a.x*b.y-a.y*b.x;
	}
	ld len(pt a){
		return sqrt(a.x*a.x+a.y*a.y);
	}
	ld dis(int k,pt c){
		return fabs((c-p[k])*v[k]/len(v[k]));
	}
}
pt o[N][N],A,B; ld r[N][N],R=1e99;
int f[N][N],n;

int main(){
	read(n);
	rep(i,1,n){
		read(p[i].x),read(p[i].y);
		p[i+n]=p[i];
	}
	p[n+n+1]=p[1];
	rep(i,1,n*2) v[i]=p[i+1]-p[i];
	rep(i,1,n){
		f[i][i]=i;
		o[i][i]=p[i];
		rep(j,i+1,i+n-1){
			if(v[i]*v[j]<eps) break;
			f[i][j]=f[i][j-1];
			while(f[i][j]<j&&dis(i,p[f[i][j]+1])<dis(j,p[f[i][j]+1]))
				f[i][j]++;
			pt L=p[f[i][j]],R=p[f[i][j]+1],M;
			REP(T,50){
				M=pt((L.x+R.x)*0.5,(L.y+R.y)*0.5);
				if(dis(i,M)<dis(j,M))L=M;
				else R=M;
			}
			o[i][j]=M;
			r[i][j]=max(dis(i,o[i][j]),dis(j,o[i][j]));
		}
	}
	rep(i,1,n){
		if(f[i][i+n-1]&&r[i][i+n-1]<R)
			R=r[i][i+n-1],A=B=o[i][i+n-1];
		rep(j,i,i+n-2)
			if(f[i][j]&&f[j+1][i+n-1])
				if(max(r[i][j],r[j+1][i+n-1])<R){
					R=max(r[i][j],r[j+1][i+n-1]);
					A=o[i][j],B=o[j+1][i+n-1];
				}
	}
	printf("%.10lf\n",R);
	printf("%.10lf %.10lf\n",A.x,A.y);
	printf("%.10lf %.10lf\n",B.x,B.y);
	return 0;
}