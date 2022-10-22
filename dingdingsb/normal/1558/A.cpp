// Problem: B. Charmed by the Game
// Contest: Codeforces - Codeforces Round #740 (Div. 2, based on VK Cup 2021 - Final (Engine))
// URL: https://codeforces.com/contest/1561/problem/B
// Memory Limit: 512 MB
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
int t,a,b;
signed main(){
	read(t);while(t--){
		read(a,b);int n=a+b;
		vector<int>ans;
		if(n&1){
			int ka=n/2,kb=n-ka;
			for(int x=0;x<=ka;x++){
				if(b-(ka-x)<0)continue;
				if(kb-(b-(ka-x))<0)continue;
				ans.pb(ka-x+kb-(b-(ka-x)));
			}
			swap(ka,kb);
			for(int x=0;x<=ka;x++){
				if(b-(ka-x)<0)continue;
				if(kb-(b-(ka-x))<0)continue;
				ans.pb(ka-x+kb-(b-(ka-x)));
			}
		}else{
			int ka=n/2,kb=n/2;
			for(int x=0;x<=ka;x++){
				if(b-(ka-x)<0)continue;
				if(kb-(b-(ka-x))<0)continue;
				ans.pb(ka-x+kb-(b-(ka-x)));
			}
		}
		sort(ans.begin(),ans.end());
		ans.resize(unique(ans.begin(),ans.end())-ans.begin());
		write(ans.size());putchar('\n');
		for(auto x:ans)write(x),putchar(' ');putchar('\n');
	}
	return 0;
	
}