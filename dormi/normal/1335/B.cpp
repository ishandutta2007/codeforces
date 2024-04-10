#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
char arr[2001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        for(int i=0;i<a-(b-1);i++){
            arr[i]='a';
        }
        char let='b';
        for(int i=a-(b-1);i<a;i++){
            arr[i]=let;
            let++;
        }
        for(int i=0;i<n;i++){
            printf("%c",arr[i%a]);
        }
        printf("\n");
    }
    return 0;
}