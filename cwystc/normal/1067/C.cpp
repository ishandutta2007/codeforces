#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define LL long long
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FORD(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
typedef pair<int,int> pa;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
int n,t;
int main(){
	cin>>n;
	t=(n-1)/4;
	puts("0 0");
	FOR(i,1,t) printf("%d 0\n",i);
	FOR(i,1,t) printf("%d 0\n",-i);
	FOR(i,1,t) printf("0 %d\n",i);
	FOR(i,1,t) printf("0 %d\n",-i);
	if ((n-1)%4>=1) printf("%d 0\n",t+1);
	if ((n-1)%4>=2) printf("0 %d\n",t+1);
	if ((n-1)%4>=3) printf("%d 0\n",-t-1);
	return 0;
}