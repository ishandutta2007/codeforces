#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
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

const int N=1000005;
priority_queue<int,vi,greater<int> > Q;
int op[N],x[N],ans[N],n;
char st[5];

void GG(){
	puts("NO");
	exit(0);
}

int main(){
	read(n);
	rep(i,1,n*2){
		scanf("%s",st+1);
		if(st[1]=='+'){
			op[i]=1;
		}
		else{
			op[i]=2;
			read(x[i]);
		}
	}
	int cur=n;
	per(i,n*2,1){
		if(op[i]==1){
			if(Q.empty()) GG();
			ans[cur--]=Q.top();
			Q.pop();
		}
		else{
			Q.push(x[i]);
		}
	}
	cur=1;
	rep(i,1,n*2){
		if(op[i]==1){
			Q.push(ans[cur++]);
		}
		else{
			if(Q.empty()) GG();
			if(Q.top()!=x[i]) GG();
			Q.pop();
		}
	}
	puts("YES");
	rep(i,1,n){
		printf("%d%c",ans[i]," \n"[i==n]);
	}
	return 0;
}