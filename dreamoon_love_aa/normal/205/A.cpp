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
    int i,j,k,n,mi=1000000100;
    cin>>n;
    vector<int>r;
    for(i=0;i<n;i++){
        int x;
        cin>>x;
        if(x<mi){
            r.clear();
            r.pb(i);
            mi=x;
        }
        else if(x==mi)r.pb(i);
    }
    if(r.size()==1)printf("%d\n",r[0]+1);
    else puts("Still Rozdil");
    return 0;
}