#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

ll minx=(ll)2000000000,maxx=(ll)-2000000000;
int T; char ch[10],YN[10]; ll num;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",ch+1);
		scanf("%I64d",&num);
		scanf("%s",YN+1);
		int l=strlen(ch+1);
		if (l==1){
			if (ch[1]=='<'){
				if (YN[1]=='Y') minx=min(minx,num-1);
				else maxx=max(maxx,num);
			}else{
				if (YN[1]=='Y') maxx=max(maxx,num+1);
				else minx=min(minx,num);
			}
		}else{
			if (ch[1]=='<'){
				if (YN[1]=='Y') minx=min(minx,num);
				else maxx=max(maxx,num+1);
			}else{
				if (YN[1]=='Y') maxx=max(maxx,num);
				else minx=min(minx,num-1);
			}
		}
	}
	if (minx<maxx) printf("Impossible\n");
	else printf("%I64d\n",maxx);
	return 0;
}