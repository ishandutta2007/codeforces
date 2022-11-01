#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
const long long inf = 0x3f3f3f3f3f3f3f3f;

int n, k;

char a[maxn];

long long f[maxn];

int main(){
	int i, j;
	
	scanf("%d%d", &n, &k);
	
	for(i=1;i<=n;i++){
		scanf(" %c", &a[i]);
	}
	
	memset(f, 0x3f, sizeof(f));
	f[0] = 0;
	
	list <int> qa, qb;
	qa.push_back(0);	
	for(i=1;i<=n;i++){
		while(qa.size() and qa.front() < i - k - 1)qa.pop_front();
		while(qb.size() and qb.front() < i - k - 1)qb.pop_front();
		f[i] = min(f[i], f[i - 1] + i);
		if(a[i] == '1'){
			int x = qa.front();
			if(qb.size() and f[qb.front()] < f[x])x = qb.front();
			f[min(i + k, n)] = min(f[min(i + k, n)], f[x] + i);
			while(qb.size() and f[qb.back()] > f[min(i + k, n)])qb.pop_back();
			qb.push_back(min(i + k, n));
		}
		
		while(qa.size() and f[qa.back()] > f[i])qa.pop_back();
		qa.push_back(i);
	}
	
	printf("%lld\n", f[n]);
	
	return 0;
}