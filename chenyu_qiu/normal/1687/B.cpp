#include <bits/stdc++.h>
using namespace std;
const int o=2222;
struct node{
    int id,val;
}a[o];
char p[o];
bool cmp(node x,node y){return x.val<y.val;}
int ques(char ch[]){
    printf("? %s\n",ch+1);
    fflush(stdout);
    int x;
    scanf("%d",&x);
    return x;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)p[i]='0';
    for(int i=1;i<=m;i++){
        p[i]='1';
        a[i].val=ques(p);
        a[i].id=i;
        p[i]='0';
    }
    sort(a+1,a+m+1,cmp);
    int ans=0;
    for(int i=1,x=0,last=0;i<=m;i++){
        p[a[i].id]='1';
        x=ques(p);
        if(x==last+a[i].val)ans+=a[i].val,last=x;
        else p[a[i].id]='0';
    }
    cout<<"! "<<ans<<endl;
    return 0;
}