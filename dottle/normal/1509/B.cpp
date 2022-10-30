#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

inline void MAX(int &a,const int &b) {if(b>a) a=b;}
inline void MIN(int &a,const int &b) {if(b<a) a=b;}
inline int max(const int &a,const int &b) {return a>b?a:b;}
inline int min(const int &a,const int &b) {return a<b?a:b;}

const int N=2e5+5;

int n;

char s[N];

int cm,ct;

int main() {
	
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		scanf("%s",s+1);
		cm=ct=0;
		bool flag=1;
		for(int i=1 ; i<=n&&flag ; ++i) {
			if(s[i]=='M') ++cm;
			else ++ct;
			if(ct<cm) flag=0;
		}
		flag&=(ct==cm<<1);
		ct=cm=0;
		for(int i=n ; i&&flag ; --i) {
			if(s[i]=='M') ++cm;
			else ++ct;
			if(ct<cm) flag=0;
		}
		puts(flag?"YES":"NO");
	}
	return 0;
}