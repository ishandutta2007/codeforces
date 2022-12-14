#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 1110111
const int mo = 1e9+7;
char str[N];
int A[N],x[N],n1[N],vis[N], n, m;
int pow(int a, int b, int c){
	a %= mo;
	int ret = 1;
	while(b){
		if(b & 1) ret = 1LL * ret * a % c;
		a = 1LL * a * a % c;
		b >>= 1;
	}
	return ret;
}
int main(){
	scanf("%d%d",&n,&m);scanf("%s",str+1);
	for (int i=1;i<=m;i++) scanf("%d",&x[i]);
	int L=strlen(str+1);
	for (int i=2;i<=L;i++){
		int P=n1[i-1];		while (str[P+1]!=str[i]&&P) P=n1[P];if (str[P+1]==str[i]) n1[i]=P+1; else n1[i]=P;
	}
	int P=0,cnt=0;for (int i=L;i;i=n1[i]) vis[i]=1;for (int i=1;i<=m;i++) A[x[i]]=1;
	for (int i=1;i<=n;i++)
		if ((i>=P+L||!P)&&!A[i]) cnt++;
		else if (A[i]==1){
			if (P==0||i>=P+L){P=i; continue;}
			int k1=P+L-i;
			if (!vis[k1]){cout<<0<<endl; return 0;	}
			P=i;
		}
	printf("%d\n", pow(26, cnt, mo));
	return 0;
}