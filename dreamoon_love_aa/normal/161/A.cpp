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
vector<pair<int,int> >d1,d2,an;
int x,y;
inline bool valid(int a,int b){
    return a-x<=b&&b<=a+y;
}
int main(){
    int i,j,k,n,m;
    cin>>n>>m>>x>>y;
    for(i=0;i<n;i++){
        scanf("%d",&k);
        d1.pb(make_pair(k,i+1));
    }
    for(i=0;i<m;i++){
        scanf("%d",&k);
        d2.pb(make_pair(k,i+1));
    }
    sort(d1.begin(),d1.end());
    sort(d2.begin(),d2.end());
    for(i=j=0;i<d1.size();i++){
        while(j<m&&d2[j].first<d1[i].first-x)j++;
        if(j!=m&&valid(d1[i].first,d2[j].first)){
            an.pb(make_pair(d1[i].second,d2[j].second));
            j++;
        }
    }
    printf("%d\n",an.size());
    for(i=0;i<an.size();i++){
        printf("%d %d\n",an[i].first,an[i].second);
    }
    return 0;
}