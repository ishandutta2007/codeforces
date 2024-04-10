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
    int i,j,k=0,n;
    cin>>n;
    int last=1;
    vector<int>an;
    for(i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x<0){
            k++;
            if(k==3){
                an.pb(i-last);
                last=i;
                k=1;
            }
        }
    }
        an.pb(n+1-last);
        printf("%d\n",(int)an.size());
        for(i=0;i<an.size();i++){
            if(i)printf(" ");
            printf("%d",an[i]);
        }
    return 0;
}