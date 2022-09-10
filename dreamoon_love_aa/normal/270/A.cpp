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
int tr[180];
int main(){
    int i,j,k,n;
    for(i=3;i<=1000;i++)
        if(180*(i-2)%i==0)tr[180*(i-2)/i]=1;
    cin>>n;
    while(n--){
        cin>>k;
        if(tr[k])puts("YES");
        else puts("NO");
    }
    return 0;
}