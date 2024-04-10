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

const int N=100005;
int c[N],p[N],t,n,cnt;
char s[N];

void GG(){
	puts("-1");
	exit(0);
}

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	rep(i,1,n){
		if(s[i]=='#'){
			s[i]=')';
			p[++cnt]=i;
		}
		if(s[i]=='(') t++;
		else t--;
	}
	//cout<<cnt<<" "<<t<<endl;
	if(t<0) GG();
	c[p[cnt]]=t;
	t=0;
	rep(i,1,n){
		if(s[i]=='(') t++;
		else t--;
		t-=c[i];
		if(t<0) GG();
	}	
	assert(t==0);
	rep(i,1,cnt){
		printf("%d\n",1+c[p[i]]);
	}
	return 0;
}