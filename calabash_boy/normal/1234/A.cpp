#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
int main(){
    int q;
    cin>>q;
    while (q--){
        int sum = 0;
        int n;
        cin>>n;
        for (int i=0;i<n;i++){
            int x;
            cin>>x;
            sum += x;
        }
        cout<<(sum + n - 1) / n<<endl;
    }
    
    return 0;
}