#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct data{
    char s[24];
    int score;
    bool operator<(data b)const{return score>b.score||(score==b.score&&strcmp(s,b.s)<0);}
    void scan(){scanf("%s%d",s,&score);}
}a[100000],tmp;
int d[100000];
main(){
    char M[24];
    int n,m,i,j,p,left,right,an;
    scanf("%d",&n);
    for(i=0;i<n;i++)a[i].scan();
    scanf("%d",&m);
    for(i=0;i<m;i++)scanf("%d",&d[i]);
    sort(d,d+n);
    scanf("%s",M);
    for(i=0;i<n;i++)
        if(strcmp(a[i].s,M)==0)break;
    a[i].score+=d[n-1];
    sort(a,a+n);
    for(i=0;strcmp(a[i].s,M);i++);
    p=i;
    left=p+1;
    right=n-1;
    an=p+1;
    for(i=n-2-p;i>=0;i--){
        tmp=a[right];
        tmp.score+=d[i];
        if(a[p]<tmp)right--;
        else{
            left++;
            an++;
        }
    }
    printf("%d ",an);
    a[p].score+=d[0]-d[n-1];
    sort(a,a+n);
    for(i=0;strcmp(a[i].s,M);i++);
    p=i;
    left=p+1;
    right=n-1;
    an=p+1;
    for(i=p+1;i<n;i++){
        tmp=a[left];
        tmp.score+=d[i];
        if(tmp<a[p]){
            an++;
            left++;
        }
        else right--;
    }
    printf("%d\n",an);
}