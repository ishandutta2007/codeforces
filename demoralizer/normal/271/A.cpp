#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define MM 998244353
#define fr first
#define sc second
#define vc vector
#define pii pair<int,int>
#define msi map<string,int>
#define mii map<int,int>
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int y;
    cin>>y;
    y++;
    for(int i=y;;i++){
        int n=i;
        set<int> s;int c=0;
        while(n>0){
            c++;
            s.insert(n%10);
            n/=10;
        }
        if(s.size()==c){cout<<i;return 0;}
    }
}