#include<cstdio>
#include<cstring>
using namespace std;
const int o=1<<21;
int T,n,sm;bool cut[o];char str[o];
int main(){
	for(scanf("%d",&T);T--;putchar('\n'),sm=0){
		scanf("%s",str+1);cut[n=strlen(str+1)]=1;
		for(int i=1;i<=n;++i) sm+=str[i]-48;
		if(!sm){printf("-1");continue;}
		for(int s=1,cnt,tar,v;1;s<<=1) if(s>=sm){
			cnt=1;v=0;tar=s-sm;
			for(int i=1;i<n;++i)
				if((v+=str[i]-48)&&tar>=v) tar-=v,cut[i]=0,v*=2;
				else cut[i]=1,v=0,++cnt;
			if(!tar){
				printf("%d\n",cnt);
				for(int i=1,l=1;i<=n;++i) if(cut[i]) printf("%d %d\n",l,i),l=i+1;
				break;
			}
		}
	}
	return 0;
}