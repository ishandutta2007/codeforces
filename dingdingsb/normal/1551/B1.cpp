// Problem: CF1551B1 Wonderful Coloring - 1
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1551B1
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
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
constexpr int N=2e5+100;
int T,t[26];char str[N];
int main(){
	scanf("%d",&T);
	while(T--){
		memset(t,0,sizeof t);
		cin>>str;	
		int n=strlen(str);
		int _=n;
		for(int i=0;i<_;i++)
			t[str[i]-'a']++,
			t[str[i]-'a']>=3&&(n--);
		cout<<n/2<<endl;
    }
	return 0;
}