#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int T,n,i,j,k,c[26];

void out(int x,int c){while (c--) putchar('a'+x);}
void doit(){
	for(i=0;i<26;i++) if (c[i]==1){
		out(i,1);
		for(j=0;j<26;j++) if (i!=j) out(j,c[j]);
		return;
	}
	int s=0; while (!c[s]) s++;
	if (c[s]<=2) {for(i=0;i<26;i++) out(i,c[i]);return;}
	if (n-c[s]>=c[s]-2){
		j=s+1;
		out(s,2);
		for(i=3;i<=c[s];i++){
			while (!c[j]) j++;
			putchar('a'+j),c[j]--;
			out(s,1);
		}
		while (j<26){
			while (j<26&&!c[j]) j++;
			if (j<26) putchar('a'+j),c[j]--;
		}
		return;
	}
	int cnt=0;
	for(i=0;i<26;i++) cnt+=(c[i]>0);
	if (cnt==1){for(i=0;i<26;i++) out(i,c[i]);return;}
	if (cnt==2){
		for(i=0;i<26;i++) if (c[i])
			for(j=i+1;j<26;j++) if (c[j]){
				putchar('a'+i);
				out(j,c[j]);
				out(i,c[i]-1);
				return;
			}
	}
	for(i=0;i<26;i++) if (c[i])
		for(j=i+1;j<26;j++) if (c[j])
			for(k=j+1;k<26;k++) if (c[k]){
				putchar('a'+i);
				putchar('a'+j);
				out(i,c[i]-1);
				putchar('a'+k);
				out(j,c[j]-1);
				out(k,c[k]-1);
				for(k++;k<26;k++) out(k,c[k]);
				return;
			}
}

int main(){
	scanf("%d",&T);
	while (T--){
		char ch=getchar();
		while (ch<'a'||ch>'z') ch=getchar();
		memset(c,0,sizeof(c)),n=0;
		while (ch>='a'&&ch<='z') c[ch-'a']++,n++,ch=getchar();
		doit(),putchar('\n');
	}
}