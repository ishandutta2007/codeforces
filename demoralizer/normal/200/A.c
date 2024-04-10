#include <stdio.h>
int c[2001][2001];
int b[2001][2001];
int min(int a,int b){
	return a>b?b:a;
}
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	int n,m,k,x,y;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<k;i++){
		scanf("%d %d",&x,&y);
		if(c[x][y]==0){
            printf("%d %d\n",x,y);
            c[x][y]=1;
            continue;
		}
		for(int i=-1;i<=1;i++)
            for(int j=-1;j<=1;j++){
                int u=b[x+i][y+i]-max(i,-i)-max(j,-j);
                if(u>b[x][y])b[x][y]=u-1;
            }

		for(int d=b[x][y];;d++){
			for(int x2=max(1,x-d);x2<=min(x+d,n);x2++){
				int d2=d-max(x-x2,x2-x);
				if(y-d2>0&&(c[x2][y-d2]==0)){
					printf("%d %d\n",x2,y-d2);
					c[x2][y-d2]=1;
					b[x][y]=d?d:1;
					goto abc;
				}
				if((y+d2<m+1)&&(c[x2][y+d2]==0)){
					printf("%d %d\n",x2,y+d2);
					c[x2][y+d2]=1;
					b[x][y]=d?d:1;
					goto abc;
				}
			}
		}
		abc:;
	}
}