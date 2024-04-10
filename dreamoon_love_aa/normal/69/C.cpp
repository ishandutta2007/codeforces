#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<map>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
struct Name{
    char s[108];
}name[100];
map<string,int>H;
struct data{
    int x,y;
};
vector<data>Map[100];
struct Person{
    int d[100];
}a[108];
struct Answer{
    int x,v;
    bool operator<(Answer b)const{return strcmp(name[x].s,name[b.x].s)<0;}
};
vector<Answer>an;
bool is_alpha(char c){return c>='a'&&c<='z';}
bool is_digit(char c){return c>='0'&&c<='9';}
void process(int x,char s[]){
    int i,j,y;
    for(i=0;s[i]!=':';i++);
    s[i]=0;
    strcpy(name[x].s,s);
    H[name[x].s]=x;
    for(i++;s[i];){
        while(s[i]==' '||s[i]==',')i++;
        for(j=i;is_alpha(s[j]);j++);
        s[j]=0;
        y=H[s+i];
        j++;
        Map[x].push_back((data){y,atoi(s+j)});
        for(i=j;is_digit(s[i]);i++);
    }
}
main(){
    char s[8000];
    int k,m,n,q,i,j,x;
    scanf("%d%d%d%d",&k,&n,&m,&q);
    for(i=0;i<n;i++){
        scanf("%s",name[i].s);
        H[name[i].s]=i;
    }
    gets(s);
    for(i=0;i<m;i++){
        gets(s);
        process(n+i,s);
    }
    for(i=1;i<=k;i++)
        for(j=0;j<n+m;j++)a[i].d[j]=0;
    while(q--){
        scanf("%d%s",&x,s);
        a[x].d[H[s]]++;
        while(1){
            for(i=n;i<n+m;i++){
                for(j=0;j<Map[i].size();j++)
                    if(a[x].d[Map[i][j].x]<Map[i][j].y)break;
                if(j==Map[i].size()){
                    a[x].d[i]++;
                    for(j=0;j<Map[i].size();j++)
                        a[x].d[Map[i][j].x]-=Map[i][j].y;
                    break;
                }
            }
            if(i==n+m)break;
        }
    }
    for(i=1;i<=k;i++){
        for(j=x=0;j<n+m;j++)
            if(a[i].d[j])x++;
        printf("%d\n",x);
        an.clear();
        for(j=0;j<n+m;j++){
            if(a[i].d[j])an.push_back((Answer){j,a[i].d[j]});
        }
        sort(an.begin(),an.end());
        for(j=0;j<an.size();j++)printf("%s %d\n",name[an[j].x].s,an[j].v);
    }
}