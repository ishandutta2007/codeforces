#include <cstdio>
using namespace std;
char str[10001];
void input(char end,int &len){
	len=0;
	do{
		char in=getchar();
		if(in==end)return;
		str[len]=in;
		len++;
	}while(true);
}
int main(){
	int psize,len,ans=0,nowl=0,suml=0,spc=0;
	bool startsen=true,begin=true;
	scanf("%d\n",&psize);
	input('\n',len);
	for(int k=0;k<len;k++)
	if(str[k]=='!'||str[k]=='?'||str[k]=='.'){
		nowl++;
		if(nowl>psize){
			printf("Impossible");
			return 0;
		}
		if(begin){
			begin=false;
			ans++;
			suml=nowl;
		}else{
			if(suml+nowl+spc>psize){
				suml=nowl;
				ans++;
			}else{
				suml+=nowl+spc;
			}
		}
		startsen=true;
		nowl=spc=0;
	}else{
		if(startsen&&str[k]==' '){
			spc++;
			continue;
		}
		nowl++;
	 	startsen=false;
	}
	printf("%d\n",ans);
	return 0;
}