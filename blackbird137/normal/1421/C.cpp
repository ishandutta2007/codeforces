#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define int long long

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=1e5+5;
int n;
char s[N];

signed main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	printf("3\n");
	printf("L 2\n");n++;
	printf("R 2\n");n+=n-2;
	printf("R %lld\n",n-1);
	return 0;
}