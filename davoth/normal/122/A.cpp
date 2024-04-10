#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
int main(){
    int l[]={4,7,47,74,77,44,777,444,744,747,774,474,447,477};
    int n;
    cin>>n;
    for(int i=0;i<14;i++){
        if(n%l[i]==0){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}