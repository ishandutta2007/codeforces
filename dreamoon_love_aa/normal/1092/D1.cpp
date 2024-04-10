#include<cstdio>
int m;
int a[200000];
int main(){
    int n;
    scanf("%d",&n);
    int v1=0,v2=0;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(x&1){
            if(i&1)v1++;
            else v1--;
        }
        else{
            if(i&1)v2++;
            else v2--;
        }
    }
    puts((v1==0||v2==0)?"YES":"NO");
    return 0;
}