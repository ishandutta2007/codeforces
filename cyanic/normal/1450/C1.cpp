#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
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

const int N=305;
char s[N][N];
int n,c[3];

void rmain(){
	read(n);
	c[0]=c[1]=c[2]=0;
	rep(i,1,n){
		scanf("%s",s[i]+1);
		rep(j,1,n){
			if(s[i][j]=='X') c[(i+j)%3]++;
		}
	}
	int k=min_element(c,c+3)-c;
	rep(i,1,n){
		rep(j,1,n){
			if(s[i][j]=='X'){
				if((i+j)%3==k) putchar('O');
				else putchar('X');
			}
			else{
				putchar('.');
			}
		}
		puts("");
	}
}

int main(){
	int T;
	read(T);
	for(;T;T--) rmain();

	return 0;
}