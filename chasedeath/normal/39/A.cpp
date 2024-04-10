#include<bits/stdc++.h>
using namespace std;

#define reg register
typedef long long ll;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)


//#pragma GCC optimize(2)


char IO;
int rd(){
	int s=0,f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=1e5+10,P=998244353;

int n,x;
char s[N];
struct Node{
	int x,k;
	bool operator < (const Node __) const{
		return x<__.x;
	}
}A[N];
int cnt;



int main(){
	x=rd();
	scanf("%s",s+1);
	n=strlen(s+1);
	int k=0;
	rep(i,1,n) {
		//if(s[i]=='+'){
			//k=0;
			//continue;
		//}
		//if(s[i]=='-'){
			//k=1;
			//continue;
		//}
		int x=0;
		//cout<<i<<endl;
		if(isdigit(s[i])) {
			int j=i;
			while(isdigit(s[j])) {
				x=x*10+(s[j]-'0');
				j++;
			}
			i=(j+=3);
			A[++cnt]=(Node){(k?-x:x),(s[i]=='a')};
			k=(s[++i]=='-');
		} else {
			i+=2;
			x=1;
			A[++cnt]=(Node){(k?-x:x),(s[i]=='a')};
			k=(s[++i]=='-');
		}
	}
	//rep(i,1,cnt) cout<<A[i].x<<' '<<A[i].k<<endl;
	sort(A+1,A+cnt+1);
	ll ans=0;
	rep(i,1,cnt) {
		if(A[i].k) x++;
		ans+=1ll*A[i].x*x;
		if(!A[i].k) x++;
	}
	printf("%I64d\n",ans);
}