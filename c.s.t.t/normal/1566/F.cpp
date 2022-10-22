#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,m,a[200100];
struct Sec{
	int L,R;
	friend bool operator<(const Sec&u,const Sec&v){return u.L==v.L?u.R>v.R:u.L<v.L;}
}s[200100],t[200100];
ll f[200100][2];//doubled leftwards/rightwards.
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<=m;i++)scanf("%d%d",&s[i].L,&s[i].R);
		sort(s+1,s+m+1);
		for(int i=m,mn=0x3f3f3f3f,M=m=0;i;i--){
			M=lower_bound(a+1,a+n+1,s[i].L)-a;
			if(M<=n&&a[M]<=s[i].R)continue;
			if(s[i].R<mn)t[++m]=s[i],mn=s[i].R;
		}
		reverse(t+1,t+m+1);
//		for(int i=1;i<=m;i++)printf("QWQ:%d %d\n",t[i].L,t[i].R);
		int l=1,r=1,DL,DR;
		while(r<=m&&t[r].R<a[1])r++;
		DL=(r==1?0:a[1]-t[1].R);
		f[1][0]=2ll*DL,f[1][1]=DL;
//		printf("%d:%d %d\n",1,f[1][0],f[1][1]);
		l=r;
		for(int i=1;i<n;i++){
			while(r<=m&&t[r].R<a[i+1])r++;
			f[i+1][0]=f[i+1][1]=0x3f3f3f3f3f3f3f3f;
			for(int j=l;j<=r;j++){
				DL=(j==l?0:t[j-1].L-a[i]);
				DR=(j==r?0:a[i+1]-t[j].R);
				f[i+1][0]=min(f[i+1][0],min(f[i][0]+DL,f[i][1]+2ll*DL)+2ll*DR);
				f[i+1][1]=min(f[i+1][1],min(f[i][0]+DL,f[i][1]+2ll*DL)+DR);
			}
			l=r;
//			printf("%d:%d %d\n",i+1,f[i+1][0],f[i+1][1]);
		}
		DR=(r>m?0:t[m].L-a[n]);
		printf("%lld\n",min(f[n][0]+DR,f[n][1]+2ll*DR));
	}
	return 0;
}
/*
1
4 12
-9 -16 12 3
-20 -18
-14 -13
-10 -7
-3 -1
0 4
6 11
7 9
8 10
13 15
14 18
16 17
18 19
*/