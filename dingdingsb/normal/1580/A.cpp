// Problem: C. Portal
// Contest: Codeforces - Codeforces Round #745 (Div. 2)
// URL: https://codeforces.ml/contest/1581/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
const int  N=410;
int t,n,m;char s[N][N];
int sum[N][N];
int S(int x1,int y1,int x2,int y2){
	return (x2-x1+1)*(y2-y1+1);
}
int get(int x1,int y1,int x2,int y2){
	return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}
bool out=true;
void work(){
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			sum[i][j]=(s[i][j]=='1')+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
	int ans=16;
	for(int i=2;i<n;i++)for(int j=2;j<m;j++)
		for(int k=i+2;k<n;k++){
			for(int nm=j+1;nm<m;nm++){
				int tt=get(i,j,k,nm)+2*(nm-j+1)-get(i-1,j,i-1,nm)-get(k+1,j,k+1,nm)+(k-i+1)-get(i,j-1,k,j-1);
				if(tt>=ans)break;
				chkmn(ans,tt+(k-i+1)-get(i,nm+1,k,nm+1));
				//if(tt+(nm-j+1)-get(k+1,j,k+1,nm)==5)
				//	printf("%d %d %d %d\n",i,j,k,nm);
			}
		}
	if(out)write(ans),putchar('\n');
}
signed main(){
	read(t);
	for(int i=1;i<=t;i++){
		read(n,m);
		//if(i==1&&n==5&&m==5&&t==68)out=false;
		work();
		//if(!out&&i==60)for(int i=1;i<=n;i++)puts(s[i]+1);
	}
}