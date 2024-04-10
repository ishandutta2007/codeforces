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
void error(){puts("Error occurred");}
bool dfs(int &now,vector<string>&mm){
    if(now>=d.size())return 0;
    if(d[now]==0)return 1;
    mm[now]+="<";
    now++;
    if(!dfs(now,mm))return 0;
    mm[now]+=",";
    now++;
    if(!dfs(now,mm))return 0;
    mm[now]+=">";
    return 1;    
}
int main(){
    int i,j,k,n;
    char s[100];
    scanf("%d",&n);
    while(scanf("%s",s)==1){
        if(s[0]=='i')d.pb(0);
        else d.pb(1);
    }
    if(n*2-1!=(int)d.size())error();
    else{
        vector<string>mm((int)d.size()+1);
        int now=0;
        if(!dfs(now,mm)||now!=d.size()-1)error();
        else{
            for(i=0;i<d.size();i++){
                if(d[i]==0)printf("int");
                else printf("pair");
                cout<<mm[i];
            }
            puts("");
        }
    }
    return 0;
}