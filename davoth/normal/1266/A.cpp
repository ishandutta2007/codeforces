#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int N = 1e2 + 10;

int n;
int main(){
    fast_io;
    cin >> n;
    for(int i=0; i<n; i++){
        string x;
        cin >> x;
        int sum=0,even=0;
        bool c=false;
        for(char j : x){
            sum+=j-'0';
            if(j=='0') c=true;
            if((j-'0')%2==0) even++;
        }
        if(sum%3==0 && c && even>=2) cout << "red\n";
        else cout << "cyan\n";
    }
    return 0;
}