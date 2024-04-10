#include<stdio.h>
#include<string.h>
char s[200001];
int cz[200001];
void Solve(){
	scanf("\n%s",s);
	int i,j=0,l=strlen(s),ans=0;
	for(i=0;i<l;i++){
		if(s[i]=='1'){
			cz[i]=j;
			j=0;
		}else{
			j++;
		}
	}
	for(i=0;i<l;i++){
		if(s[i]=='1'){
			int t=1;
			for(j=i;j<l&&t<=l&&t<2+cz[i]+j-i;j++){
				ans++;
				t<<=1;
				if(s[j+1]=='1'){
					t|=1;
				}
			}
		}
	}
	printf("%d\n",ans);
	for(i=0;i<l;i++){
		s[i]=cz[i]=0;
	}
}
int main(){
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		Solve();
	}
	return 0;
}