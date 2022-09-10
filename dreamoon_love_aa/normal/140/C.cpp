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
#define SIZE 100000
int r[SIZE],an[SIZE],ann;
set<pair<int,int> >H;
int main(){
    int i,j,k,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&r[i]);
    sort(r,r+n);
    for(i=0;i<n;i=j){
        for(j=i+1;j<n&&r[j]==r[i];j++);
        H.insert(make_pair(j-i,r[i]));
    }
    while(H.size()>=3){
        pair<int,int>tmp[3];
        set<pair<int,int> >::iterator it=H.end();
        it--;
        tmp[0]=*it;
        it--;
        tmp[1]=*it;
        it--;
        tmp[2]=*it;
        H.erase(it,H.end());
        for(i=0;i<3;i++){
            an[ann++]=tmp[i].second;
            tmp[i].first--;
            if(tmp[i].first)H.insert(tmp[i]);
        }
        sort(an+ann-3,an+ann);
        swap(an[ann-1],an[ann-3]);
    }
    printf("%d\n",ann/3);
    for(i=0;i<ann;i++){
        printf("%d",an[i]);
        if(i%3==2)puts("");
        else printf(" ");
    }
    return 0;
}