#include<stdio.h>
#include<set>
using namespace std;
#define SIZE 10004
struct data{
    int w,x,y,z;
    bool operator<(data b)const{
        if(w<b.w)return 1;
        if(w>b.w)return 0;
        if(x<b.x)return 1;
        if(x>b.x)return 0;
        if(y<b.y)return 1;
        if(y>b.y)return 0;
        if(z<b.z)return 1;
        return 0;
    }
    data add(int s)const{
        if(s==0)return (data){w+1,x,y,z};
        if(s==1)return (data){w,x+1,y,z};
        if(s==2)return (data){w,x,y+1,z};
        if(s==3)return (data){w,x,y,z+1};
    }
    int get(int s)const{
        if(s==0)return w;
        if(s==1)return x;
        if(s==2)return y;
        if(s==3)return z;
    }
};
set<data>H[SIZE];
bool p[4];
main(){
    int n,tmp,d[4]={0,0,0,0},e[4],i,j;
    char s[SIZE];
    set<data>::iterator it;
    scanf("%d%s",&n,s);
    H[0].insert((data){0,0,0,0});
    for(i=0;i<n;i++){
        if(s[i]=='G')tmp=0;
        else if(s[i]=='H')tmp=1;
        else if(s[i]=='R')tmp=2;
        else if(s[i]=='S')tmp=3;
        else tmp=4;
        if(tmp<4){
            d[tmp]++;
            H[i+1]=H[i];
        }
        else{
            for(it=H[i].begin();it!=H[i].end();it++){
                for(j=0;j<4;j++)e[j]=d[j]+it->get(j);
                int small=100000;
                for(j=0;j<4;j++)
                    if(e[j]<small)
                        small=e[j];
                for(j=0;j<4;j++)
                    if(e[j]==small)H[i+1].insert(it->add(j));
            }
        }
    }
    for(it=H[n].begin();it!=H[n].end();it++){
        for(i=0;i<4;i++)e[i]=d[i]+it->get(i);
        int small=100000;
        for(j=0;j<4;j++)
            if(e[j]<small)
                small=e[j];
        for(j=0;j<4;j++)
            if(e[j]==small)p[j]=1;
    }
    if(p[0])puts("Gryffindor");
    if(p[1])puts("Hufflepuff");
    if(p[2])puts("Ravenclaw");
    if(p[3])puts("Slytherin");
}