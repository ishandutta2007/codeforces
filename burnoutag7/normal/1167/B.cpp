#include<bits/stdc++.h>
using namespace std;

int a[6]={4, 8, 15, 16, 23, 42};
int p[10];

bool fc(){
    for(int i=0;i<4;i++){
        if(a[i]*a[i+1]!=p[i+1])return false;
    }
    return true;
}

int main(){

    fflush(stdout);
    printf("? 1 2\n");
    fflush(stdout);
    scanf("%d",&p[1]);
    fflush(stdout);
    printf("? 2 3\n");
    fflush(stdout);
    scanf("%d",&p[2]);
    fflush(stdout);
    printf("? 3 4\n");
    fflush(stdout);
    scanf("%d",&p[3]);
    fflush(stdout);
    printf("? 4 5\n");
    fflush(stdout);
    scanf("%d",&p[4]);
    fflush(stdout);

    while(!fc()){
        next_permutation(a,a+6);
    }
    printf("! ");
    for(int i=0;i<6;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    fflush(stdout);

    return 0;
}