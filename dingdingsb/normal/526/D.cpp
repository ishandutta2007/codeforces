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
const int N=1e6+100;
const int mod=998244353;
int n,k;
char str[N];
struct string{
    long long Hash[N];
    long long Pow[N];int b;
    void init(int B){b=B;Pow[0]=1;for(int i=1;i<=n;i++)Pow[i]=(Pow[i-1]*b)%mod;for(int i=1;i<=n;i++)Hash[i]=(Hash[i-1]*b+str[i]-'a')%mod;}
	long long get(int l, int r){return ((Hash[r]-Hash[l-1]*Pow[r-l+1])%mod+mod)%mod;}char *operator+(const int x){return str+x;}
	int lcs(int x, int y){int l=0,r=n-y+1;while(l<r){int mid=l+r+1>>1;if(get(x,x+mid-1)==get(y,y+mid-1))l=mid;else r=mid-1;}return l;}
}S1,S2;
int cf[N];//
signed main(){
	read(n,k);
	scanf("%s",str+1);
	S1.init(31),S2.init(117);
	for(int i=1,kk;i<=n;i++){
		if(n/i<k)break;
		for(int j=2;j<=k;j++){
			int st=(j-1)*i+1,ed=j*i;
			if(S1.get(1,i)!=S1.get(st,ed)||S2.get(1,i)!=S2.get(st,ed))
				goto loop;
		}
		kk=min(i,min(S1.lcs(1,k*i+1),S2.lcs(1,k*i+1)));
		cf[k*i]++;
		cf[k*i+kk+1]--;
		loop:;
	}
	for(int i=1;i<=n;i++)
		cf[i]+=cf[i-1],
		putchar(cf[i]>0?'1':'0');
}