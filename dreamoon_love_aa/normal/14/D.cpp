#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 210
vector<int>Map[SIZE];
int an;
int Q(int x,int last,int &tmp){
    int i,s=0,r;
    vector<int>d;
    d.clear();
    for(i=0;i<Map[x].size();i++){
        if(Map[x][i]==last)continue;
        r=Q(Map[x][i],x,tmp);
        if(r>s)s=r;
        d.push_back(tmp);
    }
    sort(d.begin(),d.end());
    if(d.size()==0)tmp=0;
    else if(d.size()==1){
        tmp=d[0]+1;
        if(s<tmp)s=tmp;
    }
    else{
        tmp=(d[d.size()-1]+1)+(d[d.size()-2]+1);
        if(s<tmp)s=tmp;
        tmp=d[d.size()-1]+1;
    }
    return s;
}
void Go(int x,int y){
    int r;
    int tmp=Q(x,y,r)*Q(y,x,r);
    if(tmp>an)an=tmp;
}
main(){
    int n,x,y,m,i,j;
    scanf("%d",&n);
    m=n-1;
    while(m--){
        scanf("%d%d",&x,&y);
        Map[x].push_back(y);
        Map[y].push_back(x);
    }
    for(i=1;i<=n;i++)
        for(j=0;j<Map[i].size();j++)
            Go(i,Map[i][j]);
    printf("%d\n",an);
}