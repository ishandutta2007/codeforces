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
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin >> n;
        if(n==1)printf("-1\n");
        else{
            for(int i=2;i<n;i++){
                printf("2");
            }
            if(2*(n-1)%3==0)printf("4");
            else printf("2");
            printf("3\n");
        }
    }
    return 0;
}