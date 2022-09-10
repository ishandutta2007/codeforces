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
    int i,x,n;
    cin>>n;
    cin>>x;
    for(i=1;i<=n;i++){
        int y,z;
        cin>>z>>y;
        if(x==y||x==7-y||x==z||x==7-z){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}