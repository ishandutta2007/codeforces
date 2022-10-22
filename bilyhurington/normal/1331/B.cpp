#include<bits/stdc++.h>
using namespace std;
int main(){
    int x;
    scanf("%d",&x);
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            printf("%d%d",i,x/i);
            return 0;
        }
    }
}