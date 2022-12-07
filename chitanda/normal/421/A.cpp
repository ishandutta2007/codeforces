#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long

int n,a,b,p[101],x;

int main(){
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x),p[x]=1;
	for(int j=1;j<=b;j++) scanf("%d",&x),p[x]=2;
	for(int i=1;i<=n;i++) printf("%d ",p[i]);
	return 0;
}