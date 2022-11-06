#include<bits/stdc++.h>
using namespace std;
char a[200005],b[200005];
vector<pair<int,int>>v;
void work(){
    int n,i,j,t=0;
    scanf("%d",&n);
    scanf("%s%s",a+1,b+1);
    for(i=1;i<=n;++i){
        if(a[i]=='1'){
            ++t;
            b[i]='0'+'1'-b[i];
        }
    }
    t&=1;
    for(i=2;i<=n;++i)if(b[i]!=b[i-1]){
        puts("NO");
        return;
    }
    puts("YES");
    v.clear();
    for(i=1;i<=n;++i){
        if(a[i]=='1'){
            v.emplace_back(i,i);
        }
    }
    b[1]-='0';
    if(b[1]^t){
        v.emplace_back(1,1);
        v.emplace_back(2,2);
        v.emplace_back(1,2);
    }
    printf("%d\n",v.size());
    for(i=0;i<v.size();++i){
        printf("%d %d\n",v[i].first, v[i].second);
    }

}
int main(){
    int n;
    scanf("%d",&n);
    while(n--)work();
    return 0;
}