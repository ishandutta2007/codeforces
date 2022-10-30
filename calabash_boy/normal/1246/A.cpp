#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,p;
    cin>>n>>p;
    for (int ans = 1;ans <= 60;ans ++){
        int temp = n - ans * p;
        if (temp> 0 and __builtin_popcount(temp) <= ans and ans <= temp ){

            cout<<ans<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}