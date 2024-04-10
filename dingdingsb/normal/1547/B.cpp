// Problem: CF1547B Alphabetical Strings
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1547B
// Memory Limit: 500 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
int t,n;char s[30];
signed main(){
	read(t);while(t--){
		cin>>s+1;int n=strlen(s+1);
		int l=1,r=n;vector<int>ch;
		while(l<=r){
			if(s[l]>s[r])ch.pb(s[l]),l++;
			else if(s[l]<s[r])ch.pb(s[r]),r--;
			else if(l==r)ch.pb(s[l]),l++;
			else{puts("nO");goto nxt;}
		}
		reverse(ch.begin(),ch.end());
		for(int i=0;i<ch.size();i++)
			if(ch[i]!='a'+i){puts("nO");goto nxt;}
		puts("YES");
		nxt:;
	}
}