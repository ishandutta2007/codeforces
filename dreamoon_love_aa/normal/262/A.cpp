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
    int i,j,k,n,an=0;
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>j;
        int cnt=0;
        while(j){
            if(j%10==7||j%10==4)cnt++;
            j/=10;
        }
        if(cnt<=k)an++;
    }
    cout<<an<<endl;
    return 0;
}