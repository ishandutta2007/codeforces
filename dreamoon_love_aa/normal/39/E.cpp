#include<stdio.h>
#include<map>
using namespace std;
struct data{
    int x,y;
    bool operator<(data b)const{return x<b.x||(x==b.x&&y<b.y);}
};
map<data,int>H;
long long pow(long long x,int y){
    long long an=1;
    while(y){
        if(y&1)an*=x;
        x*=x;
        y>>=1;
    }
    return an;
}
int dfs(int a,int b,int n){
    int tmp;
    if(H.count((data){a,b}))return H[(data){a,b}];
    if(pow(a,b)>=n)
        return 1;
    if(a==1){
        if(pow(a+1,b)>=n){
            H[(data){a,b}]=0;
            return 0;
        }
        if(dfs(a,b+1,n)<0){
            H[(data){a,b}]=1;
            return 1;
        }
        tmp=-dfs(a+1,b,n);
        H[(data){a,b}]=tmp;
        return tmp;
    }
    if(b==1){
        if(pow(a,2)>=n){
            if((n-a)&1)return -1;
            else return 1;
        }
    }
    if(dfs(a+1,b,n)<0||dfs(a,b+1,n)<0){
        H[(data){a,b}]=1;
        return 1;
    }
    H[(data){a,b}]=-1;
    return -1;
}
main(){
    int a,n,b,an;
    scanf("%d%d%d",&a,&b,&n);
    an=dfs(a,b,n);
    if(!an)puts("Missing");
    else if(an<0)puts("Stas");
    else puts("Masha");
}