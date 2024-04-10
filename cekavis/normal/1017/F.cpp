#include<cstdio>
#include<bitset>

using namespace std;
bitset<100000010> p;
unsigned n, A, B, C, D, ans;
inline unsigned calc(unsigned x){
	unsigned sum=0;
	for(unsigned long long i=x; i<=n; i*=x) sum+=n/i;
	return (((A*x+B)*x+C)*x+D)*sum;
}
int main() {
	scanf("%u%u%u%u%u", &n, &A, &B, &C, &D);
	ans=calc(2)+calc(3);
	for(unsigned i=1, now;; ++i) if(!p[i]){
		if((now=i*3+1+(i&1))>n) break;
		ans+=calc(now);
		unsigned j=now;
		while((j+=now<<2)<=n){
			p[j/3]=1;
			if((j+=now<<1)<=n) p[j/3]=1;
		}
	}
	return printf("%u", ans), 0;
}