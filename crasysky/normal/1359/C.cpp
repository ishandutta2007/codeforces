#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
using namespace std;

int main() {
	int T; scanf("%d",&T);
	while (T--){
		int a,b,m; scanf("%d%d%d",&b,&a,&m);
		if (m<=(a+b)/2.0) puts("2");
		else{
			int y=(b-m)/(2*m-(a+b));//(b+(a+b)*y)/(2*y+1)=m
			pair<double,int> p(fabs((a+b)/2.0-m),2);
			rep(t,y,y+1)
				p=min(p,make_pair(fabs((b+1.0*(a+b)*t)/(2*t+1)-m),2*t+1));
			printf("%d\n",p.second);
		}
	}
}