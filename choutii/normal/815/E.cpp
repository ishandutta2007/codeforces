#include<iostream>
#include<cstdio>
#include<map>
#define fir first
#define sec second
typedef long long LL;
using namespace std;
map <LL, LL> f, g, h, a, b, c;
LL n, k;

int main(){
	cin >> n >> k;
	if(k == 1) return puts("1"), 0;
	if(k == 2) return printf("%lld\n", n), 0;
	n -= 2; k -= 3;
	g[n] = 1;
	while(!g.empty()){
		h.clear();
		for(map<LL, LL> :: iterator x = g.begin(); x != g.end(); x++) {
			if(x -> fir) 
				f[-(x -> fir - 1 >> 1)] += x -> sec,  
				h[x -> fir >> 1] += x -> sec, 
				h[x -> fir - 1 >> 1] += x -> sec;
		}
		g = h;
	}
	
	for(map<LL, LL> :: iterator x = f.begin(); x != f.end(); x++){
		if(k >= x -> sec) 
			k -= x -> sec;
		else{
			LL l = 1, r = n, d = -x -> fir;
			while(1){
				if(!k && (r - l >> 1) == d) 
					return printf("%lld\n", l + 1 + d), 0;
				a.clear(); b.clear();
				a[r - l >> 1] = b[r - l >> 1] = 1;
				while(!b.empty()){
					c.clear();
					for(map<LL, LL> :: iterator x = b.begin(); x != b.end(); x++) 
						if(x -> fir) {
							a[x -> fir - 1 >> 1] += x -> sec;
							c[x -> fir >> 1] += x -> sec;
							c[x -> fir - 1 >> 1] += x -> sec;
							
						}
					b = c;
				}
				
				LL m = l + r >> 1;
				if(k >= a[d]) 
					k -= a[d], l = m + 1;
				else 
					r = m - 1;
			}
		}
	}
	return 0;
}