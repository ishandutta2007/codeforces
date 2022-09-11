#include<stdio.h>
#include<algorithm>
using namespace std;
main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t,k,n,m;
    scanf("%d%d",&t,&k);
    while(t--){
        scanf("%d%d",&n,&m);
        if(n>m)swap(n,m);
        if(n%(k+1)==0)puts("+");
        else{
            if(k!=1){
                if((n/(k+1))&1)
                    puts(((m-n)&1)?"-":"+");
                else 
                    puts(((m-n)&1)?"+":"-");
            }
            else{
                puts(((m-n)&1)?"+":"-");
            }
        }
    }
}