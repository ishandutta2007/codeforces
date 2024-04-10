#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e6+6; char s[N];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		scanf("%s",s); 
		int n=strlen(s),c=0;
		rep(i,1,n-1){
			if (s[i]==s[i-1]) s[i]=' ',++c;
			else if (i>1&&s[i]==s[i-2]) s[i]=' ',++c;
		}
		printf("%d\n",c);
	}
	return 0;
}