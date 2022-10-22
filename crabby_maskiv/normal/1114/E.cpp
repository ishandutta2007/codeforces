#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100005;
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
int gcd(int a,int b){
	if(!b) return a;
	return gcd(b,a%b);
}
int main()
{
	int i,j;int mx;
	srand((unsigned)time(NULL));
	read(n);int cnt;
	#ifdef TIME
		clock_t ST=clock();
	#endif
	int l=0,r=1000000000;
	while(r-l>5){
		int mid=(l+r)/2;
		cout<<"> "<<mid<<endl;
		cout.flush();
		bool tmp;
		read(tmp);cnt++;
		if(tmp) l=mid;
		else r=mid;
	}
	for(i=r;i>=l;i--){
		cout<<"> "<<i<<endl;
		cout.flush();
		bool tmp;
		read(tmp);cnt++;
		if(tmp){
			mx=i+1;
			break;
		}
	}
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	int ans=0;
	while(cnt<60){
		int a=rand(),b=rand();
		int k=(a*32768+b)%n+1;
		cout<<"? "<<k<<endl;
		cout.flush();
		int tmp;read(tmp);cnt++;
		ans=gcd(ans,mx-tmp);
	}
	cout<<"! "<<mx-ans*(n-1)<<" "<<ans;
	return 0;
}