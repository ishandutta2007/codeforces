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

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}



int main(){

	int T;

	read(T);

	while(T--){
		int n,a,b,p=0;

		read(n),read(a);
		rep(i,2,n){
			read(b);
			if(abs(a-b)>=2) p=i-1;
			a=b;
		}

		puts(p?"YES":"NO");
		if(p) printf("%d %d\n",p,p+1);
	}

    return 0;
}