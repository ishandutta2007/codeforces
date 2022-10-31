#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    scanf("%d",&n);
    int flag = n%4;
    if (flag==0){
        printf("0\n");
        printf("%d ",n/2);
        n/=2;
        for (int i=2;i<=n;i+=2){
            printf("%d ",i);
        }
        for (int i=n+1;i<=n*2;i+=2){
            printf("%d ",i);
        }
    }else if (flag ==1){
        printf("1\n");
        printf("%d ",(n-1)/2);
        n=(n-1)/2;
        for (int i=2;i<=n;i+=2){
            printf("%d ",i+1);
        }
        for (int i=n+1;i<=n*2;i+=2){
            printf("%d ",i+1);
        }
    }else if (flag ==2){
        printf("1\n");
        printf("%d 1 ",(n-2)/2+1);
        n= (n-2)/2;
        for (int i=2;i<=n;i+=2){
            printf("%d ",i+2);
        }
        for (int i=n+1;i<=n*2;i+=2){
            printf("%d ",i+2);
        }
    }else {
        printf("0\n");
        printf("%d 3 ",(n-3)/2+1);
        n= (n-3)/2;
        for (int i=2;i<=n;i+=2){
            printf("%d ",i+3);
        }
        for (int i=n+1;i<=n*2;i+=2){
            printf("%d ",i+3);
        }
    }
    cout<<endl;
    return 0;
}