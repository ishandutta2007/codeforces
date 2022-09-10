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
bool p[SIZE],have[SIZE];
vector<int>fac[SIZE];
int H[SIZE];
int main(){
    int i,j,k,n,m;
    scanf("%d%d",&n,&m);
    for(i=2;i<SIZE;i++)
        if(!p[i]){
            fac[i].pb(i);
            for(j=i+i;j<SIZE;j+=i){
                p[j]=1;
                fac[j].pb(i);
            }
        }
    while(m--){
        char c[4];
        int x;
        scanf("%s%d",c,&x);
        if(c[0]=='+'){
            if(have[x])puts("Already on");
            else{
                for(i=0;i<fac[x].size();i++){
                    if(H[fac[x][i]]){
                        printf("Conflict with %d\n",H[fac[x][i]]);
                        break;
                    }
                }
                if(i==fac[x].size()){
                    printf("Success\n");
                    for(i=0;i<fac[x].size();i++)H[fac[x][i]]=x;
                    have[x]=1;
                }
            }
        }
        else{
            if(!have[x])puts("Already off");
            else{
                puts("Success");
                have[x]=0;
                for(i=0;i<fac[x].size();i++)H[fac[x][i]]=0;
            }
        }
    }
    return 0;
}