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
#define SIZE 100001
int a[SIZE],pos[SIZE],neg[SIZE],pos_num,neg_num,pp_n;
bool pp[SIZE];
int main(){
    int i,j,k,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]>0){
            pos[a[i]]++;
            pos_num++;
        }
        else{
            neg[-a[i]]++;
            neg_num++;
        }
    }
    for(i=1;i<=n;i++){
        int tmp=pos[i]+neg_num-neg[i];
        if(tmp==m){
            pp_n++;
            pp[i]=1;
        }
    }
    for(i=1;i<=n;i++){
        if(a[i]>0){
            if(pp[a[i]]){
                if(pp_n==1)puts("Truth");
                else puts("Not defined");
            }
            else puts("Lie");
        }
        else{
            if(!pp[-a[i]]){
                puts("Truth");
            }
            else{
                if(pp_n==1)puts("Lie");
                else puts("Not defined");
            }
        }
    }
    return 0;
}