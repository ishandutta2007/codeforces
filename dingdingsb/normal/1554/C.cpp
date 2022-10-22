// Problem: Mikasa
// Contest: Codeforces
// URL: https://m1.codeforces.ml/contest/1554/problem/C
// Memory Limit: 256 MB
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
#define int long long
typedef long long ll;
int t,n,m;const int B=31;
int a[B],b[B];vector<pair<int,int>>e;
signed main(){
	read(t);
	while(t--){
		read(n,m);
		if(n>m)puts("0");
		else{
			e.clear();
			for(int j=0;j<B;j++)a[j]=n>>j&1;
			for(int j=0;j<B;j++)b[j]=m>>j&1;
			int now=0;
			for(int j=B-1;~j;j--){
				if(b[j]==0)now^=a[j]<<j;
				else{
					e.push_back({now+(a[j]<<j),now+(a[j]<<j)+((1<<j)-1)});
					now^=(a[j]^1)<<j;
				}
			}
			e.push_back({now,now});
			sort(e.begin(),e.end());
			//for(auto [x,y]:e)
			//	printf("%d %d\n",x,y);
			int r=e[0].second;
			for(int i=1;i<e.size();i++)
				if(r!=e[i].first-1)break;
				else r=e[i].second;
			write(r+1);putchar('\n');
	
		}
	}
    return 0;
    cout<<"ccfn***";
}