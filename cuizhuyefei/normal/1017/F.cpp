#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register ui i=a; i<=b; i++)
#define per(i,a,b) for (register ui i=a; i>=b; i--)
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
const int N = 33333;
ui n,mrk[N],len,prime[N];
ui A,B,C,D,S,a[N][4],b[N][4],res;
void getp(ui n){
	rep(i,2,n){
		if(!mrk[i])prime[++len]=i;
		rep(j,1,len){
			if(i*prime[j]>n)break;
			mrk[i*prime[j]]=prime[j];
			if(i%prime[j]==0)break;
		}
	}
}
ui power(ui a, ui k){
	if(k==0)return 1;
	if(k==1)return a;
	if(k==2)return a*a;
	if(k==3)return a*a*a;
}
ui getS(ui k, ui n){
	if(k==0)return n;
	if(k==1){ui a=n,b=n+1;if(a%2==0)a/=2;else b/=2;return a*b;}
	if(k==2){
		ui a=n,b=n+1,c=2*n+1;if(a%3==0)a/=3;else if(b%3==0)b/=3;else c/=3;
	//	ui my=a*b*c/2;ui A=a,B=b,C=c;
		if(a%2==0)a/=2;else if(b%2==0)b/=2;else c/=2;
	//	ui std=a*b*c;if(my!=std)printf("QAQ %u %u %u: %u %u\n",A,B,C,my,std);
		return a*b*c;
	}
	if(k==3){
		ui a=n,b=n+1;if(a%2==0)a/=2;else b/=2;return a*b*a*b;
	}
}
ui getans(ui a[4]){return a[3]*A+a[2]*B+a[1]*C+a[0]*D;}
int main() {//freopen("1.in","r",stdin);
	cin>>n>>A>>B>>C>>D;S=sqrt(n)+1;getp(S);
	rep(t,1,len){
		ui p=prime[t],xs=A*p*p*p+B*p*p+C*p+D,nn=n/p;
		while(nn>=p){nn/=p;res+=xs*nn;}
	}
	rep(i,0,3)rep(j,1,S)a[j][i]=getS(i,j)-1,b[j][i]=getS(i,n/j)-1;
//	rep(i,1,S)printf("%d : %u %u %u %u\n",i,a[i][0],a[i][1],b[i][0],b[i][1]);
	rep(t,1,len){
		ui p=prime[t];
		for(ui i=1;i<=S&&n>=p*p*i;i++){
			rep(j,0,3)b[i][j]-=power(p,j)*((i*p<=S?b[i*p][j]:a[n/(i*p)][j])-a[p-1][j]);
		}
		for(ui i=S;i>=p*p;i--){
			rep(j,0,3)a[i][j]-=power(p,j)*(a[i/p][j]-a[p-1][j]);
		}
	}
//	rep(i,1,S)printf("%d : %u %u %u %u\n",i,a[i][0],a[i][1],b[i][0],b[i][1]);
	rep(i,1,n){
		ui j=n/(n/i),x=n/i;//[i,j]
		if(j<=S)res+=(ui)(n/i)*(getans(a[j])-getans(a[i-1]));
		else {
			res+=(ui)(n/i)*(getans(b[x])-getans(b[x+1]));
		//	assert(n/(x+1)+1==i);
		//	printf("%d %d %d <%d>\n",i,j,x,S);
		}
		i=j;
	}
	cout<<res;
	return 0;
}