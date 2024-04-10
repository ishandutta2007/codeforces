#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<bitset>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mk make_pair
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,i,j,t,cnt[26];
set<int> s;
string st;
int main()
{
	ios_base::sync_with_stdio(0); 
	cin>>t;
	while(t--){
		cin>>st;
		fz0k(i,26)cnt[i]=0;
		fz0k(i,st.size()) cnt[st[i]-'a']++;
		s.clear();
		fz0k(i,26) if(cnt[i])s.insert(i);
		sort(st.begin(),st.end());
		int t=*s.begin();
		if(s.size()==1||cnt[t]==1){
			puts(st.c_str());
			continue;
		}
		fz0k(i,26) if(cnt[i]==1){
			break;
		}
		if(i<26){
			putchar('a'+i);
			fz0k(j,st.size())if(st[j]!=i+'a') putchar(st[j]);
			puts("");continue;
		}
		if(cnt[t]-2<=st.size()-cnt[t]){
			putchar('a'+t);putchar('a'+t);
			i=cnt[t];cnt[t]-=2;
			while(i<st.size()){
				putchar(st[i]);
				if(cnt[t]){
					putchar('a'+t);
					cnt[t]--;
				}
				i++;
			}
			puts("");
			continue;
		}
		s.erase(t);
		int x=*s.begin();s.erase(x);
		swap(st[1],st[cnt[t]]);
		if(cnt[x]==1){
			puts(st.c_str());
			continue;
		}
		if(!s.empty()){
			swap(st[cnt[t]+1],st[cnt[t]+cnt[x]]);
			puts(st.c_str());
			continue;
		}
		putchar('a'+t);cnt[t]--;
		while(cnt[x]--) putchar('a'+x);
		while(cnt[t]--) putchar('a'+t);
		puts("");
	}
	return 0;
}