#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define SIZE 100010
char s[SIZE];
bool used[26];
struct data{
    int x,y;
    bool operator<(data b)const{
        return y<b.y||(y==b.y&&x<b.x);
    }
}a[26];
main(){
    int n,i,k,o,sum=0;
    scanf("%s",s);
    n=strlen(s);
    for(i=0;i<26;i++)a[i].x=i;
    for(i=0;i<n;i++){
        a[s[i]-'a'].y++;
    }
    scanf("%d",&k);
    sort(a,a+26);
    for(i=0;i<26&&a[i].y==0;i++);
    o=i;
    for(;i<26;i++){
        if(a[i].y+sum<=k){
            sum+=a[i].y;
            used[a[i].x]=1;
        }
        else break;
    }
    printf("%d\n",26-i);
    for(i=0;i<n;i++){
        if(!used[s[i]-'a'])putchar(s[i]);
    }
    puts("");
}