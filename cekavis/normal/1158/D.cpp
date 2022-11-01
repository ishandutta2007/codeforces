#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 2005;
int n;
char s[N];
bool vis[N];
struct vec{
	int x, y;
	vec(int a=0, int b=0){ x=a, y=b;}
	vec operator-(const vec &r)const{ return vec(x-r.x, y-r.y);}
	ll operator*(const vec &r)const{ return (ll)x*r.y-(ll)y*r.x;}
} a[N];
int main() {
	scanf("%d", &n);
	int x=1;
	for(int i=1; i<=n; ++i){
		scanf("%d%d", &a[i].x, &a[i].y);
		if(a[i].x<a[x].x) x=i;
	}
	scanf("%s", s+1);
	vis[x]=1, printf("%d", x);
	vec now(1, 0);
	for(int i=1; i<n; ++i){
		int t=0;
		for(int j=1; j<=n; ++j) if(!vis[j]){
			if(s[i]=='L'){
				if(!t || (a[j]-a[x])*(a[t]-a[x])>0) t=j;
			}
			else{
				if(!t || (a[j]-a[x])*(a[t]-a[x])<0) t=j;
			}
		}
		now=a[t]-a[x], x=t, vis[x]=1;
		printf(" %d", x);
	}
	return 0;
}