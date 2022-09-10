#include<cstdio>
int main(){
    int n,one=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(x==1)one=1;
    }
    puts(one?"-1":"1");
    return 0;
}