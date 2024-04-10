#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef double ld;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=100005;
int a[N],n,m,mn;

int main(){
	read(n),read(m);
	a[1]=0;
	rep(i,1,m){
		if(i&1) a[i+1]=a[i]+i;
		else a[i+1]=a[i]-i;
	}
	rep(i,m+2,n){
		if(a[i-2]<a[i-1]){
			a[i]=a[i-1]+1;
		}
		else{
			a[i]=a[i-1]-1;
		}
	}
	rep(i,1,n){
		mn=min(mn,a[i]);
	}
	rep(i,1,n){
		printf("%d%c",a[i]-mn+1," \n"[i==n]);
	}
	return 0;
}