#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
const int N = 66, LIM = 1e4;
int n,a[6][N],xx,yy;
string R,C,M,ans;
string mul(string a, int k){
	string b;rep(i,1,k)b+=a;assert(SZ(b)<=LIM);
	return b;
}
inline void operate(char c){
	int x=1,y=1;
	if(xx>=1&&xx<=2&&yy>=1&&yy<=2*n+1&&!a[xx][yy])x=xx,y=yy;
	else{rep(i,1,2)rep(j,1,2*n+1)if(a[i][j]==0){x=i,y=j;break;}}
	xx=x;yy=y;
	assert(!a[x][y]);
	if(c=='u'){assert(x==2);swap(a[x][y],a[x-1][y]);xx--;}
	if(c=='d'){assert(x==1);swap(a[x][y],a[x+1][y]);xx++;}
	if(c=='r'){assert(y<2*n+1);swap(a[x][y],a[x][y+1]);yy++;}
	if(c=='l'){assert(y>1);swap(a[x][y],a[x][y-1]);yy--;}
	assert(c!='C');
	if(c=='R'){for(char x:R)operate(x);}
	if(c=='M'){for(char x:M)operate(x);}
}
void choose(int x){
	while(a[1][n+1]!=x){
		C+="R";for(char c:R)operate(c);//"R"
	}
	C+="M";for(char c:M)operate(c);//"M"
}
int main() {
	int T;read(T);while(T--){
		read(n);R=C=M=ans="";
		rep(i,1,2)rep(j,1,2*n+1)a[i][j]=0;
		int num=0;rep(j,1,2*n+1)a[1][j]=++num;
		per(j,2*n+1,1)if(j!=n+1)a[2][j]=++num;
		R+=mul("r",n);R+="u";R+=mul("l",2*n);R+="d";R+=mul("r",n);
		for(char c:R)operate(c);
		assert(a[2][n+1]==0&&a[1][2]==1&&a[1][3]==2);
		
		rep(i,1,2)rep(j,1,2*n+1)a[i][j]=0;
		num=0;rep(j,1,2*n+1)a[1][j]=++num;
		per(j,2*n+1,1)if(j!=n+1)a[2][j]=++num;
		M="u"+mul("r",n)+"d"+mul("l",n);
		for(char c:M)operate(c);
		assert(a[2][n+1]==0);
		
		rep(i,1,2)rep(j,1,2*n+1)a[i][j]=0;
		num=0;rep(j,n,2*n+1)a[1][j]=++num;
		per(j,2*n+1,1)if(j!=n+1)a[2][j]=++num;
		rep(j,1,n-1)a[1][j]=++num;
		choose(1);choose(2*n+2);choose(2*n+3);choose(2*n+2);choose(2*n+3);choose(1);
		while(a[1][n+1]!=3){
			C+="R";for(char c:R)operate(c);
		}
		assert(SZ(C)<=LIM);
		assert(a[2][n+1]==0&&a[1][n+1]==3&&a[1][n]==2&&a[1][n+2]==1&&a[2][n+2]==2*n+2&&a[2][n]==2*n+3);
	//	fprintf(stderr,"%d %d %d\n",SZ(R),SZ(M),SZ(C));
		
		
		rep(i,1,2)rep(j,1,2*n+1){
			string b;cin>>b;a[i][j]=0;
			if(b[0]!='E'){for(auto x:b)a[i][j]=10*a[i][j]+x-'0';}
			if(a[i][j]>=2*n+2)a[i][j]=4*n+1+2*n+2-a[i][j];//permutation
		}
	//	rep(i,1,2){rep(j,1,2*n+1)printf("%d ",a[i][j]);puts("");}
		static int s[N];int sz=0,re=0;
		rep(j,1,2*n+1)if(a[1][j])s[++sz]=a[1][j];
		per(j,2*n+1,1)if(a[2][j])s[++sz]=a[2][j];
		rep(i,1,sz)rep(j,1,i-1)re^=s[j]>s[i];
		if(re){puts("SURGERY FAILED");continue;}
		
		rep(i,1,2)rep(j,1,2*n+1)if(!a[i][j]){
			ans+=mul("r",2*n+1-j);rep(k,1,2*n+1-j)operate('r');
			if(i==1){ans+='d';operate('d');}
			break;
		}
		ans+=mul("l",n);rep(k,1,n)operate('l');
		assert(a[2][n+1]==0);
		
		rep(i,2,4*n+1){
		//	fprintf(stderr,"cur %d\n",i);
			while(a[1][n+1]!=i){ans+="R";for(char c:R)operate(c);}
			int dis=0;
			per(j,n,1)if(a[1][j]==i-1)dis=n+1-j;
			rep(j,1,n)if(a[2][j]==i-1)dis=n+j;
			rep(j,n+2,2*n+1)if(a[2][j]==i-1)dis=n+n+j-(n+1);
			rep(j,n+2,2*n+1)if(a[1][j]==i-1)dis=3*n+2*n+1-j+1;
			dis--;
			assert(dis>=0);
			assert(a[1][n+1]==i);
			
			rep(j,1,dis)if(a[1][n+2]!=1){
				assert(a[1][n+1]==i);
				ans+="CR";for(char c:C)operate(c);
				assert(a[1][n]==i);
				for(char c:R)operate(c);
				assert(a[1][n+1]==i);
			}
			else{
				ans+="RC";for(char c:R)operate(c);for(char c:C)operate(c);
				assert(a[1][n+1]==i);
			}
			assert(a[1][n]==i-1);
		//	rep(i,1,2){rep(j,1,2*n+1)printf("%d ",a[i][j]);puts("");}puts("");
		}
		while(a[1][1]!=1){ans+="R";for(char c:R)operate(c);}
		ans+=mul("r",n);rep(i,1,n)operate('r');
	//	rep(i,1,2){rep(j,1,2*n+1)printf("%d ",a[i][j]);puts("");}
		assert(a[2][2*n+1]==0);
		rep(i,1,2*n+1)assert(a[1][i]==i);
		per(i,2*n,1)assert(a[2][i]==2*n+1+2*n+1-i);
		puts("SURGERY COMPLETE");
		cout<<ans<<endl;
		cout<<"R ";cout<<R<<endl;
		cout<<"C ";cout<<C<<endl;
		cout<<"M ";cout<<M<<endl;
		puts("DONE");
	}
	return 0;
}