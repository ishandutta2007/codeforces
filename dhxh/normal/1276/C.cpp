#include <bits/stdc++.h>

using namespace std;

const int maxn = 4e5 + 5;

int n;

int a[maxn];
int cnt[maxn];
int f[maxn];
int ans[maxn];
int b[maxn];
int c[maxn];

int main(){
	int i, j, k;
	int x, y;
	
	scanf("%d", &n);
	
	for(i=1;i<=n;i++){
		scanf("%d", &b[i]);
	}
	
	sort(b + 1, b + n + 1);
	
	x = 1;
	a[1]++;
	c[1] = b[1];
	
	for(i=2;i<=n;i++){
		if(b[i] == b[i - 1]){
			a[x]++;
		}else{
			c[++x] = b[i];
			a[x]++;
		}
	}
	
	for(i=1;i<=n;i++){
		cnt[a[i]]++;
	}
	
	int sum = n, s = 0;
	
	for(i=n;i>0;i--){
		f[i] = sum;
		s += cnt[i];
		sum -= s;
	}
	
	x = 0, y = 0;
	
	for(i=1;i<=n;i++){
		for(j=i;j<=n and 1ll*i*j<=n;j++){
			if(1ll * i * j > x * y and f[i] >= 1ll * i * j){
				x = i, y = j;
			}
		}
	}
	
	printf("%d\n", x * y);
	printf("%d %d\n", x, y);
	
	deque <int> q;
	
	for(i=1;i<=n;i++){
		if(x <= a[i] and q.size() + x <= x * y){
			for(j=1;j<=x;j++){
				q.push_front(i);
			}
		}else{
			for(j=1;j<=min(x, a[i]) and q.size()<x*y;j++){
				q.push_back(i);
			}
		}
	}
	
	for(i=0;i<y;i++){
		for(j=i,k=0;k<x;k++,j=(j+1)%y){
			ans[k * y + j] = q.front();
			q.pop_front();
		}
	}
	
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			printf("%d ", c[ans[i * y + j]]);
		}
		printf("\n");
	}
	
	return 0;
}