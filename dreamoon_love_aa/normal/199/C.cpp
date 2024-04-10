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
    long long i,j,k,b,n,t;
    cin>>k>>b>>n>>t;
    if(t==1)cout<<n<<endl;
    else{
        i=1;
        j=0;
        while(i<=t){
            j++;
            i=i*k+b;
        }
        cout<<max(0ll,n-j+1)<<endl;
        
    }
    return 0;
}