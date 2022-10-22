#include<bits/stdc++.h>
using namespace std;

#define reg register
typedef long long ll;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)

char IO;
int rd(){
	int s=0,f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=2e5+10;

int n;
char s[N],t[N];
int cnt[2];
int ans;
int p[2][N];



int main(){
	n=rd();
	scanf("%s%s",s+1,t+1);
	rep(i,1,n) {
		cnt[s[i]-'a']++,cnt[t[i]-'a']++;
		if(s[i]!=t[i]) {
			if(s[i]=='a') p[0][++p[0][0]]=i;
			else p[1][++p[1][0]]=i;
		}
	}
	if((cnt[0]&1)||(cnt[1]&1)) return puts("-1"),0;
	if(p[0][0]>p[1][0]) swap(p[0],p[1]);
	int t=(p[0][0]&1)&(p[1][0]&1);
	//cout<<p[0][0]<<' '<<p[1][0]<<endl;
	printf("%d\n",(p[0][0]+p[1][0])/2+t);
	while(t--){
		int x=p[1][p[1][0]--];
		p[0][++p[0][0]]=x;
		printf("%d %d\n",x,x);
	}
	rep(i,1,p[0][0]/2) printf("%d %d\n",p[0][i*2-1],p[0][i*2]);
	rep(i,1,p[1][0]/2) printf("%d %d\n",p[1][i*2-1],p[1][i*2]);
}