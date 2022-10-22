#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int,int> Pii;
#define reg register
#define mp make_pair
#define pb push_back
#define Mod1(x) ((x>=P)&&(x-=P))
#define Mod2(x) ((x<0)&&(x+=P))
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
template <class T> inline void cmin(T &a,T b){ ((a>b)&&(a=b)); }
template <class T> inline void cmax(T &a,T b){ ((a<b)&&(a=b)); }

char IO;
template <class T=int> T rd(){
	T s=0; int f=0;
	while(!isdigit(IO=getchar())) f|=IO=='-';
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=1010,INF=1e9+10;

int n;
int F[N];
int stk[N],top;
int X[N],Y[N],HX[N],HY[N],CX,CY;
vector <int> VX[N],VY[N];

int cnt;
int Find2(int x){ while(F[x]!=x) x=F[x]; return x; }
void Uni2(int x,int y) {
	x=Find2(x),y=Find2(y);
	if(x!=y) F[x]=y,cnt--,stk[++top]=x;
}

int Find(int x){ return F[x]==x?x:F[x]=Find(F[x]); }
void Uni(int x,int y){
	x=Find(x),y=Find(y);
	if(x!=y) F[x]=y,cnt--;
}
void Back(){ while(top) F[stk[top]]=stk[top],top--,cnt++; }

int prex[N][N],nxtx[N][N];
int prey[N][N],nxty[N][N];

int Check(int mid){
	rep(i,1,cnt=n+1) F[i]=i;
	rep(i,1,CX) rep(j,1,VX[i].size()-1) if(HY[Y[VX[i][j]]]-HY[Y[VX[i][j-1]]]<=mid) Uni(VX[i][j],VX[i][j-1]);
	rep(i,1,CY) rep(j,1,VY[i].size()-1) if(HX[X[VY[i][j]]]-HX[X[VY[i][j-1]]]<=mid) Uni(VY[i][j],VY[i][j-1]);
	rep(i,1,n+1) Find(i);
	
	top=0;
	rep(i,1,CX) rep(j,1,VX[i].size()-1) {
		int x=VX[i][j-1],y=VX[i][j];
		if(HY[Y[y]]-HY[Y[x]]<=mid*2ll) {
			Uni2(n+1,x),Uni2(n+1,y);
			if(cnt==1) return 1;
			Back();
		}
	}

	rep(i,1,CY) rep(j,1,VY[i].size()-1) {
		int x=VY[i][j-1],y=VY[i][j];
		if(HX[X[y]]-HX[X[x]]<=mid*2ll) {
			Uni2(n+1,x),Uni2(n+1,y);
			if(cnt==1) return 1;
			Back();
		}
	}

	rep(i,1,CX) {
		rep(j,1,CY) {
			if(prex[i][j]==prey[i][j]) continue;
			//cout<<"$"<<i<<' '<<j<<endl;
			for(int v:{prex[i][j],nxtx[i][j],prey[i][j],nxty[i][j]}) {
				if(v && abs(HX[i]-HX[X[v]])<=mid && abs(HY[j]-HY[Y[v]])<=mid) {
					//cout<<"uni "<<v<<endl;
					Uni2(v,n+1);
				}
			}
			if(cnt==1) return 1;
			Back();
		}
	}
	return 0;
}

int main(){
	n=rd();
	rep(i,1,n) HX[i]=X[i]=rd(),HY[i]=Y[i]=rd();
	sort(HX+1,HX+n+1),CX=unique(HX+1,HX+n+1)-HX-1;
	sort(HY+1,HY+n+1),CY=unique(HY+1,HY+n+1)-HY-1;
	rep(i,1,n) {
		X[i]=lower_bound(HX+1,HX+CX+1,X[i])-HX;
		Y[i]=lower_bound(HY+1,HY+CY+1,Y[i])-HY;
		//cout<<"$"<<X[i]<<' '<<Y[i]<<endl;
		VX[X[i]].pb(i),VY[Y[i]].pb(i);
		prex[X[i]][Y[i]]=i,nxtx[X[i]-1][Y[i]]=i;
		prey[X[i]][Y[i]]=i,nxty[X[i]][Y[i]-1]=i;
	}
	rep(i,1,CX) rep(j,1,CY) {
		prex[i][j]=prex[i][j]?prex[i][j]:prex[i-1][j];
		prey[i][j]=prey[i][j]?prey[i][j]:prey[i][j-1];
	}
	drep(i,CX,1) drep(j,CY,1) {
		nxtx[i][j]=nxtx[i][j]?nxtx[i][j]:nxtx[i+1][j];
		nxty[i][j]=nxty[i][j]?nxty[i][j]:nxty[i][j+1];
	}
	//cout<<prex[2][2]<<' '<<nxtx[2][2]<<endl;
	//cout<<prey[2][2]<<' '<<nxty[2][2]<<endl;
	rep(i,1,CX) sort(VX[i].begin(),VX[i].end(),[&](int x,int y){ return Y[x]<Y[y]; });
	rep(i,1,CY) sort(VY[i].begin(),VY[i].end(),[&](int x,int y){ return X[x]<X[y]; });
	//cout<<Check(100)<<endl;
	int l=0,r=2e9,res=-1;
	while(l<=r) {
		int mid=(0ll+l+r)>>1;
		if(Check(mid)) r=mid-1,res=mid;
		else l=mid+1;
	}
	printf("%d\n",res);
}