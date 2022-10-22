#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cassert>
#include<cstring>
#include<map>
using namespace std;

#define reg register
typedef long long ll;
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)

/*char IO;
int rd(){
	int s=0,f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}*/

const int N=5011,INF=1e9+10;


int n,m;

char s[N];
map <string,int> M;
string varname[N],vara[N],varb[N];
int opt[N];
int t0[N],t1[N];
char mi[N],ma[N];



int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	rep(i,1,n) {
		cin>>varname[i];
		M[varname[i]]=i;
		cin>>s;
		cin>>vara[i];
		if(!isdigit(vara[i][0])){
			cin>>s;
			if(s[0]=='X') opt[i]=0;
			else if(s[0]=='O') opt[i]=1;
			else opt[i]=2;
			cin>>varb[i];
		}
	}
	rep(i,0,m-1) {
		int res0=0,res1=0;
		rep(j,1,n) {
			if(isdigit(vara[j][0])) t0[j]=t1[j]=vara[j][i]^'0';
			else {
				int x0,x1,y0,y1;
				if(isalpha(vara[j][0])){
					int v=M[vara[j]];
					x0=t0[v],x1=t1[v];
	 			}  else x0=0,x1=1;
				if(isalpha(varb[j][0])) {
					int v=M[varb[j]];
					y0=t0[v],y1=t1[v];
				} else y0=0,y1=1;
				if(opt[j]==0) t0[j]=(x0^y0),t1[j]=(x1^y1);
				if(opt[j]==1) t0[j]=(x0|y0),t1[j]=(x1|y1);
				if(opt[j]==2) t0[j]=(x0&y0),t1[j]=(x1&y1);
			}
			res0+=t0[j];
			res1+=t1[j];
		}
		//cout<<i<<' '<<res0<<' '<<res1<<endl;
		ma[i]=(res1>res0)^'0';
		mi[i]=(res1<res0)^'0';
	}
	ma[m]=mi[m]='\0';
	puts(mi),puts(ma);
}