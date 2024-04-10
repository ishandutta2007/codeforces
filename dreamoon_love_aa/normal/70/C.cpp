#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct data{
    long long x,y;
    bool operator<(data b)const{return x*b.y>y*b.x||(x*b.y==y*b.x&&x<b.x);}
    bool operator==(data b)const{return x*b.y==y*b.x;}
}a[100000];
long long rev(long long x){
    long long an=0;
    while(x){
        an*=10;
        an+=x%10;
        x/=10;
    }
    return an;
}
vector<int>d[100001];
priority_queue<int>H;
main(){
    int i,j,k,kk,r,max_x,max_y,w,an1=-1,an2;
    scanf("%d%d%d",&max_x,&max_y,&w);
    for(i=1;i<=100000;i++)a[i-1]=(data){i,rev(i)};
    sort(a,a+100000);
    i=0,j=99999;
    while(i<=j){
        if(a[i].x*a[j].x==a[i].y*a[j].y){
            for(k=i+1;k<100000&&a[k]==a[i];k++);
            for(kk=j-1;kk>=0&&a[kk]==a[j];kk--);
            while(i<k){
                for(r=kk+1;r<=j;r++){
                    if(a[i].x<=max_x&&a[r].x<=max_y)d[a[i].x].push_back(a[r].x);
                    if(kk>k&&a[r].x<=max_x&&a[i].x<=max_y)d[a[r].x].push_back(a[i].x);
                }
                i++;
            }
            j=kk;
        }
        else if(a[i].x*a[j].x>a[i].y*a[j].y)i++;
        else j--;
    }
    for(i=1;i<=max_x;i++){
        for(j=0;j<d[i].size();j++)H.push(d[i][j]);
        while(H.size()>w){
            H.pop();
        }
        if(H.size()==w){
            if(an1==-1||an1*an2>i*H.top()){
                an1=i;
                an2=H.top();
            }
        }
    }
    if(an1!=-1)printf("%d %d\n",an1,an2);
    else puts("-1");
}