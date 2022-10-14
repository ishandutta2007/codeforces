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
    int a;
    cin>>a;
    for(int i=2;i*i<=a;i++){
        while(a%i==0){
            printf("%d",i);
            a/=i;
        }
    }
    if(a!=1)printf("%d",a);
    return 0;
}