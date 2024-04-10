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
    int n;
    cin>>n;
    int mut=1;
    while(n>3){
        int rem=(n+1)/2;
        for(int i=0;i<rem;i++)printf("%d ",mut);
        mut*=2;
        n/=2;
    }
    if(n==3)printf("%d %d %d\n",mut,mut,mut*3);
    else if(n==2)printf("%d %d\n",mut,mut*2);
    else printf("%d\n",mut);
    return 0;
}