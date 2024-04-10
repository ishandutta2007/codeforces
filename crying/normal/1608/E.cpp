#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
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
const int MAXN=1e5+10;
int n,x,y,c,m,l[4];
int p[4];
pi X[4][MAXN],Y[4][MAXN];
bool cmp(const pi& a,const pi& b){return a.se<b.se;}
int check1(int mid){
	if(X[p[1]][mid].fr >= X[p[3]][m-mid+1].fr)return 0;
	int cnt=0;
	rep(i,1,m)if(X[p[2]][i].fr>X[p[1]][mid].fr && X[p[2]][i].fr < X[p[3]][m-mid+1].fr)cnt++;
	return cnt>=mid;
}
int check2(int mid){
	if(Y[p[1]][mid].se >= Y[p[3]][m-mid+1].se)return 0;
	int cnt=0;
	rep(i,1,m)if(Y[p[2]][i].se>Y[p[1]][mid].se && Y[p[2]][i].se < Y[p[3]][m-mid+1].se)cnt++;
	return cnt>=mid;
}
int check3(int mid){
	int cnt=0,ylim=0;
	rep(i,1,m){
		if(Y[p[2]][i].fr>X[p[1]][mid].fr){
			cnt++;
			if(cnt==mid){
				ylim=Y[p[2]][i].se;break;
			}
		}
	}
	if(cnt<mid)return 0;
	cnt=0;
	rep(i,1,m){
		if(Y[p[3]][i].fr>X[p[1]][mid].fr && Y[p[3]][i].se>ylim)cnt++;
	}
	return cnt>=mid;	
}
int check4(int mid){
	int cnt=0,ylim=0;
	rep(i,1,m){
		if(Y[p[2]][i].fr<X[p[1]][m-mid+1].fr){
			cnt++;
			if(cnt==mid){
				ylim=Y[p[2]][i].se;break;
			}
		}
	}
	if(cnt<mid)return 0;
	cnt=0;
	rep(i,1,m){
		if(Y[p[3]][i].fr<X[p[1]][m-mid+1].fr && Y[p[3]][i].se>ylim)cnt++;
	}
	return cnt>=mid;
}
int check5(int mid){
	int cnt=0,xlim=0;
	rep(i,1,m){
		if(X[p[2]][i].se>Y[p[1]][mid].se){
			cnt++;
			if(cnt==mid){
				xlim=X[p[2]][i].fr;break;
			}
		}
	}
	if(cnt<mid)return 0;
	cnt=0;
	rep(i,1,m){
		if(X[p[3]][i].se>Y[p[1]][mid].se && X[p[3]][i].fr>xlim)cnt++;
	}
	return cnt>=mid; 
}
int check6(int mid){
	int cnt=0,xlim=0;
	rep(i,1,m){
		if(X[p[2]][i].se<Y[p[1]][m-mid+1].se){
			cnt++;
			if(cnt==mid){
				xlim=X[p[2]][i].fr;break;
			}
		}
	}
	if(cnt<mid)return 0;
	cnt=0;
	rep(i,1,m){
		if(X[p[3]][i].se<Y[p[1]][m-mid+1].se && X[p[3]][i].fr>xlim)cnt++;
	}
	return cnt>=mid; 
}
int check(int mid){
	rep(a,1,3)rep(b,1,3)rep(c,1,3){
		if(a==b || a==c || b==c)continue;
		p[1]=a;p[2]=b;p[3]=c;
		if(check1(mid))return 1;
		if(check2(mid))return 1;
		if(check3(mid))return 1;
		if(check4(mid))return 1;
		if(check5(mid))return 1;
		if(check6(mid))return 1;
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	m=n/3;
	rep(i,1,n){
		scanf("%d%d%d",&x,&y,&c);
		l[c]++;
		X[c][l[c]]=mp(x,y);
		Y[c][l[c]]=mp(x,y);
	}
	rep(i,1,3)sort(X[i]+1,X[i]+1+m),sort(Y[i]+1,Y[i]+1+m,cmp);
	int L=1,R=m,ans=0;
	while(L<=R){
		int mid=(L+R)>>1;
		if(check(mid)){
			ans=mid;L=mid+1;
		}else{R=mid-1;}
	}
	printf("%d",ans*3);
	return 0;
}