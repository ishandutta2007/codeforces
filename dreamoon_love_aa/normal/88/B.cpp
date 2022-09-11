#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
#define SIZE 40
char s[SIZE][SIZE];
struct data{
    int x,y;
};
int used[26];
char input[500010];
int sqr(int x){return x*x;}
main(){
    vector<data>S;
    int n,m,x,tmp,i,j,k,an=0;
    for(i=0;i<26;i++)used[i]=-1;
    scanf("%d%d%d",&n,&m,&x);
    for(i=0;i<n;i++)scanf("%s",s[i]);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(s[i][j]=='S')S.push_back((data){i,j});
    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            if(s[i][j]!='S'){
                tmp=s[i][j]-'a';
                for(k=0;k<S.size();k++){
                    if(sqr(S[k].x-i)+sqr(S[k].y-j)<=x*x){
                        used[tmp]=1;
                        break;
                    }
                }
                used[tmp]=max(used[tmp],0);
            }
        }
    scanf("%d",&n);
    scanf("%s",input);
    for(i=0;i<n;i++){
        if(input[i]>='A'&&input[i]<='Z'){
            if(S.size()==0)break;
            if(used[input[i]-'A']<0)break;
            an+=1-used[input[i]-'A'];
        }
        else{
            if(used[input[i]-'a']<0)break;
        }
    }
    if(i<n)puts("-1");
    else printf("%d\n",an);
}