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
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 666;
int n,ans[N];double E;
Vi ask(Vi a){
	E+=1.0/SZ(a)/SZ(a);assert(E<=1.4);
	string b;rep(i,0,SZ(a)-1)b+=a[i]==1?'C':(a[i]==2?'H':'O');
	printf("? ");cout<<b<<endl;fflush(stdout);
	Vi res;int l,x;read(l);rep(i,1,l){
		read(x),res.pb(x);
		rep(j,0,SZ(a)-1)ans[x+j]=a[j];
	}
	sort(ALL(res));
	return res;
}
void printans(){
	if(E+1.0/n/n<=1.4&&n==4){
		Vi a;rep(i,1,n)a.pb(ans[i]);
		assert(SZ(ask(a)));
	}
	string b;rep(i,1,n){assert(ans[i]>=1&&ans[i]<=3);b+=ans[i]==1?'C':(ans[i]==2?'H':'O');}
	printf("! ");assert(SZ(b)==n);cout<<b<<endl;fflush(stdout);
	int res;read(res);assert(res);
}
void solve4(){
	ask({1,2});ask({2,3});ask({1,3});ask({2,1});
	int sum=0;rep(i,1,n)sum+=ans[i]>0;
	if(!sum){
		ask({1,1,1});ask({2,2,2});ask({3,3,3});
		if(ans[1]&&ans[4]){printans();return;}
		if(ans[4]){
			Vi a;a.pb(3);rep(i,2,4)a.pb(ans[i]);
			assert(SZ(ask(a)));
			ans[1]=3;
		}
		else if(ans[1]){
			if(SZ(ask({3,3,3,1})))ans[4]=1;else ans[4]=2;
		}
		else{
			if(SZ(ask({3,3,2,2})))ans[1]=3,ans[2]=3,ans[3]=2,ans[4]=2;
			else ans[1]=3,ans[2]=3,ans[3]=1,ans[4]=1;
		}
		printans();return;
	}
	if(sum==4){printans();return;}
	if(sum==2){
		int p=0;rep(i,1,4)if(ans[i]){p=i;break;}
		assert(ans[p+1]);
		if(!ans[4]){
			rep(i,1,2)ask({ans[p],ans[p+1],i});
			if(!ans[p+2])ans[p+2]=3;
		}
		else{
			rep(i,1,2)ask({i,ans[p],ans[p+1]});
			if(!ans[p-1])ans[p-1]=3;
		}
	}
	sum=0;rep(i,1,n)sum+=ans[i]>0;assert(sum==3);
	//sum==3
	int p=0;rep(i,1,4)if(!ans[i])p=i;
	rep(i,1,2){
		Vi a;rep(j,1,4)a.pb(ans[j]?ans[j]:i);ask(a);
	}
	if(!ans[p])ans[p]=3;
	printans();return;
}
void solve(){
	ask({1,1});ask({1,2});ask({1,3});ask({2,2});ask({3,3});
	rep(i,1,n-1)if(ans[i]&&!ans[i+1]){
		ans[i+1]=5-ans[i];
	}
	if(!ans[1]){
		int p=1;while(p+1<=n-1&&!ans[p+1])p++;
		vector<Vi>candi;
		rep(s,2,3){
			Vi a;
			rep(i,1,n-1)a.pb(ans[i]?ans[i]:(i&1?s:5-s));
			candi.pb(a);
		}
		rep(i,0,SZ(candi)-1){
			Vi back;if(i<SZ(candi)-1)back=ask(candi[i]);
			if(i==SZ(candi)-1||SZ(back)&&back[0]==1){
				rep(j,0,SZ(candi[i])-1)ans[j+1]=candi[i][j];break;
			}
		}
	}
	if(!ans[n])ans[n]=5-ans[n-1];
	Vi a;rep(i,1,n-1)a.pb(ans[i]);a.pb(1);
	if(SZ(ask(a))){ans[n]=1;}
	/*vector<Vi>candi;
	rep(x,1,3){Vi a;rep(i,1,n-1)a.pb(ans[i]);a.pb(x);candi.pb(a);}
	rep(i,0,SZ(candi)-1)if(i==SZ(candi)-1||SZ(ask(candi[i]))){
		rep(j,0,SZ(candi[i])-1)ans[j+1]=candi[i][j];break;
	}*/
	printans();
}
int main() {
	int T;read(T);while(T--){
		read(n);rep(i,1,n)ans[i]=0;E=0;
		if(n==4)solve4();
		else solve();
	}
	return 0;
}