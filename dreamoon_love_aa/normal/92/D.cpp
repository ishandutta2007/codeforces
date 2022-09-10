#include<stdio.h>
#include<vector>
using namespace std;
int a[100010],an[100010];
vector<int>d,p;
int search(int x){
    int left=0,right=d.size(),mid;
    while(left<right){
        mid=(left+right)/2;
        if(d[mid]<x)right=mid;
        else left=mid+1;
    }
    if(left==d.size())return -1;
    return p[left];
}
main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    an[n-1]=-1;
    d.push_back(a[n-1]);
    p.push_back(n-1);
    for(i=n-2;i>=0;i--){
        an[i]=search(a[i])-i-1;
        if(an[i]<0)an[i]=-1;
        if(a[i]<d[d.size()-1]){
            d.push_back(a[i]);
            p.push_back(i);
        }
    }
    for(i=0;i<n;i++){
        if(i)putchar(' ');
        printf("%d",an[i]);
    }
    puts("");
}