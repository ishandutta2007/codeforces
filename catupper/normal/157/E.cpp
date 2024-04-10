#include<stdio.h>
int table[2501][100];
int main(){
	int i,j,k;
	for(i=0;i<26;i++) table[i][0]=1;
	for(i=0;i<2501;i++){
		for(j=1;j<100;j++){
			for(k=0;k<26;k++){
				if(i-k>=0){
					table[i][j]+=table[i-k][j-1];
					table[i][j]%=1000000007;
				}
			}
		}
	}
	scanf("%d\n",&k);
	while(k--){
		int t=0,x,l=0;
		while((x=getchar())!='\n' && x!=-1)t+=x-97,l++;
		printf("%d\n",(table[t][l-1]+1000000006)%1000000007);		
	}
	return 0;
}            /*
a=input()

table=[[0 for x in range(100)]for y in range(2501)]

for x in range(26):
    table[x][0]=1

for x in range(2501):
    for y in range(1,100):
        table[x][y]=0
        for z in range(26):
            if(x-z)>=0:
                table[x][y]+=table[x-z][y-1]                   
        table[x][y]%=(10**9)+7

for x in range(a):    
    s=raw_input()
    l=len(s)
    s=sum(map(lambda x:ord(x)-97,s))
    
    print table[s][l-1]-1   
               */