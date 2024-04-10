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
vector<pair<int,int> >d;
int rr[100001];
int a[100001];
int main(){
    int i,j,k,n,m;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(i=0;i<n;i=j){
        for(j=i+1;j<n&&a[i]==a[j];j++);
        d.pb(make_pair(i,a[i]));
    }
    for(i=0;i<d.size();){
        if(i==d.size()-1){
            rr[d.back().first]=n-1;
            i++;    
        }
        else if(d[i].second>d[i+1].second){
            rr[d[i].first]=d[i+1].first-1;
            i++;
        }
        else{
            for(j=i+1;j<d.size();j++){
                if(j+1==d.size()||(d[j].second>d[j-1].second)!=(d[j+1].second>d[j].second))break;
            }
            for(k=j;k+1<(int)d.size();k++){
                if((d[k].second<d[k+1].second)==(d[i].second<d[i+1].second))break;
            }
            if(k==d.size()-1){
                for(;i<j;i++)rr[d[i].first]=n-1;
            }
            else{
                for(;i<j;i++)rr[d[i].first]=d[k+1].first-1;
            }
        }
    }
    for(i=1;i<n;i++){
        rr[i]=max(rr[i],rr[i-1]);
    }
    while(m--){
        int x,y;
        scanf("%d%d",&x,&y);
        x--;y--;
        if(y<=rr[x])puts("Yes");
        else puts("No");
    }
    return 0;
}