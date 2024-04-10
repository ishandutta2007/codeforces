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
    cin>>n;
    for(i=0;i<n;i++){
        cin>>j>>k;
        int res=0;
        while(j&&k){
            if(j<k){
                res+=k/j;
                k%=j;
            }
            else{
                res+=j/k;
                j%=k;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}