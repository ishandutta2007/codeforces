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
    vector<int>d;
    for(i=0;i<4;i++){
        int x;
        cin>>x;
        d.pb(x);
    }
    sort(d.begin(),d.end());
    printf("%d\n",4-(unique(d.begin(),d.end())-d.begin()));
    return 0;
}