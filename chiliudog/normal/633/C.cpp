#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long int64;
#define mk(a,b) make_pair(a,b)
#define w1 first
#define w2 second
typedef pair<int,int> pin;
const int maxn=10005;
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}
char s[10005];
char s1[maxn];
int n,m;
map<int64,int> zball[maxn];
string res[100005];
const int seed=31;
const int64 mod=1000000000+9;
int64 hash[10005],pw[10005];
bool flag[10005];int trans[10005],num[10005];
inline int gethash(int x,int y){
	return (hash[y]-hash[x-1]*pw[y-x+1]%mod+mod)%mod;
}
int main(){
    read(n);
    scanf("%s",s+1);
    reverse(s+1,s+1+n);
    pw[0]=1;
    rep(i,1,n)pw[i]=pw[i-1]*seed%mod;
    read(m);
    rep(k,1,m){
		scanf("%s",s1+1);
		int len=strlen(s1+1);
		rep(i,1,len){
			res[k]=res[k]+s1[i];
			if(s1[i]>='A'&&s1[i]<='Z')s1[i]+='a'-'A';
		}
		int64 now=0;  
		rep(i,1,len){
			now=(now*seed+(s1[i]-'a'))%mod;
		}
		zball[len][now]=k;
    }
    int64 now=0;
    rep(i,1,n){
    	now=(now*seed+(s[i]-'a'))%mod;
    	hash[i]=now;
    }
    flag[0]=1;
    rep(i,1,n){
    	int p=max(0,i-1000);
    	rep(j,p,i-1){
    		if(flag[j]&&zball[i-j].count(gethash(j+1,i))){
    			flag[i]=1;trans[i]=j;num[i]=zball[i-j][gethash(j+1,i)];break;
    		}
    	}
    }
    int i=n;
    while(i){
    	int last=trans[i];
    	printf("%s",res[num[i]].c_str());
    	if(last!=0)putchar(' ');
    	i=last;
    }
    return 0;
}