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
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,k,n;
    cin>>n>>k;
    pair<int,int>a[1111];
    for(i=1;i<=n;i++){
        int x;
        cin>>x;
        a[i]=make_pair(x,i);
    }
    sort(a+1,a+1+n);
    printf("%d\n",a[n-k+1].first);
    vector<int>res;
    for(i=n;i>n-k;i--){
        res.pb(a[i].second);
    }
    sort(res.begin(),res.end());
    for(i=0;i<res.size();i++){
        if(i)printf(" ");
        printf("%d",res[i]);
    }
    puts("");
    return 0;
}