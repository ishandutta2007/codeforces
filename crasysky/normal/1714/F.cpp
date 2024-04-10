#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
using namespace std;

int main(){
	int T; cin>>T;
	while (T--){
		int n,d12,d23,d31; scanf("%d%d%d%d",&n,&d12,&d23,&d31);
		if ((d12+d23+d31)%2!=0){ puts("NO"); continue; }
		if ((d12+d23+d31)/2+1>n){ puts("NO"); continue; }
		int d[4];
		d[1]=(d12-d23+d31)/2;
		d[2]=(d12+d23-d31)/2;
		d[3]=(-d12+d23+d31)/2;
		if (d[1]<0||d[2]<0||d[3]<0||(int)(d[1]==0)+(int)(d[2]==0)+(int)(d[3]==0)>1){
			puts("NO"); continue;
		}
		puts("YES");
		int mid,cnt=3;
		if (d[1]==0) mid=1;
		else if (d[2]==0) mid=2;
		else if (d[3]==0) mid=3;
		else mid=4,++cnt;
		rep(i,1,3){
			if (d[i]==0) continue;
			int u=i;
			rep(j,1,d[i]-1)
				printf("%d %d\n",u,++cnt),u=cnt;
			if (d[i]>1) printf("%d %d\n",cnt,mid);
            else printf("%d %d\n",u,mid);
		}
        rep(i,cnt+1,n) printf("%d %d\n",i,mid);
	}
	return 0;
}