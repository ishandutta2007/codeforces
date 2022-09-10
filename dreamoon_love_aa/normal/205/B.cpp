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
    int i,j,n;
    long long last=0;
    long long an=0,k=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(x+k<last){
            an+=last-x-k;
            k+=last-x-k;
        }
        else last=x+k;
    }
    cout<<an<<endl;
    return 0;
}