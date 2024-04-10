#include<stdio.h>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
#define SIZE 100001
set<int>hash;
void dfs(long long x){
    if(x>=1000000000)return;
    if(x)hash.insert((int)x);
    dfs(x*10+4);
    dfs(x*10+7);
}
struct data{
    int x,No;
    bool operator<(data b)const{return x<b.x||(x==b.x&&No<b.No);}
    void print(){printf("%d %d\n",x,No);}
}a[SIZE];
int p[SIZE],d[SIZE],b[SIZE];
vector<data>an;
int main(){
    dfs(0);
    int n,hell,i,x,y;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i].x);
        b[i]=a[i].x;
        a[i].No=i;
    }
    for(i=1;i<n;i++)
        if(b[i]>b[i+1])break;
    if(i==n){
        puts("0");
        return 0;
    }
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)
        if(hash.count(a[i].x))break;
    if(i>n){
        puts("-1");
    }
    else{
        hell=a[i].No;
        for(i=1;i<=n;i++)p[i]=i;
        for(i=1;i<=n;i++)d[i]=i;
        for(i=1;i<=n;i++){
            if(a[i].No==hell)continue;
            if(p[a[i].No]==i)continue;
            if(p[hell]==i){
                an.push_back((data){i,p[a[i].No]});
                x=p[hell],y=p[a[i].No];
                swap(p[hell],p[a[i].No]);
                swap(d[x],d[y]);
            }
            else{
                an.push_back((data){i,p[hell]});
                x=p[hell];
                swap(p[hell],p[d[i]]);
                swap(d[x],d[i]);
                an.push_back((data){i,p[a[i].No]});
                x=p[hell],y=p[a[i].No];
                swap(p[a[i].No],p[hell]);
                swap(d[x],d[y]);
            }
        }
        printf("%d\n",an.size());
        for(i=0;i<an.size();i++)an[i].print();
    }
    return 0;
}