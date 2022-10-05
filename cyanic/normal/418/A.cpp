#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

int n,K;

int main(){
	read(n),read(K);
	if(K>(n-1)/2){
		puts("-1");
		return 0;
	}
	printf("%d\n",n*K);
	rep(i,1,n){
		rep(j,1,K){
			int p=(i+j)%n;
			if(p==0) p=n;
			printf("%d %d\n",i,p);
		}
	}

	return 0;
}