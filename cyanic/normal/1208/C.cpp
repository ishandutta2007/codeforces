#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
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

const int mat[4][4]={
	{8,9,1,13},
	{3,12,7,5},
	{0,2,4,11},
	{6,10,15,14}
};
const int N=1005;
int ans[N][N],n;

int main(){
	read(n);

	int cur=0;
	REP(i,n/2)REP(j,n/2){
		ans[i][j]=(cur++)*4;
		ans[i+n/2][j]=ans[i][j]+1;
		ans[i][j+n/2]=ans[i][j]+2;
		ans[i+n/2][j+n/2]=ans[i][j]+3;
	}

	REP(i,n){
		REP(j,n)printf("%d ",ans[i][j]);
		puts("");
	}

	
	return 0;
}