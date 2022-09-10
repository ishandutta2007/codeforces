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
int a[100001],sum[2];
vector<int>team[2];
void print(int x){
    int i;
    printf("%d\n",team[x].size());
    for(i=0;i<team[x].size();i++){
        if(i)putchar(' ');
        printf("%d",team[x][i]);
    }
    puts("");
}
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i+1<=n;i+=2){
        if(a[i]<=a[i+1]){
            if(sum[0]>sum[1]){
                sum[1]+=a[i+1];
                team[1].pb(i+1);
                sum[0]+=a[i];
                team[0].pb(i);
            }
            else{
                sum[1]+=a[i];
                team[1].pb(i);
                sum[0]+=a[i+1];
                team[0].pb(i+1);
            }
        }
        else{
            if(sum[0]<sum[1]){
                sum[1]+=a[i+1];
                team[1].pb(i+1);
                sum[0]+=a[i];
                team[0].pb(i);
            }
            else{
                sum[1]+=a[i];
                team[1].pb(i);
                sum[0]+=a[i+1];
                team[0].pb(i+1);
            }
        }
    }
    if(n&1){
        if(sum[0]<=sum[1])team[0].pb(n);
        else team[1].pb(n);
    }
    print(0);
    print(1);
    return 0;
}