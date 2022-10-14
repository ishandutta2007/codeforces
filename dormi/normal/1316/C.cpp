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
    int n,m,p;
    cin>>n>>m>>p;
    int a;
    int ind=n;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a%p){
            ind=min(i,ind);
        }
    }
    int ind2=m;
    for(int i=0;i<m;i++){
        cin>>a;
        if(a%p){
            ind2=min(i,ind2);
        }
    }
    printf("%d\n",ind+ind2);
    return 0;
}