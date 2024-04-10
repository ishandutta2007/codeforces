#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define ref(i,x,y)for(int i=x;i<=y;++i)
#define def(i,x,y)for(int i=x;i>=y;--i)
int read(){char c=getchar();int d=0,f=1;for(;c<'0'||c>'9';c=getchar())if(c=='-')f=-1;for(;c>='0'&&c<='9';d=d*10+c-48,c=getchar());return d*f;}
char Read(){char c=getchar();while(c<'0'||c>'9')c=getchar();return c;}
typedef pair<int,int>PII;
typedef long long LL;
const int N=1000000;
int n,s[N+1],t[1<<25]; char st[N+1];
int main(){
	scanf("%d",&n);
	ref(i,1,n){
		scanf("%s",st+1);int l=strlen(st+1);
		ref(j,1,l) s[i]^=(1<<st[j]-'a');
	}
	int half=(1<<25);
	LL ans=0;
	ref(i,1,n)if(s[i]<half)t[s[i]]++;
	ref(i,0,half-1)if(t[i]){
		ans+=1LL*t[i]*(t[i]-1)/2;
		ref(j,0,25-1)if(i>>j&1)ans+=1LL*t[i]*t[i^(1<<j)];
	}
	ref(i,1,n)if(s[i]>=half)ans+=t[s[i]-half];
	ref(i,0,half-1)t[i]=0;
	ref(i,1,n)if(s[i]>=half)t[s[i]-half]++;
	ref(i,0,half-1)if(t[i]){
		ans+=1LL*t[i]*(t[i]-1)/2;
		ref(j,0,25-1)if(i>>j&1)ans+=1LL*t[i]*t[i^(1<<j)];
	}
	cout<<ans<<endl;
}