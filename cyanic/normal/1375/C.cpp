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

const int N=300005;
int l[N],r[N],a[N],n,top;

void rmain(){
	read(n);
	rep(i,1,n){
		read(a[i]);
	}
	top=0;
	rep(i,1,n){
		int t=a[i];
		while(top&&l[top]<=a[i]) {
			t=l[top--];
		}
		l[++top]=t,r[top]=a[i];
	}
	puts(top==1?"YES":"NO");
}

int main(){
	int T; read(T);
	while(T--) rmain();
	return 0;
}