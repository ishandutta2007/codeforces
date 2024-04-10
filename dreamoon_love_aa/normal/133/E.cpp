#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
#define MOD 401
using namespace std;
char s[111];
int used[100000],cs;
int to(int x,int y,int z){
    return (x+1)*30000+y*201+z+100;
}
void get(int haha,int &x,int &y,int &z){
    x=(haha/30000)-1;
    haha%=30000;
    y=haha/201;
    haha%=201;
    haha-=100;
    z=haha;
}
vector<int>bfs[2];
int main(){
    int i,j,k,n,now,x,y,z,tmp,an=0;
    scanf("%s",s);
    scanf("%d",&n);
    bfs[1].pb(to(1,n,0));
    for(i=0;s[i];i++){
        now=i&1;
        cs++;
        bfs[now].clear();
        for(j=0;j<bfs[!now].size();j++){
            get(bfs[!now][j],x,y,z);
            if(s[i]=='T'){
                for(k=0;k<=y;k++){
                    if(k&1){
                        tmp=to(x,y-k,z+x);
                        if(used[tmp]==cs)continue;
                        used[tmp]=cs;
                        bfs[now].pb(tmp);
                    }
                    else{
                        tmp=to(-x,y-k,z);
                        if(used[tmp]==cs)continue;
                        used[tmp]=cs;
                        bfs[now].pb(tmp);
                    }
                }
            }
            else{
                for(k=0;k<=y;k++){
                    if(!(k&1)){
                        tmp=to(x,y-k,z+x);
                        if(used[tmp]==cs)continue;
                        used[tmp]=cs;
                        bfs[now].pb(tmp);
                    }
                    else{
                        tmp=to(-x,y-k,z);
                        if(used[tmp]==cs)continue;
                        used[tmp]=cs;
                        bfs[now].pb(tmp);
                    }
                }
            }
        }
    }
    for(i=0;i<bfs[now].size();i++){
        get(bfs[now][i],x,y,z);
        if(y==0)an=max(an,abs(z));
    }
    printf("%d\n",an);
    return 0;
}