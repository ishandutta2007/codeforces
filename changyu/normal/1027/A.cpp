#include<cstdio>
char a[101];int l;
int main(){
    int f;
    int T;scanf("%d",&T);for(;T--;){
    scanf("%d%s",&l,a);
    f=1;
    for(int i=0;i<(l>>1);i++)
      if(a[i]-a[l-1-i]!=2&&a[i]-a[l-1-i]!=0&&a[i]-a[l-1-i]!=-2){f=0;break;}
    puts(f?"YES":"NO");
	}return 0;
}