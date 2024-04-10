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
    int i,j,k,n,a,b,c,an=0,now;
    scanf("%d%d%d",&a,&b,&c);
    now=c;
    for(i=1;i<a+b;i++){
        an+=now;
        if(i<a&&i<b)now++;
        else if(i>=a&&i>=b)now--;
    }
    cout<<an<<endl;
    return 0;
}