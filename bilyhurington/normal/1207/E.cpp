#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
int ans1,ans2;
const int pow7=128;
int main(){
    printf("?");
    for(int i=1;i<=100;i++){
        printf(" %d",i*pow7);
    }
    printf("\n");
    fflush(stdout);
    scanf("%d",&ans1);
    ans1%=pow7;
    printf("?");
    for(int i=1;i<=100;i++) printf(" %d",i);
    printf("\n");
    fflush(stdout);
    scanf("%d",&ans2);
    ans2/=pow7;
    printf("! %d",ans2*pow7+ans1);
}