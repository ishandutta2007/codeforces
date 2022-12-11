#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3e5+50;
const double eps=1e-12;
int n,k,T;
void solve(){
    scanf("%d%d",&n,&k);
    bool fl=0;
    for(int i=1,x;i<=n;i++)
        scanf("%d",&x),fl|=x;
    puts(fl?"Yes":"No");
}
int main(){
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}