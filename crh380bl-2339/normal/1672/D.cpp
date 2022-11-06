#include<bits/stdc++.h>
using namespace std;
struct node{
    int val,num;
    int nxt2;
}a[200005];
int b[200005];
map<int,int>M;
int main(){
    int n,t,i,s,j,s1,s2,m,x;
    cin>>t;
    while(t--){
        cin>>n;
        m=0;
        M.clear();
        for(i=0;i<=n;++i)a[i].val=a[i].num=a[i].nxt2=0;
        for(i=1;i<=n;++i){
            scanf("%d",&x);
            if(a[m].val==x){
                a[m].num++;
            }
            else{
                ++m;
                a[m].val=x;
                a[m].num=1;
                if(M[x])a[M[x]].nxt2=m;
                M[x]=m;
                
            }
        }
        for(i=1;i<=n;++i)scanf("%d",&b[i]);
        bool flg=1;
        for(i=j=1;i<=n;){
            if(a[j].val==b[i]){
                --a[j].num;
                if(a[j].num==0)++j;
                ++i;
                continue;
            }
            else{
                if(!a[j].nxt2){
                    puts("NO");
                    flg=0;
                    break;
                }
                a[a[j].nxt2].num+=a[j].num;
                a[j].num=0;
                ++j;
            }
        }
        if(flg)puts("YES");
    }
    return 0;
}