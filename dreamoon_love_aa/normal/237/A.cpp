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
int used[25][61];
int main(){
    int i,j,k,n,res=0;
    cin>>n;
    for(i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        used[x][y]++;
        res=max(res,used[x][y]);
    }
    cout<<res<<endl;
    return 0;
}