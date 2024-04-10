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
    cin>>n;
    while(n--){
        int x=0;
        for(i=0;i<3;i++){
            cin>>k;
            x+=k;
        }
        an+=(x>1);
    }
    cout<<an<<endl;
    return 0;
}