#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int k;
    cin>>k;
    printf("%d %d\n",4,4);
    printf("%d ",(1<<18)-1);
    for(int i=0;i<3;i++)printf("0 ");
    printf("\n");
    printf("%d %d %d ",(1<<18)-1,(1<<17),(1<<17));
    for(int i=0;i<1;i++)printf("0 ");
    printf("\n");
    printf("%d %d %d ",k,0,(1<<17));
    for(int i=0;i<1;i++)printf("0 ");
    printf("\n");
    printf("%d %d %d %d\n",k,k,(1<<18)-1,k);
    return 0;
}