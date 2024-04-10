#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
int main(){
    string s;
    int n;
    cin>>n>>s;
    int cnt=0;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}