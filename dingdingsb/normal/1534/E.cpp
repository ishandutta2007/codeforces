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
const int N=500+10;
int n,k,dis[N],pre[N],ans;
queue<int>q;vector<int>ou,ji;
signed main(){
	read(n,k);
	memset(dis,-1,sizeof dis);
	dis[0]=0;q.push(0);
	while(q.size()){
		int i=q.front();q.pop();
		//i n-i 
		//i
		for(int j=0;j<=k;j++)
			 if(k-j<=n-i&&j<=i){
			 	//j
			 	//k-j 
				int tmp=i-j+(k-j);
				if(dis[tmp]==-1){
					dis[tmp]=dis[i]+1;
					pre[tmp]=i;q.push(tmp);
				}
			 }
	}
	if(dis[n]==-1)return puts("-1"),0;
	for(int i=1;i<=n;i++)ou.pb(i);
	vector<int>ge;int tmp=n;
	do{
		ge.pb(tmp),tmp=pre[tmp];
	}while(tmp!=0);ge.pb(0);
	reverse(ge.begin(),ge.end());
	//for(auto x:ge)printf("%d ",x);putchar('\n');
	for(int i=1;i<ge.size();i++){
		//x 
		int x=(ge[i-1]-ge[i]+k)/2;
		vector<int>tmp1,tmp2;
		cout<<"? ";
		for(int j=1;j<=x;j++)tmp1.pb(ji.back()),cout<<ji.back()<<" ",ji.pop_back();
		for(int j=1;j<=k-x;j++)tmp2.pb(ou.back()),cout<<ou.back()<<" ",ou.pop_back();
		cout<<endl;
		for(auto j:tmp2)ji.pb(j);
		for(auto j:tmp1)ou.pb(j);
		assert(ji.size()==ge[i]);
		cin>>tmp;ans^=tmp;
	}
	cout<<"! "<<ans<<endl;
}