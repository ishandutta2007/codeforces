#include <stdio.h>
#include <string.h>
#define maxn 4010
int f[maxn][maxn];
char s[maxn],t[maxn];
int sp[26][maxn],tp[26][maxn];
int ti,td,tr,te;
int n,m;
int min(int x,int y){return x<y?x:y;}
int main(){
	int i,j,k;
	scanf("%d %d %d %d",&ti,&td,&tr,&te);
	scanf("%s %s",s,t);
	n=strlen(s);
	m=strlen(t);
	for (j=0;j<26;j++){
		k=-1;
		for (i=0;i<n;i++){
			sp[j][i]=k;
			if (s[i]-'a'==j) k=i;
		}
	}
	for (j=0;j<26;j++){
		k=-1;
		for (i=0;i<m;i++){
			tp[j][i]=k;
			if (t[i]-'a'==j) k=i;
		}
	}
	for (i=0;i<=n;i++)
		for (j=0;j<=m;j++){
			if (i==0){
				f[i][j]=j*ti;
			}else
			if (j==0){
				f[i][j]=i*td;
			}else{
				f[i][j]=min(f[i-1][j]+td,f[i][j-1]+ti);
				f[i][j]=min(f[i][j],f[i-1][j-1]+tr*(s[i-1]!=t[j-1]));
				int cs,ct;
				if ((cs=sp[t[j-1]-'a'][i-1])>-1 && (ct=tp[s[i-1]-'a'][j-1])>-1){
					f[i][j]=min(f[i][j],f[cs][ct]+te+td*(i-2-cs)+ti*(j-2-ct));
				}
			}
		}
	printf("%d\n",f[n][m]);
	return 0;
}