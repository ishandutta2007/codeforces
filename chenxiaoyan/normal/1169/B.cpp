#include<bits/stdc++.h>
using namespace std;
#define N 300000
#define pb push_back
int a[N+1],b[N+1];
vector<int> v;
int main(){
	int n,i;scanf("%d",&n);scanf("%d",&n);
	bool ok1=true,ok2=true;
	for(i=1;i<=n;i++)scanf("%d%d",a+i,b+i);
	for(i=1;i<=n;i++)if(a[i]!=a[1]&&b[i]!=a[1])v.pb(i);
	for(i=1;i<v.size();i++){
		if(a[v[i]]!=a[v[0]]&&b[v[i]]!=a[v[0]])ok1=false;
		if(a[v[i]]!=b[v[0]]&&b[v[i]]!=b[v[0]])ok2=false;
	}
	if(ok1||ok2)return !printf("YES");
	
	v.clear();
	ok1=ok2=true;
	for(i=1;i<=n;i++)if(a[i]!=b[1]&&b[i]!=b[1])v.pb(i);
	for(i=1;i<v.size();i++){
		if(a[v[i]]!=a[v[0]]&&b[v[i]]!=a[v[0]])ok1=false;
		if(a[v[i]]!=b[v[0]]&&b[v[i]]!=b[v[0]])ok2=false;
	}
	printf(ok1||ok2?"YES":"NO");
	return 0;
}
/*1
4 6
1 2
1 3
1 4
2 3
2 4
3 4
*/
/*2
5 4
1 2
2 3
3 4
4 5
*/
/*3
300000 5
1 2
1 2
1 2
1 2
1 2
*/