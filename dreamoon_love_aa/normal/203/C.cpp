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
    int i,j,k,n,d,a,b;
    scanf("%d%d",&n,&d);
    scanf("%d%d",&a,&b);
    vector<pair<int,int> >ha;
    for(i=1;i<=n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        ha.pb(make_pair(a*x+b*y,i));
    }
    sort(ha.begin(),ha.end());
    int now=0;
    vector<int>an;
    for(i=0;i<ha.size();i++){
        if(d-now>=ha[i].first){
            now+=ha[i].first;
            an.pb(ha[i].second);
        }
        else break;
    }
    printf("%d\n",(int)an.size());
    for(i=0;i<an.size();i++){
        if(i)printf(" ");
        printf("%d",an[i]);
    }
    puts("");
    return 0;
}