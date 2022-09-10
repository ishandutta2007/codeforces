#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
char s1[10010],s2[1000010];
vector<int>p[26];
bool search(int x,int &nownow){
    int leftleft=0,rightright=p[x].size(),midmid;
    while(leftleft<rightright){
        midmid=(leftleft+rightright)>>1;
        if(p[x][midmid]<=nownow)leftleft=midmid+1;
        else rightright=midmid;
    }
    if(leftleft<(int)p[x].size()){
        nownow=p[x][leftleft];
        return 1;
    }
    return 0;
}
int main(){
    int i,an=1,nownow=-1;
    scanf("%s%s",s1,s2);
    for(i=0;i<26;i++)p[i].clear();
    for(i=0;s1[i];i++)
        p[s1[i]-'a'].push_back(i);
    for(i=0;s2[i];i++){
        if(p[s2[i]-'a'].size()==0)break;
        if(!search(s2[i]-'a',nownow)){
            an++;
            nownow=p[s2[i]-'a'][0];
        }
    }
    if(s2[i])puts("-1");
    else printf("%d\n",an);
    return 0;
}