#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FORD(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
typedef long long LL;
typedef pair<int,int> pa;
typedef vector<int> vec;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
int T,n,l1,l2,l3,r1,r2,r3,l0,r0;

void doit(){
	scanf("%d",&n);
	scanf("%d%d%d%d%d%d",&l1,&r1,&l2,&r2,&l3,&r3);
	int o1=(l1+r1)%2;
	int o2=(l2+r2)%2;
	int o3=(l3+r3)%2;
	if (o1!=o2 && o1!=o3){
	
	}
	else if (o2!=o1 && o2!=o3){
		swap(l1,l2);
		swap(r1,r2);
		swap(o1,o2);
		
	}
	else{
		swap(l1,l3);
		swap(r1,r3);
		swap(o1,o3);
	}
	scanf("%d%d",&l0,&r0);
	int o0=(l0+r0)%2;
	if ((l1==1 || l1==n) && (r1==1 || r1==n)){
		if ((l0!=l1)+(r0!=r1)<=1) puts("YES");
		else puts("NO");
	}
	else{
		if (o0==o1 && (l0-l1)%2!=0) puts("NO");
		else puts("YES");
	}
}
int main(){
	scanf("%d",&T);
	while (T--) doit();
	return 0;
}