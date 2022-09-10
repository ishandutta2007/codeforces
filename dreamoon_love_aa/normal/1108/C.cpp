#include<bits/stdc++.h>
using namespace std;
char c[5]="BGR";
char an[200005],s[200005];
int n;
int mi=2e5+5;
int main(){
    scanf("%d",&n);
    scanf("%s",s);
    do{
        int dif=0;
        for(int i=0;i<n;i++){
            dif+=(s[i]!=c[i%3]);
        }
        if(dif<mi){
            mi=dif;
            for(int i=0;i<n;i++)an[i]=c[i%3];
        }
    }while(next_permutation(c,c+3));
    printf("%d\n",mi);
    puts(an);
    return 0;
}