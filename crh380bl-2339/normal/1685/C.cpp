#include<bits/stdc++.h>
using namespace std;
#define N 400005
char s[N];
int n,ans;
int Ans[N][2];
void printans(){
    printf("%d\n",ans);
    for(int i=1;i<=ans;++i)printf("%d %d\n",Ans[i][0],Ans[i][1]);
}
bool chk0(){
    int i,num=0;
    for(i=1;i<=n;++i){
        if(s[i]=='(')++num;
        else --num;
        if(num<0)return false;
    }
    return true;
}
bool chk1(){
    int i,num=0,id1=0,id2=n+1,maxval1=0,maxval2=0;
    for(i=1;i<=n;++i){
        if(s[i]=='(')++num;
        else --num;
        if(num>maxval1){
            maxval1=num;
            id1=i;
        }
        if(num<0){
            break;
        }
    }
    num=0;
    for(i=n;i>=1;--i){
        if(s[i]==')')++num;
        else --num;
        //printf("<%d,%d,%c>\n",i,num,s[i]);
        if(num>maxval2){
            maxval2=num;
            id2=i;
        }
        if(num<0){
            break;
        }
    }
    ++id1;--id2;
    //printf("%d %d\n",id1,id2);
    num=0;
    for(i=1;i<id1;++i){
        if(s[i]=='(')++num;
        else --num;
        if(num<0)return false;
    }
    for(i=id2;i>=id1;--i){
        if(s[i]=='(')++num;
        else --num;
        if(num<0)return false;        
    }
    for(i=id2+1;i<=n;++i){
        if(s[i]=='(')++num;
        else --num;
        if(num<0)return false;
    }
    ans=1;
    Ans[1][0]=id1;
    Ans[1][1]=id2;
    return true;

}
void work(){
    ans=0;
    scanf("%d%s",&n,s+1);
    n<<=1;
    if(chk0()){
        puts("0");
        return;
    }
    if(chk1()){
        printans();
        return;
    }
    int num=0,maxval=0,id=0;
    for(int i=1;i<=n;++i){
        if(s[i]=='(')++num;
        else --num;
        if(num>maxval){
            id=i;
            maxval = num;
        }
    }
    if(1<id){
        ++ans;
        Ans[ans][0]=1;
        Ans[ans][1]=id;
    }
    if(id+1<n){
        ++ans;
        Ans[ans][0]=id+1;
        Ans[ans][1]=n;
    }
    printans();
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}