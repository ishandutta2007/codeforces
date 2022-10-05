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

const int N=2000005;
int num[N],c0,c1,c01,c10;
int s,t,len;
vi ans;

void push(char c,int x){
	while(x--) putchar(c);
}

int main(){
	read(c0),read(c1);
	read(c01),read(c10);

	if(abs(c01-c10)>=2){
		puts("-1");
		return 0;
	}

	if(c01>c10){
		s=0,t=1;
		len=c01*2;
	}
	else if(c10>c01){
		s=1,t=0;
		len=c10*2;
	}
	else{
		if(c0>c1||c0>=c01+1) s=0,t=0;
		else s=1,t=1;
		len=c01*2+1;
	}

	int a0=0,a1=0;
	rep(i,1,len){
		if((i%2)^s^1) a1++;
		else a0++;
	}

	if(c0<a0||c1<a1){
		puts("-1");
		return 0;
	}

	int ex0=c0-a0,ex1=c1-a1;

	rep(i,1,len){
		if((i%2)^s^1){
			push('7',1+(len-i<=1?ex1:0));
		}
		else{
			push('4',1+ex0),ex0=0;
		}
	}

	return 0;
}