#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <utility>
#define maxn 100005
using namespace std;
typedef long long ll;
int n,x,a[maxn],b[maxn];
map <int,int> a1,a2;
int ans = 10;
int main(){
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a1.find(a[i]) != a1.end()){
			ans = min(ans,0);
		}
		a1[a[i]]++;
		b[i] = (a[i] & x);
		if(a2.find(b[i]) != a2.end()){
			ans = min(ans,2);
		}
		a2[b[i]]++;
	}
	for(int i=1;i<=n;i++){
		a1[a[i]]--;
		if(a1.find(b[i]) != a1.end() && a1[b[i]] > 0){
			ans = min(ans,1);
		}
		a1[a[i]]++;
	}
	if(ans == 10) puts("-1");
	else printf("%d\n",ans);
	return 0;
}