#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>pos,neg;
int zero;
main(){
    int n,x,i,first=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        if(!x)zero++;
        else if(x>0)pos.push_back(x);
        else neg.push_back(x);
    }
    for(i=0;i<pos.size();i++){
        if(first)putchar(' ');
        else first=1;
        printf("%d",pos[i]);
    }
    if(neg.size()>1){
        sort(neg.begin(),neg.end());
        int k;
        if(neg.size()%2==0)k=neg.size();
        else k=neg.size()-1;
        for(i=0;i<k;i++){
            if(first)putchar(' ');
            else first=1;
            printf("%d",neg[i]);
        }
    }
    if(first==0){
        if(zero>0)putchar('0');
        else printf("%d",neg[0]);
    }
    puts("");
}