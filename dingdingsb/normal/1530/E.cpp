#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
typedef long long ll;
#define fi first
#define se second
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
const int N=1e5+100;
int t,n;char s[N];int cnt[200];
char first(char ban){
	for(char i='a';i<='z';i++)if(i!=ban)if(cnt[i])
		return cnt[i]--,i;
	return -1;
}
void solve(){
	memset(cnt,0,sizeof cnt);int tot=0;
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n;i++)cnt[s[i]]++;
	for(int i='a';i<='z';i++)if(cnt[i]){
		//I think Wu Zixu has aked 101 many times
		//I orz Wu Zixu forever
		//Wu Zixu txdy orz,wuwa
		if(cnt[i]==n)return puts(s+1),void();
		if(cnt[i]==1){
			putchar(i);
			for(int j='a';j<='z';j++)if(i!=j)
				while(cnt[j])putchar(j),cnt[j]--;
			putchar('\n');
			return;
		}
		tot++;
	}
	for(int i='a';i<='z';i++)if(cnt[i]){
		if(cnt[i]-2<=n-cnt[i]){
			putchar(i);putchar(i);cnt[i]-=2;
			for(int j=3;j<=n;j++){
				if(j&1)putchar(first(i));
				else{
					if(cnt[i])putchar(i),cnt[i]--;
					else putchar(first(i));
				}
			}
		}else{
			putchar(i);cnt[i]--;
			if(tot==2){
				int tmp;
				while((tmp=first(i))!=-1)
					putchar(tmp);
				while(cnt[i])putchar(i),cnt[i]--;
			}else{
				int tmp;
				putchar(tmp=first(i));
				while(cnt[i])putchar(i),cnt[i]--;
				putchar(first(tmp));
				while((tmp=first(0))!=-1)putchar(tmp);
			}
		}
		return putchar('\n'),void();
	}
}
signed main(){
	read(t);while(t--)solve();
}