#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
#define SIZE 200002
pair<long long,long long>H[SIZE];
vector<pair<long long,long long> >an;
long long used[SIZE],n,yo,k;
struct Point{
    long long x,y,v;
    bool operator<(const Point& b)const{return v<b.v;}
}a[SIZE];
long long getNo(pair<long long,long long> x){
    int r=lower_bound(H,H+n,x)-H;
    if(r==n||H[r]!=x)return -1;
    return r;
}
bool tt(long long x,long long y){
    int i;
    int er=0;
    yo++;
    for(i=0;i<n&&er<=k;i++){
        if(used[i]==yo)continue;
        int tmp=getNo(make_pair((long long)x*2-H[i].first,(long long)y*2-H[i].second));
        if(tmp==-1)er++;
        else{
            used[tmp]=yo;
        }
    }
    return er<=k;
}
int main(){
    int i,j,er;
    scanf("%I64d%I64d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%I64d%I64d",&a[i].x,&a[i].y);
        a[i].x*=2;
        a[i].y*=2;
        a[i].v=a[i].x+a[i].y;
        H[i]=make_pair(a[i].x,a[i].y);
    }
    sort(a,a+n);
    sort(H,H+n);
    if(k>=n){
        puts("-1");
        return 0;
    }
    for(i=0;i<n&&i<=k;i++){
        er=i;
        for(j=n-1;j>=i&&((er+n-1-j)<=k||a[j].v==a[j+1].v);j--){
            if(tt((a[i].x+a[j].x)/2,(a[i].y+a[j].y)/2)){
                an.pb(make_pair((a[i].x+a[j].x)/2,(a[i].y+a[j].y)/2));
            }
        }
    }
    sort(an.begin(),an.end());
    int nn=unique(an.begin(),an.end())-an.begin();
    printf("%d\n",nn);
    for(i=0;i<nn;i++)
        printf("%.1lf %.1lf\n",an[i].first*0.5+1e-12,an[i].second*0.5+1e-12);
    return 0;
}