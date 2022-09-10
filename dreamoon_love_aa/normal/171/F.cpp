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
#define M 1000000
bool p[M];
int an[M],cnt;
int reverse(int x){
    int res=0;
    while(x){
        res*=10;
        res+=x%10;
        x/=10;
    }
    return res;
}
int main(){
    int i,j,k,n,aa;
    for(i=2;i*i<M;i++){
        if(!p[i])
            for(j=i+i;j<M;j+=i)p[j]=1;
    }
    for(i=2;i<M;i++){
        int tmp=reverse(i);
        if(i==tmp)continue;
        if(!p[i]&&!p[reverse(i)])an[++cnt]=i;
    }
    cin>>n;
    cout<<an[n]<<endl;
    return 0;
}