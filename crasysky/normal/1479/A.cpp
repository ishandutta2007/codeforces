#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back
using namespace std;
int Q(int x){
	printf("? %d\n",x); fflush(stdout);
	int y; scanf("%d",&y); return y;
}
void A(int x){
	printf("! %d\n",x); fflush(stdout); exit(0);
}
int main(){
	int n; scanf("%d",&n);
	if (n==1) A(1);
	int x=Q(2),p=2; if (Q(1)<x) A(1);
	per(i,20,0)
		if (p+(1<<i)<=n){
			int a=Q(p+(1<<i)-1),b=Q(p+(1<<i));
			if (x>=a&&a>b) p+=1<<i;
		}
	A(p);
}