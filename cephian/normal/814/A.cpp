#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int a[200],b,n,k;

int main() {
	scanf("%d%d",&n,&k);
	if(k!=1) {
		printf("Yes\n");
		return 0;
	}
	for(int i = 0; i < n; ++i) {
		scanf("%d",a+i);
	}
	scanf("%d",&b);
	for(int i = 0; i < n; ++i)
		if(a[i]==0)a[i]=b;
	for(int i = 1; i < n; ++i) {
		if(a[i]<a[i-1]) {
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}