#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>

using namespace std;
#define ll long long

const int N = 305;
int n, t, s[N];
int solvel(int l, int r){
	int tt, st=t;
	bool fl=0, fr=0;
	while(!fl || fr){
		printf("? %d %d\n", l, r), fflush(stdout), scanf("%d", &tt);
		if((tt^t^r)&1) fr^=1; else fl^=1;
		swap(t, tt);
	}
	return (r-(t-st))/2;
}
int solver(int l, int r){
	int tt, st=t;
	bool fl=0, fr=0;
	while(fl || !fr){
		printf("? %d %d\n", l, r), fflush(stdout), scanf("%d", &tt);
		if((tt^t^r)&1) fr^=1; else fl^=1;
		swap(t, tt);
	}
	return (n-l+1-(t-st))/2;
}
int main() {
	scanf("%d%d", &n, &t);
	if(n==1) return printf("! %d\n", t), fflush(stdout), 0;
	if(n%2==0) for(int i=1; i<=n; ++i) s[i]=solvel(i, i), solvel(i, i);
	else{
		for(int i=2; i<=n; ++i) s[i]=solvel(i-1, i), solvel(i-1, i);
		s[1]=s[n]-solver(2, 3);
	}
	printf("! ");
	for(int i=1; i<=n; ++i) putchar('0'+s[i]-s[i-1]);
	puts(""), fflush(stdout);
	return 0;
}