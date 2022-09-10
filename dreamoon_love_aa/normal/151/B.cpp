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
int d[6]={0,1,3,4,6,7};
int ma[3];
vector<string>an[3];
int main(){
    int i,j,k,n;
    cin>>n;
    while(n--){
        int m,tr[3]={};
        string name;
        cin>>m>>name;
        while(m--){
            string phone;
            cin>>phone;
            for(i=1;i<6;i++)
                if(phone[d[i]]!=phone[d[i-1]])break;
            if(i==6){
                tr[0]++;
                continue;
            }
            for(i=1;i<6;i++)
                if(phone[d[i]]>=phone[d[i-1]])break;
            if(i==6){
                tr[1]++;
                continue;
            }
            tr[2]++;
        }

        for(i=0;i<3;i++){
            if(tr[i]>ma[i]){
                an[i].clear();
                ma[i]=tr[i];
                an[i].pb(name);
            }
            else if(tr[i]==ma[i])an[i].pb(name);
        }
    }
    printf("If you want to call a taxi, you should call: ");
    for(i=0;i<an[0].size();i++){
        if(i)printf(", ");
        cout<<an[0][i];
    }
    puts(".");
    printf("If you want to order a pizza, you should call: ");
    for(i=0;i<an[1].size();i++){
        if(i)printf(", ");
        cout<<an[1][i];
    }
    puts(".");
    printf("If you want to go to a cafe with a wonderful girl, you should call: ");
    for(i=0;i<an[2].size();i++){
        if(i)printf(", ");
        cout<<an[2][i];
    }
    puts(".");
    return 0;
}