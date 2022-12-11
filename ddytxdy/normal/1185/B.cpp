#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
int n,lc,ld,le,lf,nume[N],numf[N];char c[N],d[N],e[N],f[N];bool flag;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%s%s",c+1,d+1);flag=1;le=lf=0;
		lc=strlen(c+1);ld=strlen(d+1);
		for(int i=1;i<=lc;i++){
			if(i==1||c[i]!=c[i-1])e[++le]=c[i],nume[le]=0;
			nume[le]++;
		}
		for(int i=1;i<=ld;i++){
			if(i==1||d[i]!=d[i-1])f[++lf]=d[i],numf[lf]=0;
			numf[lf]++;
		}
		if(le!=lf){puts("NO");continue;}
		for(int i=1;i<=le;i++){
			if(nume[i]>numf[i]||e[i]!=f[i])flag=0;
		}
		if(!flag)puts("NO");
		else puts("YES");
	}
}