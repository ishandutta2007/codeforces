#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
int n,b[25];
pii a[25];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)a[i].se=i,scanf("%d",&a[i].fi);
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)b[a[i].se]=a[i+1].fi;
	b[a[n].se]=a[1].fi;
	for(int i=1;i<=n;i++)printf("%d ",b[i]);
}