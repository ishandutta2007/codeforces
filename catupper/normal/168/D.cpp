#include<stdio.h>
double table[201][202][401];
int main(){
	int a,b,c,t[201],s[201];
	scanf("%d%d%d",&a,&b,&c);
	for(int i=0;i<a;i++)scanf("%d",t+i);
	for(int i=0;i<a;i++)scanf("%d",s+i);
	table[0][0][c+200]=1.0;//made,prises,bag
	for(int i=0;i<a;i++){
		int tt=t[i],ss=s[i];
		for(int j=0;j<=a;j++){
			for(int k=0;k<=400;k++){
				if(ss==-1){
					int xx=k-1,yy=j+1;
					if(yy>200)yy=200;
					if(xx<0)xx=0;
					table[i+1][yy][xx]+=table[i][j][k]*tt/100.0;//win
					table[i+1][j][k]+=table[i][j][k]*(100-tt)/100.0;//lose
				}
				else{
					int xx=k+ss,yy=j+1;
					if(yy>200)yy=200;
					if(xx>400)xx=400;
					table[i+1][yy][xx]+=table[i][j][k]*tt/100.0;//win
					table[i+1][j][k]+=table[i][j][k]*(100-tt)/100.0;//lose
				
				}
			}
		}
	}
	double res=0;
	for(int i=b;i<=a;i++){
		for(int j=200;j<=400;j++){
			res+=table[a][i][j];
		}
	}
	printf("%f\n",res);
}