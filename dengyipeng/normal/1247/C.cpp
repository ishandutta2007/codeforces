#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int n,p,i,j,k;

int check(int cnt){
	if (cnt==4){
		printf("");
	}
	int m=n-p*cnt,sum=0;
	for(int x=m;x;x/=2) if (x&1) 
		sum++;
	if (sum>cnt||cnt>m) return 0;
	return 1;
}

int main(){
//	freopen("ceshi.in","r",stdin);
	scanf("%d%d",&n,&p);
	int tp=0;
	for(i=1;i<=30;i++) if (check(i))
		{tp=1,printf("%d",i);break;}
	if (!tp) printf("-1");
}