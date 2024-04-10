#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 5005;
int n, m, a[N];
int main() {
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i){
		if(m>=(i-1)/2) m-=(i-1)/2, a[i]=i;
		else{
			a[i]=i*2-1-m*2;
			for(int j=i+1; j<=n; ++j) a[j]=1000000000-(n-j)*5000;
			m=0;
			break;
		}
	}
	if(m>0) return puts("-1"), 0;
	for(int i=1; i<=n; ++i) printf("%d%c", a[i], " \n"[i==n]);
	return 0;
}