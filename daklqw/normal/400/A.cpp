#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const char str[9][9]={"1x12","2x6","3x4","4x3","6x2","12x1"};
const int shit[9]={1,2,3,4,6,12};
char buf[18];
int n,tot,matrix[18][18];bool wwj[9];
int main(){ 
	scanf("%d",&n);
	while(n--){
		scanf("%s",buf+1);
		memset(wwj,0,sizeof wwj);
		tot=0;
		memset(matrix,0,sizeof matrix);
		for(int k=0;k<6;++k){
			bool can=false;
			for(int i=1;i<=shit[k];++i)
				for(int j=1;j<=12/shit[k];++j)
					matrix[i][j]=buf[(i-1)*(12/shit[k])+j]=='X';
			for(int i=1;i<=12/shit[k];++i){
				int cnt=0;
				for(int j=1;j<=shit[k];++j)cnt+=matrix[j][i];
				if(cnt==shit[k]){can=true;break;}
			}
			if(can)wwj[k]=true,++tot;
		}
		printf("%d ",tot);
		for(int i=0;i<6;++i)if(wwj[i])printf("%s ",str[i]);
		putchar(10);
	}
	return 0;
}