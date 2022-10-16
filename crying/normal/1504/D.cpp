#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=110;
int a,n,xa,ya,xb,yb,f1,f2;
int c1,c2,c3,c;
int Next(int& i,int& j,int type){
	if(j+2<=n){j+=2;return 1;}
	if(i+1<=n){
		i++;
		if(type==1){
			if(i&1)j=1;
			else j=2;
		}else{
			if(i&1)j=2;
			else j=1;
		}
		return 1;
	}
	return -1;
}
int main(){
	cin>>n;
	xa=ya=xb=1;yb=2;f1=f2=1;
	rep(i,1,n*n){
		cin>>a;
		if(i==1){
			if(a==1)c1=2,c2=3;
			else if(a==2)c1=1,c2=3;
			else c1=1,c2=2;
			c3=a;
		}
		if(a!=c1){
			if(f1){
				//
				cout<<c1<<' '<<xa<<' '<<ya<<endl;
				if(Next(xa,ya,1)==-1)f1=0; 
			}else{
				//
				if(a!=c2)c=c2;
				else c=c3;
				cout<<c<<' '<<xb<<' '<<yb<<endl;
				Next(xb,yb,2);
			}
		}else{
			if(f2){
				//
				cout<<c2<<' '<<xb<<' '<<yb<<endl;
				if(Next(xb,yb,2)==-1)f2=0; 
			}else{
				//
				if(a!=c1)c=c1;
				else c=c3;
				cout<<c<<' '<<xa<<' '<<ya<<endl; 
				Next(xa,ya,1);
			}
		}
	}
	return 0;
}