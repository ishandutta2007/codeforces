#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int a[26],n;
char s[100005];

int main() {
	scanf("%d",&n);
	int ao = 0, lo,sum=0;
	for(int i = 0; i < n; ++i) {
		scanf("%d",a+i);
	}
	int dv = 0,odr;
	for(int p = 1; p <= 100000; ++p) {
		bool ok = true;
		int odd_r = 0, wr;
		for(int i = 0; i < n; ++i) {
			if(a[i]%p) goto skp;
			if((a[i]/p)&1) {
				++odd_r;
				wr = i;
			}
		}
		if((p&1) && odd_r == 1) {
			dv = p;
			odr = wr;
		} else if(p%2==0) {
			dv = p;
		}
		skp:;
	}
	printf("%d\n",dv);
	if(dv&1) {
		for(int i = 0; i < dv; ++i) {
			for(int j = 0; j < n; ++j)
				for(int k = 0; k < (a[j]/dv)/2; ++k)
					printf("%c",j+'a');
			printf("%c",odr+'a');
			for(int j = n-1; j >= 0; --j)
				for(int k = 0; k < (a[j]/dv)/2; ++k)
					printf("%c",j+'a');
		}
	} else if(dv != 0) {
		for(int i = 0; i < dv/2; ++i) {
			for(int j = 0; j < n; ++j)
				for(int k = 0; k < a[j]/dv; ++k)
					printf("%c",j+'a');
			for(int j = n-1; j >= 0; --j)
				for(int k = 0; k < a[j]/dv; ++k)
					printf("%c",j+'a');
		}
	} else {
		for(int i = 0; i < n; ++i) {
			while(a[i]--)
				printf("%c",i+'a');
		}
	}
	printf("\n");
	return 0;
}