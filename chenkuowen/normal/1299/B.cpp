#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+1e5;
typedef long long ll;
struct C{ int x,y; }a[MAX_N];
struct Vec{ 
	int x,y;
	Vec(C a,C b){ x=b.x-a.x,y=b.y-a.y; }
	inline ll cp(Vec b){
		return 1ll*x*b.y-1ll*y*b.x;
	}
	inline ll dis(){ return 1ll*x*x+1ll*y*y; }
	inline bool operator!=(Vec b){
		return x!=b.x||y!=b.y;
	}
};
int main(){
	int n; scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d%d",&a[i].x,&a[i].y);
	if(n&1){
		puts("NO");
		return 0;
	}
	for(int i=0;i<n;++i)
		if(Vec(a[i],a[(i+1)%n])!=Vec(a[(i+n/2+1)%n],a[(i+n/2)%n])){
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0;
}