#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 266666;
struct node{string s,t;};vector<node>ans;
string a[N],b[N];int n,m,zuo,tot;
set<int>A,B;
string a_to_b[N],b_to_a[N];int sz1,sz2;
inline int getnum(string s){
	if(s[0]=='0')return 0;
	int x=0;rep(i,0,SZ(s)-1){
		if(isdigit(s[i]))x=10*x+s[i]-'0';else return 0;
	}
	return x>=1&&x<=tot?x:0;
}
set<string>used;
int main() {
	int T;read(T);while(T--){
		char S[10];scanf("%s",S);string s=S;used.insert(s);
		int x;read(x);
		if(x)a[++n]=s;else b[++m]=s;
	}
	int zuo=n;tot=n+m;
	//a:1..n b:n+1..n+m
	rep(i,1,n)A.insert(i);
	rep(i,n+1,n+m)B.insert(i);
	int tmp=0;rep(i,1,n){
		int t=getnum(a[i]);
		if(t>=1&&t<=zuo)A.erase(t);
		else if(t>zuo)a_to_b[++sz1]=a[i],B.erase(t);
		else a[++tmp]=a[i];
	}
	n=tmp;
	tmp=0;rep(i,1,m){
		int t=getnum(b[i]);//cerr<<t<<' '<<b[i]<<endl;
		if(t>=1&&t<=zuo)b_to_a[++sz2]=b[i],A.erase(t);
		else if(t>zuo)B.erase(t);
		else b[++tmp]=b[i];
	}
	m=tmp;
//	cerr<<n<<' '<<m<<' '<<sz1<<' '<<sz2<<endl;
	if(!SZ(A)&&!SZ(B)&&sz1){
		B.insert(getnum(a_to_b[sz1]));
		string s;rep(i,1,6)s+=(R()%26)+'a';
		while(used.count(s)){s="";rep(i,1,6)s+=(R()%26)+'a';}
		ans.pb((node){a_to_b[sz1--],s});a[++n]=s;
	}
	while(sz1+sz2){
	//	cerr<<n<<' '<<m<<' '<<sz1<<' '<<sz2<<endl;
		if(sz1&&!A.empty()){
			B.insert(getnum(a_to_b[sz1]));
			ans.pb((node){a_to_b[sz1--],to_string(*A.begin())});
			A.erase(A.begin());
		}
		else{
			A.insert(getnum(b_to_a[sz2]));
			ans.pb((node){b_to_a[sz2--],to_string(*B.begin())});
			B.erase(B.begin());
		}
	}
	while(n)ans.pb((node){a[n--],to_string(*A.begin())}),A.erase(A.begin());
	while(m)ans.pb((node){b[m--],to_string(*B.begin())}),B.erase(B.begin());
	printf("%d\n",SZ(ans));
	rep(i,0,SZ(ans)-1){
		printf("move ");
		string s=ans[i].s;rep(j,0,SZ(s)-1)putchar(s[j]);putchar(' ');
		s=ans[i].t;rep(j,0,SZ(s)-1)putchar(s[j]);puts("");
	}
	return 0;
}