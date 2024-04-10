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
const int N=2e5+100;
int t,n,cnt[N][5],len[N];
char str[N];
signed main(){
	read(t);while(t--){
		read(n);
		for(int i=1;i<=n;i++){
			scanf("%s",str+1);
			len[i]=strlen(str+1);
			memset(cnt[i],0,sizeof cnt[i]);
			for(int j=1;j<=len[i];j++)
				cnt[i][str[j]-'a']++;
		}
		int ans=0;
		for(int i=0;i<5;i++){
			vector<int>zyy;
			for(int j=1;j<=n;j++)
				zyy.pb(cnt[j][i]-(len[j]-cnt[j][i]));
			sort(zyy.begin(),zyy.end());reverse(zyy.begin(),zyy.end());
			int now=0;
			for(int j=0;j<n;j++){
				now+=zyy[j];
				if(now>0)chkmx(ans,j+1);
			}
		}
		write(ans);putchar('\n');
	}
}