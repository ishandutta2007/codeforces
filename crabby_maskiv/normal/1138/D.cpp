#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int maxn=500005;
const int inf=0x3f3f3f3f;
const int mod=998244353;
template<typename T>inline void read(T &x) {
    int f=1;x=0;char c=getchar();
    while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    x*=f;return;
}
template<typename T,typename...Args>
	inline void read(T &x,Args &...args){
	read(x);read(args...);
}
int n,m;
string s,t;
int nxt[maxn];
int main()
{
	int i,j;
	cin>>s>>t;
	int lens=s.length(),lent=t.length();
	s=" "+s;t=" "+t;
	
	if(lens<lent){
		for(i=1;i<=lens;i++) putchar(s[i]);
		return 0;
	}
	int cnt0=0,cnt1=0;
	for(i=1;i<=lens;i++){
		if(s[i]-'0'==1) cnt1++;
		else cnt0++;
	}
	int tmp;
	for(i=2;i<=lent;i++){
		int p=i-1;
		while(p>0){
			if(t[nxt[p]+1]==t[i]){
				nxt[i]=nxt[p]+1;
				break;
			}
			else p=nxt[p];
		}
	}
	tmp=lent-nxt[lent];
	#ifdef TIME
		clock_t ST=clock();
	#endif
	if(tmp>=lent) tmp=lent;
	int a1=0,a0=0;
	int b1=0,b0=0;
	string k=t.substr(lent-tmp+1,tmp);
	k=" "+k;
	for(i=1;i<=tmp;i++){
		if(k[i]-'0'==1) a1++;
		else a0++;
	}
	for(i=1;i<=lent;i++){
		if(t[i]-'0'==1) b1++;
		else b0++;
	}
	if(b1>cnt1||b0>cnt0){
		for(i=1;i<=lens;i++) putchar(s[i]);
		return 0;
	}
	for(i=1;i<=lent;i++) putchar(t[i]);
	cnt0-=b0;cnt1-=b1;
	while(cnt1>=a1&&cnt0>=a0){
		cnt1-=a1;
		cnt0-=a0;
		for(i=1;i<=tmp;i++) putchar(k[i]);
	}
	while(cnt1--) putchar('1');
	while(cnt0--) putchar('0');
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	return 0;
}