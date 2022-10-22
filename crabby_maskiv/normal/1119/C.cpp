#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int N=505;
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
int a[N][N],b[N][N];
int s1[N],s2[N];
int main()
{
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)
			cin>>a[i][j];
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)
			cin>>b[i][j];
	}
	#ifdef TIME
		clock_t ST=clock();
	#endif
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)
			s1[i]+=(a[i][j]!=b[i][j]);
	}
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++)
			s2[i]+=(a[j][i]!=b[j][i]);
	}
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	for(i=1;i<=n;i++){
		if(s1[i]&1){
			cout<<"NO";
			return 0;
		}
	}
	for(i=1;i<=m;i++){
		if(s2[i]&1){
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}