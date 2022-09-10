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
vector<int>d;
int main(){
    long long mi=1000000000000000ll,ma=0;
    int i,j,k,n;
    cin>>n;
    for(i=1;i*i<n;i++)
        if(n%i==0)d.pb(i),d.pb(n/i);
    if(i*i==n)d.pb(i);
    sort(d.begin(),d.end());
    for(i=0;i<d.size();i++)
        for(j=i;j<d.size();j++){
            if(n%((long long)d[i]*d[j])==0){
                long long x=n/(d[i]*d[j]);
                if(x<d[j])break;
                mi=min(mi,(x+2)*(d[j]+2)*(d[i]+1)-n);
                ma=max(ma,(x+1)*(d[j]+2)*(d[i]+2)-n);
            }
        }
    cout<<mi<<" "<<ma<<endl;
    return 0;
}