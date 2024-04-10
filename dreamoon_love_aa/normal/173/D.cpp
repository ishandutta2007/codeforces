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
#define SIZE 100001
bool used[SIZE];
int an[SIZE],bank[SIZE],n,m;
vector<int>e[SIZE],bb[2];
void dfs(int x,int ty){
    used[x]=1;
    bank[x]=ty;
    bb[ty].pb(x);
    for(int i=0;i<e[x].size();i++){
        if(!used[e[x][i]])dfs(e[x][i],ty^1);
    }
}
void print(){
    for(int i=0;i<n;i++){
        if(i)printf(" ");
        printf("%d",an[i]);
    }
    puts("");
}
vector<int>to[SIZE];
bool tr[SIZE];
void go2(int x,vector<int>&one,vector<int>&two){
    sort(e[x].begin(),e[x].end());
    int i,j;
    vector<int>res;
    for(i=j=0;res.size()<2;i++,j++){
        if(i==e[x].size()||e[x][i]!=two[j]){
            res.pb(two[j]);
            i--;
        }
    }
    tr[x]=1;
    tr[res[0]]=1;
    tr[res[1]]=1;
    an[x]=1;
    an[res[0]]=1;
    an[res[1]]=1;
    puts("YES");
    int No=2,cnt=0;
    for(i=0;i<one.size();i++){
        if(tr[one[i]])continue;
        an[one[i]]=No;
        cnt++;
        if(cnt==3){
            cnt=0;
            No++;
        }
    }
    for(i=0;i<two.size();i++){
        if(tr[two[i]])continue;
        an[two[i]]=No;
        cnt++;
        if(cnt==3){
            cnt=0;
            No++;
        }
    }
    print();
}
void go(vector<int>&one,vector<int>&two){
    sort(two.begin(),two.end());
    int i,j;
    for(i=0;i<one.size();i++){
        if(e[one[i]].size()<(int)two.size()-1){
            go2(one[i],one,two);
            return;
        }
        else if(e[one[i]].size()==(int)two.size()-1){
            int x=one[i];
            sort(e[x].begin(),e[x].end());
            for(j=0;j<e[x].size();j++)
                if(e[x][j]!=two[j])break;
            to[two[j]].pb(x);
        }
    }
    vector<int>final;
    for(i=0;i<n&&final.size()<2;i++)
        if(to[i].size()>1)final.pb(i);
    if(final.size()<2)puts("NO");
    else{
        puts("YES");
        for(i=0;i<2;i++){
            tr[final[i]]=1;
            an[final[i]]=i+1;
            for(j=0;j<2;j++){
                int y=to[final[i]][j];
                an[y]=i+1;
                tr[y]=1;
            }
        }
        int No=3,cnt=0;
        for(i=0;i<one.size();i++){
            if(tr[one[i]])continue;
            an[one[i]]=No;
            cnt++;
            if(cnt==3){
                cnt=0;
                No++;
            }
        }
        for(i=0;i<two.size();i++){
            if(tr[two[i]])continue;
            an[two[i]]=No;
            cnt++;
            if(cnt==3){
                cnt=0;
                No++;
            }
        }
        print();
    }
}
int main(){
    int i,j,k;
    scanf("%d%d",&n,&m);
    while(m--){
        int x,y;
        scanf("%d%d",&x,&y);
        x--,y--;
        e[x].pb(y);
        e[y].pb(x);
    }
    for(i=0;i<n;i++)
        if(!used[i])dfs(i,0);
    if(bb[0].size()%3==0){
        puts("YES");
        int No=1;
        for(i=0;i<bb[0].size();i+=3){
            an[bb[0][i]]=No;
            an[bb[0][i+1]]=No;
            an[bb[0][i+2]]=No;
            No++;
        }
        for(i=0;i<bb[1].size();i+=3){
            an[bb[1][i]]=No;
            an[bb[1][i+1]]=No;
            an[bb[1][i+2]]=No;
            No++;
        }
        print();
    }
    else{
        if(bb[0].size()%3==1)go(bb[0],bb[1]);
        else go(bb[1],bb[0]);
    }
    return 0;
}