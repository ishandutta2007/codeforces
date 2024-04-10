#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;
struct data{
    int x,y,z;
    bool operator<(data b)const{
        return x>b.x||(x==b.x&&y>b.y)||(x==b.x&&y==b.y&&z>b.z);
    }
}a[500000];
map<int,int>H;
bool smaller(int x,int y){
    map<int,int>::iterator it;
    it=H.upper_bound(x);
    if(it==H.end())return 0;
    return y < it->second;
}
void add(int x,int y){
    if(H.empty()){
        H[x]=y;
        return;
    }
    map<int,int>::iterator it;
    it=H.lower_bound(x);
    if(it!=H.end()&&it->second>=y)return;
    do{
        it=H.upper_bound(x);
        if(it==H.begin())break;
        it--;
        if(it->second <= y)H.erase(it);
        else break;
    }while(1);
    H[x]=y;
}
main(){
    int n,i,j,an=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i].x);
    for(i=0;i<n;i++)
        scanf("%d",&a[i].y);
    for(i=0;i<n;i++)
        scanf("%d",&a[i].z);
    sort(a,a+n);
    for(i=0;i<n;i=j){
        for(j=i;j<n&&a[j].x==a[i].x;j++)
            if(smaller(a[j].y,a[j].z))an++;
        for(j=i;j<n&&a[j].x==a[i].x;j++)
            if(!smaller(a[j].y,a[j].z))add(a[j].y,a[j].z);
    }
    printf("%d\n",an);
}