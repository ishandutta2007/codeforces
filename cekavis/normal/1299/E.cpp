#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 805;
int n, m, cnt, a[N], f[N], g[N], p[N];
bool ask(const vector<int> &x){
	++cnt;
	printf("? %d", (int)x.size());
	for(int i:x) printf(" %d", i);
	puts(""), fflush(stdout);
	int o;
	scanf("%d", &o);
	return o;

	int s=0;
	for(int i:x) s+=a[i];//, printf("[%d]", i); puts("");
	return !(s%x.size());
}
int main() {
	mt19937 rng(random_device{}());
	scanf("%d", &n);
	// for(int i=1; i<=n; ++i) a[i]=i;
	// shuffle(a+1, a+n+1, rng);
	for(int i=1; i<=n; ++i){
		vector<int> x;
		for(int j=1; j<=n; ++j) if(i!=j) x.push_back(j);
		if(ask(x)) g[f[i]=g[1]?n:1]=i;
	}
	// for(int i=1; i<=n; ++i) printf("[%d %d]\n", a[i], f[i]);
	for(int i=1; i<=n; ++i) if(!f[i]) p[i]=ask({i, g[1]});
	m=2;
	for(int i=2, l, r; i<=n/2; ++i){
		vector<int> X;
		for(int j=1; j<=n; ++j) if(!f[j]) X.push_back(j);
		shuffle(X.begin(), X.end(), rng);
		for(int j:X) if(p[j]==i%m){
			vector<int> x;
			for(int k:X) if(j!=k) x.push_back(k);
			if(ask(x)){ l=j; break;}
		}
		for(int j:X) if(p[j]==(n-i+1)%m){
			vector<int> x;
			for(int k:X) if(j!=k) x.push_back(k);
			if(ask(x)){ r=j; break;}
		}
		g[f[l]=i]=l, g[f[r]=n-i+1]=r;
		if(i==m*2){
			for(int j=1; j<=n; ++j) if(!f[j]){
				vector<int> x={j};
				for(int k=1; k<=i; ++k) if(k!=(p[j]?p[j]:m)) x.push_back(g[k]);
				p[j]+=m*(ask(x)^!p[j]);
				// assert(p[j]==a[j]%(m*2) || p[j]==(n-a[j]+1)%(m*2));
			}
			m*=2;
		}
	}
	if(f[1]>n/2) for(int i=1; i<=n; ++i) f[i]=n-f[i]+1;
	// if(a[1]>n/2) for(int i=1; i<=n; ++i) a[i]=n-a[i]+1;
	printf("! ");
	for(int i=1; i<=n; ++i) printf("%d%c", f[i], " \n"[i==n]);
	// printf("%d/%d\n", cnt, n*18);
	// assert(cnt<=n*18);
	return fflush(stdout), 0;
}