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
#define SIZE 100100
vector<int>e[SIZE];
int a[SIZE],pos[SIZE];
int main(){
    int i,j,k,n,m;
    cin>>n>>m>>k;
    k++;
    for(i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        e[x].pb(y);
        e[y].pb(x);
    }
    memset(pos,-1,sizeof(pos));
    a[0]=1;
    pos[1]=0;
    for(i=1;;i++){
        int x=a[i-1];
        for(j=0;j<e[x].size();j++){
            if(pos[e[x][j]]==-1){
                a[i]=e[x][j];
                pos[e[x][j]]=i;
                break;
            }
            else if(i-pos[e[x][j]]>=k){
                printf("%d\n",i-pos[e[x][j]]);
                for(int jj=pos[e[x][j]];jj<i;jj++){
                    if(jj!=pos[e[x][j]])printf(" ");
                    printf("%d",a[jj]);
                }
                puts("");
                return 0;
            }
        }
    }
    return 0;
}