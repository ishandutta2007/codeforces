#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
int main(){
    int i,j,k,n;
    cin>>n;
    if(n<3){
        cout<<-1<<endl;
    }
    else if(n==3)cout<<210<<endl;
    else{
        k=1;
        for(i=1;i<n;i++){
            k*=10;
            k%=210;
        }
        k=210-k;
        printf("1");
        for(i=4;i<n;i++)printf("0");
        printf("%03d\n",k);
    }
    return 0;
}