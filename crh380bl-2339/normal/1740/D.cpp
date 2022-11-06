#include<bits/stdc++.h>
using namespace std;
int a[200005];
set<int>S;
void work(){
    S.clear();
    int n,m,k,i;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=k;++i)scanf("%d",&a[i]);
    int nw = k;
    i = 1;
    while(nw){
        if(S.find(nw)!=S.end()){
            S.erase(nw);
            --nw;
        }
        else{
            if(i>k){
                puts("TIDAK");
                return;
            }
            else{
                if(a[i]==nw){
                    ++i;
                    --nw;
                    continue;
                }
                S.insert(a[i]);
                ++i;
                if(S.size()>1LL*(n*m-4)){
                    puts("TIDAK");
                    return;
                }
            }
        }
    }
    puts("YA");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}