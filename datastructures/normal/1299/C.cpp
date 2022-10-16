#include <iostream>
#include <cstdio>
using namespace std;
double a[1000005],ans[1000005];
int n,nxt[1000005];
struct node{
    int l,r;
    double val;
}t[1000005];
int top;
int main(){
    cin>>n;
    for (int i=1;i<=n;i++)scanf("%lf",&a[i]);
    for (int i=n;i>=1;i--){
        node now;
        now.l=now.r=i;
        now.val=a[i];
        double sum=a[i];
        while(top>0){
            if (t[top].val>now.val)break;
            sum+=(t[top].r-t[top].l+1)*t[top].val;
            now.r=t[top].r;
            now.val=sum/(now.r-now.l+1);
            top--;
        }
        ans[i]=now.val;
        nxt[i]=now.r;
        t[++top]=now;
    }
    for (int i=1;i<=n;i++){
        int j;
        for (j=i;j<=nxt[i];j++)ans[j]=ans[i];
        i=nxt[i];
    }
    for (int i=1;i<=n;i++)printf("%.9f\n",ans[i]);cout<<endl;
    return 0;
}