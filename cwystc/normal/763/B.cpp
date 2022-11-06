#include<cstdio>
#include<cstring>
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define LL long long
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
using namespace std;
typedef pair<int,int> pa;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
#define y1 hh
int n;
struct node{
	int x1,y1,x2,y2;
}a[1000010];
int main(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	puts("YES");
	FOR(i,1,n) printf("%d\n",(abs(a[i].x1%2))*2+(abs(a[i].y1%2))+1);
	return 0;
}