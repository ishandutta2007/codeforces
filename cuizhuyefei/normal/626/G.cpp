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
typedef pair<double,int> Pdi;
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
int n,t,q,p[N],l[N],sum,cur[N];double res;
/*priority_queue<Pdi>ins;
priority_queue<Pdi,vector<Pdi>,greater<Pdi> >era;*/
set<Pdi>ins,era;
inline double getcost(int i, int x){
	return 1.0*p[i]*l[i]/(l[i]+x)/(l[i]+x-1);
}
void erase(int i){
	if(cur[i]<l[i])ins.erase(Pdi(getcost(i,cur[i]+1),i));
	if(cur[i])era.erase(Pdi(getcost(i,cur[i]),i));
}
void insert(int i){
	if(cur[i]<l[i])ins.insert(Pdi(getcost(i,cur[i]+1),i));
	if(cur[i])era.insert(Pdi(getcost(i,cur[i]),i));
}
void eraseone(){
	if(era.empty())return;
	int j=(*era.begin()).se;res-=(*era.begin()).fi;
	erase(j);cur[j]--;insert(j);
}
void insertone(){
	if(ins.empty())return;
	int j=(*ins.rbegin()).se;res+=(*ins.rbegin()).fi;
	erase(j);cur[j]++;insert(j);
}
int main() {
	read(n);read(t);read(q);
	rep(i,1,n)read(p[i]);
	rep(i,1,n)read(l[i]),sum+=l[i];
	rep(i,1,n)ins.insert(Pdi(getcost(i,cur[i]+1),i));
	rep(cnt,1,min(sum,t)){
		int i=(*ins.rbegin()).se;res+=(*ins.rbegin()).fi;ins.erase(*ins.rbegin());
		cur[i]++;if(cur[i]<l[i])ins.insert(Pdi(getcost(i,cur[i]+1),i));
	}
	rep(i,1,n)if(cur[i])era.insert(Pdi(getcost(i,cur[i]),i));
	while(q--){
		int op,i;read(op);read(i);
		if(op==1){
			res-=1.0*p[i]*cur[i]/(cur[i]+l[i]);erase(i);
			sum++;l[i]++;res+=1.0*p[i]*cur[i]/(cur[i]+l[i]);
			if(t>=sum){
				cur[i]++;res+=getcost(i,cur[i]);era.insert(Pdi(getcost(i,cur[i]),i));
			}
			else{insert(i);eraseone();insertone();}
		}
		else{
			res-=1.0*p[i]*cur[i]/(cur[i]+l[i]);erase(i);
			sum--;l[i]--;res+=1.0*p[i]*cur[i]/(cur[i]+l[i]);
			if(cur[i]>l[i])res-=getcost(i,cur[i]),cur[i]--,era.insert(Pdi(getcost(i,cur[i]),i));
			else insert(i),eraseone();
			insertone();
		}
		printf("%.9lf\n",res);
	}
	return 0;
}