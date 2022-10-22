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
const int N=2e3+100;
int n;set<pair<int,int>>s;
int dep[N];
signed main(){
	cin>>n;
	cout<<"? 1"<<endl;
	int cnt0=0,cnt1=0;
	for(int i=1;i<=n;i++)
		cin>>dep[i];
	for(int i=2;i<=n;i++){
		if(dep[i]%2==0)cnt0++;
		else cnt1++;
		if(dep[i]==1)s.insert(mp(1,i));
	}
	int tar;
	if(cnt0<=(n-1)/2)tar=0;
	else tar=1;
	for(int i=2;i<=n;i++)if(dep[i]%2==tar){
		cout<<"? "<<i<<endl;
		for(int j=1,x;j<=n;j++){
			cin>>x;if(x==1)s.insert(mp(min(i,j),max(i,j)));
		}
	}
	cout<<"!"<<endl;
	for(auto X:s)cout<<X.fi<<" "<<X.se<<endl;
}