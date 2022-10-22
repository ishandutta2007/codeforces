// Problem: D. Omkar and the Meaning of Life
// Contest: Codeforces - Codeforces Round #749 (Div. 1 + Div. 2, based on Technocup 2022 Elimination Round 1)
// URL: https://codeforces.com/contest/1586/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define pc putchar
#define mp make_pair
#define fi first
#define se second
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
typedef long long ll;
const int N=1e2+100;
int n;
int a[N];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cout<<"? ";
		for(int j=1;j<n;j++)cout<<i<<' ';
		cout<<n<<endl;
		int t;cin>>t;if(t){
			a[n]=i;break;
		}
	}
	if(!a[n])a[n]=n;
	for(int i=1;i<=n;i++)if(i!=a[n]){
		int add=-1;
		for(add=1;add<=n;add++)
			if(1<=i+add-a[n]&&i+add-a[n]<=n)break;
		assert(add!=-1);
		cout<<"? ";
		for(int j=1;j<n;j++)cout<<add<<' ';
		cout<<i+add-a[n]<<endl;
		int t;cin>>t;a[t]=i;
	}
	cout<<"! ";
	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	cout<<endl;
}